# You are given a string S.
# S contains alphanumeric characters only.

# Your task is to sort the string S in the following manner:
# All sorted lowercase letters are ahead of uppercase letters.
# All sorted uppercase letters are ahead of digits.
# All sorted odd digits are ahead of sorted even digits.

string = input()

lowercase = ''
uppercase = ''
odd = ''
even = ''

for letter in string:
    if(letter.isalpha()):
        if(letter.islower()):
            lowercase += letter
        elif(letter.isupper()):
            uppercase += letter
    elif(letter.isnumeric()):
        if(int(letter)%2):
            odd += letter
        elif(not int(letter)%2):
            even += letter
            
final_string = sorted(lowercase) + sorted(uppercase) + sorted(odd) + sorted(even)
final_string = ''.join(final_string)
print(final_string)
