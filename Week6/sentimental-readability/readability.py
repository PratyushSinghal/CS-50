text = input("Please enter the Text: ")

num_letters = 0
for characters in text:
    if characters.isalpha():
        num_letters += 1

num_words = len(text.split())
num_sentences = text.count(".") + text.count("!") + text.count("?")

l = (num_letters/num_words) * 100
s = (num_sentences/num_words) * 100

grade = 0.0588 * l - 0.296 * s - 15.8

if grade < 1:
    print("Before Grade 1")
elif grade >= 16:
    print("Grade 16+")
else:
    print(f"Grade {round(grade)}")
