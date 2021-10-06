import csv
import sys
import re

def main():

    # Ensure correct usage
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py data.csv sequence.txt")

    # Open txt and read its contents into memory
    with open(sys.argv[2]) as txtF:
        dna_in = txtF.read()

    # Open csv and read its contents into memory treating each as a dict
    with open(sys.argv[1]) as csvF:
        reader = csv.DictReader(csvF)
        dict_in =[]

        # Each line in reader is appended to the list
        for line in reader:
            dict_in.append(line)
        # print(dict_in)

    # Compute the longest run of consecutive repeats and compare
    calculate_rep(STR, seq)

        # if the str count matches exactly with any indiv
        if:
            # Print name of ind
        print( )
        # Else
        else:
            # Print "No match"
            print("No match")

# Compute the longest run of consecutive repeats (function)
def calculate_rep(STR, seq):
    # guru99.com/python-regular-expressions-complete-tutorial.html#7
    repetitions = re.findall(f"(?:{seq})+", STR)
    if repetitions:
        # 1. max() with iterable arguments @ programiz.com
        longest_rep = max(repetitions, key=len)
        return int(len(longest_rep) / len(seq))
    else:
        return 0

if __name__ == "__main__":
    main()
