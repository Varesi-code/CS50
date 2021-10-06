def get_max(dna, STR):

    # Iteration values. [0:5] if the word has 5 letters.
    i = 0
    j = len(STR)

    # Counter of max times it's repeated.
    maxim = 0

    for x in range(len(dna)):
        if dna[i:j] == STR:
            temp = 0
            # When a match is found start to count the consecutive matches until there's no match.
            while dna[i:j] == STR:
                temp += 1
                # Update the iteration values so they keep searching in the DNA file.
                i += len(STR)
                j += len(STR)
                # If 'temp' is bigger than the max times it's been repeated consecutively then it's the new max.
                if temp > maxim:
                    maxim = temp
        # If there's no match in that substring, update values to keep seaching.
        else:
            i += 1
            j += 1

    return maxim