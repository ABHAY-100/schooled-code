import numpy as np

rows = int(input("Rows: "))
cols = int(input("Cols: "))

A = np.array(input(f"Enter {rows*cols} numbers (separated by spaces): ").split(), dtype=float).reshape(rows, cols)

eigenvalues, eigenvectors = np.linalg.eig(A)

print("Eigenvalues: ", eigenvalues)

print("Eigenvectors: ", eigenvectors)
