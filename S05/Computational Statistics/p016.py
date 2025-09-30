import numpy as np

rows = int(input("Rows: "))
cols = int(input("Cols: "))

a = np.array(input(f"Enter {rows*cols} numbers (seperated by spaces): ").split(), dtype=int).reshape(rows, cols)

flat = a.flatten()

print(flat)
