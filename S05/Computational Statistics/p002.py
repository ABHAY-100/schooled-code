inputVal = int(input("Enter a number:- "))

print("\nDivisors of ", inputVal, ":")

for i in range(1, inputVal + 1):
    if inputVal % i == 0:
        print(f"{i} is a divisor of {inputVal}")