import numpy as np

rows = int(input("Rows: "))
cols = int(input("Cols: "))

matrix = np.array(input(f"Enter {rows*cols} numbers (separated by spaces): ").split(), dtype=int).reshape(rows, cols)
ord_diff = int(input("Enter the order difference: "))

print("Order Difference : ", np.diff(matrix, ord_diff))
