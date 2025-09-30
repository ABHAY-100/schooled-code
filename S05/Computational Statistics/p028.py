import numpy as np

x = np.array([10, 20, 30, 40, 50])
y = np.array([15, 25, 35, 45, 60])

corr_matrix = np.corrcoef(x, y)

print("Pearson corr coeff:", corr_matrix[0, 1])
