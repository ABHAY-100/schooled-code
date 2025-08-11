import numpy as np

A = np.array([[1, 2], [3, 4], [5, 6]])
Q, R = np.linalg.qr(A)

print("Q @ R close to A:", np.allclose(Q @ R, A))
print("Q.T @ Q close to I:", np.allclose(Q.T @ Q, np.eye(R.shape[0])))
