inputVal = int(input("Enter a number:- "))

print(f"\nBin: {bin(inputVal)[2:]}")
print(f"Oct: {oct(inputVal)[2:]}")
print(f"Hex: {hex(inputVal)[2:].upper()}")