from math import factorial

def facdigsum(n):
    """Returns the sum of the digits of the factorial of n."""

    facstr = str(factorial(n))

    sum = 0
    for x in facstr:
        sum += int(x)

    return sum

if __name__ == "__main__":
    print(facdigsum(100))
