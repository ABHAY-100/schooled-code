import numpy as np

a = np.array(input("Enter A: ").split(" "), dtype=int)
b = np.array(input("Enter B: ").split(" "), dtype=int)

inner_product = np.inner(a, b)
outer_product = np.outer(a, b)
cross_product = np.cross(a, b)

print("Inner Product:\n", inner_product)
print("\nOuter Product:\n", outer_product)
print("\nCross Product:\n", cross_product)
