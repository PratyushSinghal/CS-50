from cs50 import get_int
import math


def isValidA(creditNumber, num):
    digits = math.trunc(creditNumber / pow(10, 13))
    if ((num == 15) and (digits == 34 or digits == 37)):
        return True
    else:
        return False


def isValidV(creditNumber, num):
    if (num == 13):
        digits = math.trunc(creditNumber / pow(10, 12))
        if (digits == 4):
            return True
    elif num == 16:
        digits = math.trunc(creditNumber / pow(10, 15))
        if (digits == 4):
            return True
    return False


def isValidM(creditNumber, num):
    digits = math.trunc(creditNumber / pow(10, 14))
    if ((num == 16) and (digits > 50 and digits < 56)):
        return True
    else:
        return False


def digitcounter(creditNumber):
    count = 0
    while (creditNumber > 0):
        count += 1
        creditNumber = math.trunc(creditNumber / 10)
    return count


def productSum(lastDigit):
    multiply = lastDigit * 2
    sum = 0
    while (multiply > 0):
        answer = multiply % 10
        sum = sum + answer
        multiply = math.trunc(multiply / 10)
    return sum


def evenSum(creditNumber):
    sum = 0
    flag = False
    while (creditNumber > 0):
        if (flag == True):
            lastDigit = creditNumber % 10
            product = productSum(lastDigit)
            sum += product
        else:
            lastDigit = creditNumber % 10
            sum += lastDigit
        flag = not (flag)
        creditNumber = math.trunc(creditNumber / 10)
    return sum


def main():
    creditNumber = get_int("Enter your credit card number: ")
    eSum = evenSum(creditNumber)
    num = digitcounter(creditNumber)
    a = isValidA(creditNumber, num)
    m = isValidM(creditNumber, num)
    v = isValidV(creditNumber, num)
    if (not (eSum % 10 == 0)):
        print("INVALID")
        return 0
    elif (a == True):
        print("AMEX")
    elif (m == True):
        print("MASTERCARD")
    elif (v == True):
        print("VISA")
    else:
        print("INVALID")
        return 0


main()
