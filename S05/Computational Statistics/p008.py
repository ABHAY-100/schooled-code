def is_prime(n):
    if n < 2:
        return False
    for i in range(2, int(n**0.5)+1):
        if n % i == 0:
            return False
    return True

def fibonacci_primes(limit):
    a, b = 0, 1
    while a <= limit:
        if is_prime(a):
            print(a)
        a, b = b, a + b

fibonacci_primes(1000)
