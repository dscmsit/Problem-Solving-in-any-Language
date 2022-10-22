# You are given a list of N lowercase English letters. For a given integer K, you can select any K indices (assume 1-based indexing) with a uniform probability from the list.

# Find the probability that at least one of the K indices selected will contain the letter: ''.

import math
n = int(input())
string = input()
k = int(input())

total_letters = n
letters_not_a = total_letters - string.count('a')

if letters_not_a >= k:

    total_combinations = math.factorial(total_letters)/(math.factorial(k) * math.factorial(total_letters-k))

    total_invalid_combinations = math.factorial(letters_not_a)/(math.factorial(k) * math.factorial(letters_not_a-k))

    total_valid_combinations = total_combinations - total_invalid_combinations

    probability = total_valid_combinations / total_combinations

    print(probability)
    
else:
    
    print(1)
