import numpy as np

a = np.random.rand(3, 4, 5)
diagonals = [np.diagonal(a[i], axis1=0, axis2=1) for i in range(a.shape[0])]
for d in diagonals: print(d)
