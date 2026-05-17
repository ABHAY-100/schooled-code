import hashlib

s1 = input("Enter first string: ")
s2 = input("Enter second string: ")

h1 = hashlib.sha256(s1.encode()).hexdigest()
h2 = hashlib.sha256(s2.encode()).hexdigest()

h1_int = int(h1, 16)
h2_int = int(h2, 16)

xor_result = h1_int ^ h2_int

bit_difference = bin(xor_result).count('1')

print("Bit Difference:", bit_difference)
