import numpy as np

A = np.array([[1, 2, 3],
              [4, 5, 6]])

B = np.array([[7,  8,  9, 10],
              [11, 12, 13, 14],
              [15, 16, 17, 18]])

C = np.einsum('ik,kj->ij', A, B)

print("Result:")
print(C)
