def romanUnit(num):
    roman = ""
    if num < 4:
        for x in range(0, num):
            roman += "I"
    elif num == 4:
        roman += "IV"
    elif num == 5:
        roman += "V"
    elif num == 9:
        roman += "IX"
    else:
        roman += "V"
        for x in range(0, num - 5):
            roman += "I"
    return roman


def romanTens(num):
    roman = ""
    if num < 4:
        for x in range(0, num):
            roman += "X"
    elif num == 4:
        roman += "XL"
    elif num == 5:
        roman += "L"
    elif num == 9:
        roman += "XC"
    else:
        roman += "L"
        for x in range(0, num - 5):
            roman += "X"
    return roman


def romanHundreds(num):
    roman = ""
    if num < 4:
        for x in range(0, num):
            roman += "C"
    elif num == 4:
        roman += "CD"
    elif num == 5:
        roman += "D"
    elif num == 9:
        roman += "CM"
    else:
        roman += "D"
        for x in range(0, num - 5):
            roman += "C"
    return roman


def romanThousands(num):
    roman = ""
    for x in range(0, num):
        roman += "M"
    return roman


def intToRoman(num):
    if num != 0:
        numThousands = int(num/1000)
        numHundreds = int((num - numThousands*1000)/100)
        numTens = int((num - numThousands*1000 - numHundreds*100)/10)
        numUnit = int(num - numThousands*1000 - numHundreds*100 - numTens*10)
        return romanThousands(numThousands) + romanHundreds(numHundreds) + romanTens(numTens) + romanUnit(numUnit)
    else:
        return "Error"


def romanToInt(s):
    finalNumber = 0
    i = 0

    while i < len(s):
        if s[i] == 'I':
            if i+1 < len(s):
                if s[i+1] == 'V':
                    finalNumber += 4
                    i += 1
                elif (s[i+1] == 'X'):
                    finalNumber += 9
                    i += 1
                else:
                    finalNumber += 1
            else:
                finalNumber += 1

        elif s[i] == 'V':
            finalNumber += 5

        elif s[i] == 'X':
            if i+1 < len(s):
                if s[i+1] == 'L':
                    finalNumber += 40
                    i += 1
                elif s[i+1] == 'C':
                    finalNumber += 90
                    i += 1
                else:
                    finalNumber += 10
            else:
                finalNumber += 10

        elif s[i] == 'L':
            finalNumber += 50

        elif s[i] == 'C':
            if i+1 < len(s):
                if s[i+1] == 'D':
                    finalNumber += 400
                    i += 1
                elif s[i+1] == 'M':
                    finalNumber += 900
                    i += 1
                else:
                    finalNumber += 100
            else:
                finalNumber += 100

        elif s[i] == 'D':
            finalNumber += 500

        elif s[i] == 'M':
            finalNumber += 1000
        i += 1
    return finalNumber


useAgain = True
while useAgain:
    print("\n" + "What conversion do you want to make?" + "\n")
    print("1- Integer to Roman")
    print("2- Roman to Integer")
    print("3- Quit")

    option = int(input())

    if option == 1:
        print("\n" + "Enter your integer: ")
        integer = float(input())
        print(intToRoman(integer) + "\n")
    if option == 2:
        print("\n" + "Enter your roman: ")
        roman = str(input())
        print(str(romanToInt(roman)) + "\n")
    if option == 3:
        useAgain = False
