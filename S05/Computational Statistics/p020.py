import numpy as np

A = np.array([[1, 2],
              [3, 4]])

B = np.array([[0, 5],
              [6, 7]])

K = np.kron(A, B)

print(K)
