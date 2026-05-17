import math
import hashlib

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

msg = input("\nEnter message: ")

hash_value = int(hashlib.sha256(msg.encode()).hexdigest(), 16)

signature = pow(hash_value, d, n)

print("\nDigital Signature:")
print(signature)

verified_hash = pow(signature, e, n)

print("\nVerified Hash:")
print(verified_hash)

if verified_hash == hash_value % n:
    print("\nSignature Verified")
else:
    print("\nSignature Invalid")
