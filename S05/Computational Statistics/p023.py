import numpy as np

rows = int(input("Rows: "))
cols = int(input("Cols: "))

arr = np.array(input(f"Enter {rows*cols} numbers (seperated by spaces): ").split(), dtype=int).reshape(rows, cols)

np.savetxt('output.csv', arr, delimiter=',', fmt='%d')
