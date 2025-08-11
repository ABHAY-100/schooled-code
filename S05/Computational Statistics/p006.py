matrix = {}

sparse = {
    0 : [],
    1 : [],
    2 : [],
}

rows = 2
cols = 2

print("Enter Matrix : ")
for i in range(0, rows) :
    for j in range(0, cols) :
        matrix[(i, j)] = input(f"({i}, {j}): ")

for i in range(0, rows) :
    for j in range(0, cols) :
        sparse[0].append(i)
        sparse[1].append(j)
        sparse[2].append(matrix.get((i, j)))

print("Sparse Matrix : ")
for i in range(len(sparse[0])):
    print(f"{sparse[0][i]} {sparse[1][i]} {sparse[2][i]}")