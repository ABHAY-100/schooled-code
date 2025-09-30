import numpy as np

rows = int(input("Rows of A: "))
cols = int(input("Cols of A: "))

A = np.array(input(f"Enter {rows*cols} numbers (seperated by spaces): ").split(), dtype=int).reshape(rows, cols)

rows = int(input("Rows of B: "))
cols = int(input("Cols of B: "))

B = np.array(input(f"Enter {rows*cols} numbers (seperated by spaces): ").split(), dtype=int).reshape(rows, cols)

K = np.kron(A, B)

print(K)
