"""Write a function that takes a string of characters and returns a dictionary with each word in the string as the key and its length as the value. For example, if the function receives the string "Hello everyone" it should return {'Hello': 4, 'to': 1, 'everyone': 5}.
"""


def word_lengths(string):
    # Split the string into a list of words
    words = string.split()

    # Create the result dictionary with a dictionary comprehension
    result = {word: len(word) for word in words}

    return result
