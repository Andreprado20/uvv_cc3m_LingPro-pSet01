## -------------------------------------------------- LUHN ALGORITHM IN PYTHON -------------------------------------------------------- ##
# The original algorithm have 3 steps:
# 1 - Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
# 2 - Add the sum to the sum of the digits that weren’t multiplied by 2.
# 3 - If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!


# Gets input from user as a string, eliminates all empty spaces and dashes from it and casts it into an integer --------------------------
cardNumberInput = input("Enter your Credit Card Number: ")
reduced = cardNumberInput.replace(" ", "").replace("-", "")
convertedCardNumber = int(reduced)

# Converts the card number into an array and then splits it into each digit of the number ------------------------------------------------
cardNumberArray = [convertedCardNumber]
cardNumberSplited = list(map(int, str(cardNumberArray[0])))

# Gets first two digits of card number to verifiy the card's Payment Network (Could be Visa, MasterCard or American Express) -------------
firstDigits = int(str(cardNumberSplited[0]) + str(cardNumberSplited[1]))


def cardBrandCheck(firstDigits):
    firstDigitsArray = [firstDigits]
    digitsSlices = list(map(int, str(firstDigitsArray[0])))
    digit1 = digitsSlices[0]
    if digit1 == 4:
        return "Visa"
    match firstDigits:
        case 34 | 37:
            return "American Express (AMEX)"
        case 51 | 52 | 53 | 54 | 55:
            return "Mastercard"


cardBrand = cardBrandCheck(firstDigits)

# Reverses the card number by reversing the order of the elements in the array containing the card number --------------------------------
cardNumberSplited.reverse()

# Applies the first step of the original Algorithm by separating the two parts of the original number (the digits starting by the second-to-last digit 
# and the rest of the digits) and storing each one into it's own array -------------------------------------------------------------------
index = len(cardNumberSplited)
arrayToDouble = []
for element in range(1, index, 2):
    arrayToDouble.append(cardNumberSplited[element])

arrayLeftAside = []
for element in range(0, index, 2):
    arrayLeftAside.append(cardNumberSplited[element])

# Takes the array that contains the second-to-last part, doubles each digit and stores the result into a new array -----------------------
def double(number):
    return number * 2
doubledArray = list(map(double, arrayToDouble))

# Looks for elements in the doubled array that have more than one digit and splits it in two separated digits ----------------------------
for element in doubledArray:
    if element >= 10:
        number = [element]
        result = list(map(int, str(number[0])))
        for elem in result:
            doubledArray.append(elem)
        doubledArray.remove(element)

# Applying the second step of the original algorithm -------------------------------------------------------------------------------------
sumDoubledArray = 0
for num in doubledArray:
    sumDoubledArray = sumDoubledArray + num

sumLeftArray = 0
for num in arrayLeftAside:
    sumLeftArray = sumLeftArray + num

finalSum = sumLeftArray + sumDoubledArray

# Splits the digits of the final resulting sum and gets the last digit -------------------------------------------------------------------
checkInput = [finalSum]
checkInputSliced = list(map(int, str(checkInput[0])))
checkLastDigit = checkInputSliced[len(checkInputSliced) - 1]

# Applies third step of the original algorithm verifying if the last digit of the sum is 0 (zero). 
# If it's different than zero or if it's lenght is not between 13 and 16, it returns the card is invalid. 
# If it's equal to zero it returns the card is valid and the Card's Brand/Payment Network
if checkLastDigit != 0 or len(cardNumberSplited) < 13 or len(cardNumberSplited) > 16:
    print("Invalid Card Number!!")
else:
    print(f"Valid {cardBrand} Credit Card!")

# END!!
