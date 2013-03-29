def getalphavalue(name):
    """Returns the alphanumeric value of name."""
    sum = 0
    for c in name:
        if c == 'A':
            sum += 1
        elif c == 'B':
            sum += 2
        elif c == 'C':
            sum += 3
        elif c == 'D':
            sum += 4
        elif c == 'E':
            sum += 5
        elif c == 'F':
            sum += 6
        elif c == 'G':
            sum += 7
        elif c == 'H':
            sum += 8
        elif c == 'I':
            sum += 9
        elif c == 'J':
            sum += 10
        elif c == 'K':
            sum += 11
        elif c == 'L':
            sum += 12
        elif c == 'M':
            sum += 13
        elif c == 'N':
            sum += 14
        elif c == 'O':
            sum += 15
        elif c == 'P':
            sum += 16
        elif c == 'Q':
            sum += 17
        elif c == 'R':
            sum += 18
        elif c == 'S':
            sum += 19
        elif c == 'T':
            sum += 20
        elif c == 'U':
            sum += 21
        elif c == 'V':
            sum += 22
        elif c == 'W':
            sum += 23
        elif c == 'X':
            sum += 24
        elif c == 'Y':
            sum += 25
        elif c == 'Z':
            sum += 26
    return sum

def getsumnamescores(names):
    """Finds the sum of the scores of all of the elements of names. The score of each name is the alphanumeric value of the name multiplied by its alphabetical position in names."""

    names.sort()

    sum = 0
    for i in range(0, len(names)):
        sum += getalphavalue(names[i]) * (i + 1)

    return sum

if __name__ == "__main__":
    # Read the file
    with  open('names.txt', mode='r') as name_file:
        names = name_file.readlines()
    name_file.closed

    print(getsumnamescores(names))
