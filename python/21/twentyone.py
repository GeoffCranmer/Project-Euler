import math

def sumpropdivs(n):
    """Finds the sum of all proper divisors of n."""

    sum = 0
    for i in range(2, math.trunc(math.sqrt(n))):
        if (n % i == 0):
            sum += i
            sum += int(n / i)
    return sum + 1

def sumamicablenums(limit):
    """Finds the sum of all amicable numbers less than limit."""

    sum = 0
    for i in range(1, limit):
        j = sumpropdivs(i)
        if (j > i and j < limit and sumpropdivs(j) == i):
            sum += i
            sum += j

    return sum

if __name__ == "__main__":
    print(sumamicablenums(10000))
