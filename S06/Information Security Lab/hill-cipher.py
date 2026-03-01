MOD = 26

def c2n(c): return ord(c) - 65
def n2c(n): return chr(n + 65)

def inv(a):
    for i in range(26):
        if (a*i) % 26 == 1:
            return i

def mat_inv(k):
    d = (k[0][0]*k[1][1] - k[0][1]*k[1][0]) % 26
    i = inv(d)
    return [[ k[1][1]*i % 26, -k[0][1]*i % 26],
            [-k[1][0]*i % 26,  k[0][0]*i % 26]]

def hill(text, key):
    text = text.upper().replace(" ", "")
    if len(text) % 2: text += 'X'
    out = ""
    for i in range(0, len(text), 2):
        a, b = c2n(text[i]), c2n(text[i+1])
        out += n2c((key[0][0]*a + key[0][1]*b) % 26)
        out += n2c((key[1][0]*a + key[1][1]*b) % 26)
    return out

key = [[3,3],[2,5]]
msg = input("Enter word: ")

cipher = hill(msg, key)
plain  = hill(cipher, mat_inv(key))

print("Ciphertext:", cipher)
print("Decrypted :", plain)
