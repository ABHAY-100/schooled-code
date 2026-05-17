import math

p = int(input("Enter p: "))
q = int(input("Enter q: "))

n = p * q
phi = (p - 1) * (q - 1)

e = 2
while math.gcd(e, phi) != 1 :
    e+=1

d = pow(e, -1, phi)

print("\nPublic Key:")
print([e,n])

print("\nPrivate Key:")
print([d,n])

pt = input("\nEnter plain text: ")

encrypted = []

for ch in pt:
    c = pow(ord(ch), e, n)
    encrypted.append(c)

print("\nEncrypted Message:")
print(encrypted)

decrypted = ""

for c in encrypted:
    ch = chr(pow(c, d, n))
    decrypted += ch

print("\nDecrypted Message:")
print(decrypted)
