#include <cs50.h>
#include <math.h>
#include <stdio.h>
int evenSum(long creditNumber);
int productSum(int lastDigit);
int digitCounter(long creditNumber);
bool isValidA(long creditNumber, int num);
bool isValidM(long creditNumber, int num);
bool isValidV(long creditNumber, int num);

int main(void)
{
    long creditNumber = get_long("Enter your credit card number: ");
    int eSum = evenSum(creditNumber);
    int num = digitCounter(creditNumber);
    bool a = isValidA(creditNumber, num);
    bool m = isValidM(creditNumber, num);
    bool v = isValidV(creditNumber, num);
    if (eSum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }
    else if (a == true)
    {
        printf("AMEX\n");
    }
    else if (m == true)
    {
        printf("MASTERCARD\n");
    }
    else if (v == true)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
        return 0;
    }
}

bool isValidA(long creditNumber, int num)
{
    int digits = creditNumber / pow(10, 13);
    if ((num == 15) && (digits == 34 || digits == 37))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isValidV(long creditNumber, int num)
{
    if (num == 13)
    {
        int digits = creditNumber / pow(10, 12);
        if (digits == 4)
        {
            return true;
        }
    }
    else if (num == 16)
    {
        int digits = creditNumber / pow(10, 15);
        if (digits == 4)
        {
            return true;
        }
    }
    return false;
}

bool isValidM(long creditNumber, int num)
{
    int digits = creditNumber / pow(10, 14);
    if ((num == 16) && (digits > 50 && digits < 56))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int digitCounter(long creditNumber)
{
    int count = 0;
    while (creditNumber > 0)
    {
        count++;
        creditNumber = creditNumber / 10;
    }
    return count;
}

int evenSum(long creditNumber)
{
    int sum = 0;
    bool flag = false;
    while (creditNumber > 0)
    {
        if (flag == true)
        {
            int lastDigit = creditNumber % 10;
            int product = productSum(lastDigit);
            sum += product;
        }
        else
        {
            int lastDigit = creditNumber % 10;
            sum += lastDigit;
        }
        flag = !flag;
        creditNumber = creditNumber / 10;
    }
    return sum;
}

int productSum(int lastDigit)
{
    int multiply = lastDigit * 2;
    int sum = 0;
    while (multiply > 0)
    {
        int answer = multiply % 10;
        sum = sum + answer;
        multiply = multiply / 10;
    }
    return sum;
}
