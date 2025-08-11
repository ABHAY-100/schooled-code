import numpy as np

def fibonacci_binet(n):
    sqrt_5 = np.sqrt(5)
    phi = (1 + sqrt_5) / 2
    psi = (1 - sqrt_5) / 2

    indices = np.arange(n)
    fib = (np.power(phi, indices) - np.power(psi, indices)) / sqrt_5

    return np.rint(fib).astype(int)

fib_series = fibonacci_binet(10)

print(fib_series)
