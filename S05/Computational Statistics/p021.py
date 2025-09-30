import numpy as np

rows = int(input("Rows: "))
cols = int(input("Cols: "))

matrix = np.array(input(f"Enter {rows*cols} numbers (seperated by spaces): ").split(), dtype=int).reshape(rows, cols)

matrix_list = matrix.tolist()

print(matrix_list)
