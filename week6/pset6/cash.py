from cs50 import get_float

# amount of coins ie times that ops turns true
coins = 0


def main():
    change = get_positive_float()
    calculateChange(change)
    print(coins)


def get_positive_float():
    while True:
        n = get_float("Change owed: ")
        if n > 0:
            n = n * 100
            break
    return n
# make sure change is positive number


def calculateChange(m):
    # declare local variables for each coin
    quarter = 25
    dime = 10
    nickel = 5
    pennie = 1
    global coins

    while m > 0:
        # check quarters
        if m >= quarter:
            m = m - quarter
        # check dimes
        elif m >= dime:
            m = m - dime
        # check nickels
        elif m >= nickel:
            m = m - nickel
        # check pennies
        elif m >= pennie:
            m = m - pennie
        coins += 1
    return coins


if __name__ == "__main__":
    main()