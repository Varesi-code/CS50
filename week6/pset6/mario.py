from cs50 import get_int


def main():
    i = get_positive_int()
    printPyramid(i)

# Prompt user for positive integer between 1 and 8 inclusive


def get_positive_int():
    while True:
        n = get_int("Height: ")
        if n > 0 and n < 9:
            break
    return n

# print pyramid


def printPyramid(f):
    for k in range(0, f):
        for m in range(f - k - 1)[::-1]:
            print(" ", end="")
        for l in range(k + 1):
            print("#", end="")
        print()


if __name__ == "__main__":
    main()

""" ........#   8   1
    .......##   7   2
    ......###   6   3
    .....####   5   4
    ....#####   4   5
    ...######   3   6
    ..#######   2   7
    .########   1   8 """