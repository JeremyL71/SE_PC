import sys

infile = open(sys.argv[1], "r")
lines = 0
words = 0
characters = 0
for line in infile:
    wordslist = line.split()
    lines = lines + 1
    words = words + len(wordslist)
    characters = characters + len(line)
infile.close()

print(f"lines: {lines}")
print(f"words: {words}")
print(f"characters: {characters}")


def get_dictionary_word_list():
    list_words = []
    infile = open(sys.argv[1], "r")
    # reading each line
    for line in infile:
        # reading each word
        for word in line.split():
            # displaying the words
            list_words.append(word)
    return list_words


def make_one_string(list_words: list, size: int):
    i = 0
    string = ""
    while i < size:
        string = string + " " + list_words[i]
        i = i + 1
    return string


string = make_one_string(get_dictionary_word_list(), 20)
print(f"20 premiers mots: {string}")
