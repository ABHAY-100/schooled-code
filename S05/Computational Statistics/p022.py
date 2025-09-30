import numpy as np

rows = int(input("Rows: "))
cols = int(input("Cols: "))

A = np.array(input(f"Enter {rows*cols} numbers (seperated by spaces): ").split(), dtype=int).reshape(rows, cols)
Q, R = np.linalg.qr(A)

print("Q @ R close to A:", np.allclose(Q @ R, A))
print("Q.T @ Q close to I:", np.allclose(Q.T @ Q, np.eye(R.shape[0])))
