import string

def analyze_file(path):
    f = open(path, 'r', encoding='utf-8')
    text = f.read()
    f.close()
    
    words = len(text.split())
    sentences = sum(text.count(s) for s in '.!?')
    upper = sum(1 for c in text if c.isupper())
    lower = sum(1 for c in text if c.islower())
    special = sum(1 for c in text if c in string.punctuation)
    print(f"Words: {words}\nSentences: {sentences}\nUppercase: {upper}\nLowercase: {lower}\nSpecial Symbols: {special}")

analyze_file("index.txt")
