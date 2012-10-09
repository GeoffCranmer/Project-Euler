# for each digit in the number
from math import floor

def num_letters(n):
    if n == 0:
        return 0 
    elif n == 1:
        return 3 # one
    elif n == 2:
        return 3 # two
    elif n == 3:
        return 5 # three
    elif n == 4:
        return 4 # four
    elif n == 5:
        return 4 # five
    elif n == 6:
        return 3 # six
    elif n == 7:
        return 5 # seven
    elif n == 8:
        return 5 # eight
    elif n == 9:
        return 4 # nine
    elif n == 10:
        return 3 # ten
    elif n == 11:
        return 6 # eleven
    elif n == 12:
        return 6 # twelve
    elif n == 13:
        return 8 # thirteen
    elif n == 14:
        return 8 # fourteen
    elif n == 15:
        return 7 # fifteen
    elif n == 16:
        return 7 # sixteen
    elif n == 17:
        return 9 # seventeen
    elif n == 18:
        return 8 # eighteen
    elif n == 19:
        return 8 # nineteen
    elif n == 20:
        return 6 # twenty
    elif n == 30:
        return 6 # thirty
    elif n == 40:
        return 5 # forty
    elif n == 50:
        return 5 # fifty
    elif n == 60:
        return 5 # sixty
    elif n == 70:
        return 7 # seventy
    elif n == 80:
        return 6 # eighty
    elif n == 90:
        return 6 # ninety
    elif n == 1000:
        return 11 # one thousand
    elif n < 100:
        return num_letters(n - (n % 10)) + num_letters(n % 10)
    else:
        return num_letters(floor(n / 100)) + 10 + num_letters(n % 100)

if __name__ == "__main__":
    sum = 0
    for i in range(1, 1000):
        sum += num_letters(i)
    print(sum)
    
