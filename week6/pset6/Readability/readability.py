from cs50 import get_string


def main():
    text = get_string("Text: ")
    Level(text)


def Level(text):
    # initializes the counters
    CountLetters = 0
    CountWords = 0
    CountSentences = 0

    # if it doesn't start with space, counts 1st word
    if text[0].isalpha():
        CountWords += 1
       # print(CountWords)

    for i in range(len(text)):
        if text[i].isalpha():
            CountLetters += 1

        # checks for words after " or space in all characters of the stirng
        elif text[i].isspace() or text[i] == " " and text[i + 1].isalpha:
            CountWords += 1

        # checks for punctuation marks to detect endof sentence
        elif text[i] == "." or text[i] == "!" or text[i] == "?":
            CountSentences += 1
    # print(CountWords, CountLetters, CountSentences)

    # initializes variables for the Coleman Liau Index
    L = float(CountLetters) / CountWords * 100
    S = float(CountSentences) / float(CountWords) * 100

    # calculate index value
    index = 0.0588 * L - 0.296 * S - 15.8

    # turns index value into a grade level
    if index < 1:
        print("Before Grade 1")
    elif index >= 16:
        print("Grade 16+")
    else:
        print("Grade " + str(round(index)))


if __name__ == "__main__":
    main()