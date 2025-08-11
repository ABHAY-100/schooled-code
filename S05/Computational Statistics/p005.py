def fibo(number) :
    if number == 0 :
        return 0
    elif number == 1 :
        return 1
    else :
        return (number - 1) + (number - 2)

inputVal = int(input("Enter a number:- "))
print(f"Fibo = {fibo(inputVal)}")