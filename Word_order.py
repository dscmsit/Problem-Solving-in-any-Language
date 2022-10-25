# You are given n words. Some words may repeat. For each word, output its number of occurrences. The output order should correspond with the input order of appearance of the word. See the sample input/output for clarification.

n = int(input())
words = []
while(n>0):
    words.append(input())
    n -= 1
unique_words = {}
for word in words:
    if word not in unique_words:
        unique_words[word] = 1
    else:
        unique_words[word] += 1
        
print(len(unique_words))
for freq in unique_words.values():
    print(freq, end=" ")
        