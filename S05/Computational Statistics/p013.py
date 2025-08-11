text = input("Enter a string: ")

vowels = "aeiouAEIOU"
vowel_count = sum(c in vowels for c in text)
consonant_count = sum(c.isalpha() and c not in vowels for c in text)
question_mark_count = text.count('?')
word_count = len(text.split())

print(f"Vowels: {vowel_count}")
print(f"Consonants: {consonant_count}")
print(f"Words: {word_count}")
print(f"Question marks: {question_mark_count}")
