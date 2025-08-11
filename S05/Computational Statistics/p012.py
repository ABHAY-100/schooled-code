fruits = ("apple", "banana")

user_input = input("Enter a fruit name: ").lower()

if user_input in fruits:
    print(f"{user_input} is present")
else:
    print(f"{user_input} is not present")
