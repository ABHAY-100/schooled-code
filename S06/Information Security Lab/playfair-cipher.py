def matrix(key):
    key = key.replace("J", "I")
    letters = []
    for c in key + "ABCDEFGHIKLMNOPQRSTUVWXYZ":
        if c not in letters and c.isalpha():
            letters.append(c)
    return [letters[i:i+5] for i in range(0, 25, 5)]

def pairs(text):
    text = text.replace("J", "I")
    i, res = 0, ""
    while i < len(text):
        a = text[i]
        b = text[i+1] if i+1 < len(text) else "X"
        if a == b:
            res += a + "X"
            i += 1
        else:
            res += a + b
            i += 2
    return res + ("X" if len(res) % 2 else "")

def pos(m, c):
    return next((i, j) for i in range(5) for j in range(5) if m[i][j] == c)

def cipher(text, m, step):
    return "".join(
        m[r][(c+step)%5] + m[r2][(c2+step)%5] if r == r2 else
        m[(r+step)%5][c] + m[(r2+step)%5][c2] if c == c2 else
        m[r][c2] + m[r2][c]
        for r, c, r2, c2 in
        ( (*pos(m, text[i]), *pos(m, text[i+1])) for i in range(0, len(text), 2) )
    )

text = input("Enter Text: ").upper().replace(" ", "")
key = "MONARCHY"

m = matrix(key)
prepared = pairs(text)

encrypted = cipher(prepared, m, 1)
decrypted = cipher(encrypted, m, -1)

print("\nEncrypted Text:", encrypted)
print("Decrypted Text:", decrypted)
