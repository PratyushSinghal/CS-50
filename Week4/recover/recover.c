#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        return 1;
    }
    FILE *f = fopen(argv[1], "r");
    uint8_t buffer[512];
    bool found = false;
    int counter = 0;
    char file_name[8];
    FILE *image = NULL;
    while (fread(buffer, 1, 512, f))
    {
        if ((buffer[0] == 0xff) && (buffer[1] == 0xd8) && (buffer[2] == 0xff) &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            found = true;
        }
        if (found == true)
        {
            if (counter == 0)
            {
                sprintf(file_name, "%03i.jpg", counter);
                image = fopen(file_name, "w");
                fwrite(buffer, 1, 512, image);
                found = false;
                counter++;
            }
            else
            {
                fclose(image);
                sprintf(file_name, "%03i.jpg", counter);
                image = fopen(file_name, "w");
                fwrite(buffer, 1, 512, image);
                found = false;
                counter++;
            }
        }
        else if (counter != 0)
        {
            fwrite(buffer, 1, 512, image);
        }
    }
    fclose(f);
    fclose(image);
}
