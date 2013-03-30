from datetime import date
from datetime import timedelta

def numfirstsundays(begin, end):
    current = begin
    week = timedelta(7)

    count = 0
    while (current < end):
        if (current.day == 1):
            count += 1
        current = current + week
        
    return count

if __name__ == "__main__":
    num = numfirstsundays(date(1901, 1, 1), date(2000, 12, 31))
    print ("Found " + str(num) + " Sundays.")
