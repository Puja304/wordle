'''
Wordle:
1. Computer selects a random 5 letter english word. Get the list for that online
2. The user guess the whole world. The user cannot guess a word bigger than or smaller than 5 letters, and cannot guess the same word again
3. if the word user guesses is not the same word that the computer generated, they lose 1 life per valid attempt. See point 2 for invalid attemtpts
4. Print the user input in a way where if a letter from ther input matches the word position for position, it will be capital, if it is there but at a different place, it will be lowercase,
and if it does not exist in the word, it will appear as a dash
5. If the words match or lives become 0, the game ends

attempt 1:

def display_word(secret_word, guessed_word):
    displayed_word = ""
    count = 0
    for subletters in guessed_word:
        for letters in secret_word:
            if subletters == letters and secret_word.find(subletters) == guessed_word.find(subletters):
                displayed_word += subletters.upper()
            elif subletters == letters and secret_word.find(subletters) != guessed_word.find(subletters):
                displayed_word += subletters.lower()
            else:
                count += 1
        if count == 5:
            displayed_word += "-"
        count = 0
    return displayed_word


attempt 2:

def display_word(secret_word, guessed_word):
    global displayed_word
    displayed_word = ""
    count = 0
    for subindexes in range(len(guessed_word)):  #issue   #2   #is
        for indexes in range(len(secret_word)):   #times  #4
            if secret_word[indexes] == guessed_word[subindexes] and indexes == subindexes:
                displayed_word += guessed_word[subindexes].upper()
                break
            elif secret_word[indexes] == guessed_word[subindexes] and indexes != subindexes:
                if guessed_word[subindexes] in secret_word and subindexes > indexes:
                    pass
                elif len([secret_word[indexes] for char in displayed_word]) == sum(char == secret_word[indexes] for char in secret_word):
                    pass
                else: 
                    displayed_word += guessed_word[subindexes].lower()
                    break
            else:
                count += 1
        if count == 5 or len(displayed_word) <= subindexes:
            displayed_word += "-"
        count = 0
    return displayed_word
'''

import random
from wordle_words import word_list
secret_word = random.choice(word_list).upper()


def wordle(secret_word):
    lives = 5
    tries = 1
    guessed_word = ""
    list_of_guesses = []
    print("Welcome to Wordle! \nThe goal of the game is to guess a five-letter english word. To start playing, enter a five letter word when prompted.\nRules: \n1. You have 5 tries\n2. A blank space means the letter is not in the word\n3. A lowercase letter indicates that the letter is in the word but not in the correct position]\n4. An uppercase letter means it is in the correct position\nEnjoy!")
    while lives > 0:
        guessed_word = input("Enter a 5 letter word: ").upper()
        if len(guessed_word) != 5 or guessed_word in list_of_guesses:
            print("Invalid input")
        else:
            list_of_guesses.append(guessed_word)
            if guessed_word == secret_word:
                print(f"Congratulations! {secret_word} is the right answer! It took you {tries} tries(y))")
                break
            else:
                lives -= 1
                tries += 1
                progress = display_word(secret_word, guessed_word)
                print(progress)
    if lives == 0:
        print(f"Youe died. The word was {secret_word}")
    

def display_word(secret_word, guessed_word):
    default_list = ["-" for i in range(5)]
    for subindex in range(len(guessed_word)):
        if guessed_word[subindex] in secret_word:       #ISSUE TIMES
            if guessed_word[subindex] == secret_word[subindex]:
                default_list[subindex] = guessed_word[subindex].upper()
            elif guessed_word[subindex] != secret_word[subindex]:
                default_list[subindex] = guessed_word[subindex].lower()
                if n_occurences(default_list, guessed_word[subindex].lower()) > n_occurences(secret_word,guessed_word[subindex]):
                    default_list[subindex] = "-"
    for char in secret_word:
        if n_occurences(default_list, char.lower()) + n_occurences(default_list, char.upper()) > n_occurences(secret_word, char):
            iterations_to_do = n_occurences(default_list, char.lower()) - (n_occurences(secret_word, char)-n_occurences(default_list, char.upper()))
            for i in range(iterations_to_do):
                default_list[default_list.index(char.lower())] = "-"
    stringed_version = "".join(str(e) for e in default_list)
    return stringed_version

def n_occurences(any_word, a_letter):
    counter = 0
    for letter in any_word:
        if letter == a_letter:
            counter += 1
    return counter


wordle(secret_word)