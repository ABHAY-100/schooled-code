def vigenere(text, key, enc=True):
    text = text.upper().replace(" ", "")
    key  = key.upper()
    out = ""

    for i, c in enumerate(text):
        t = ord(c) - 65
        k = ord(key[i % len(key)]) - 65
        out += chr((t + k if enc else t - k) % 26 + 65)

    return out

msg = input("Enter word: ")
key = input("Enter key : ")

cipher = vigenere(msg, key, True)
plain  = vigenere(cipher, key, False)

print("Ciphertext:", cipher)
print("Decrypted :", plain)
