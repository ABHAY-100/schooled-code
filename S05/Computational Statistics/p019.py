import numpy as np

a = np.array([1, 2, 3])
b = np.array([4, 5, 6])

inner_product = np.inner(a, b)
outer_product = np.outer(a, b)
cross_product = np.cross(a, b)

print("Inner Product:\n", inner_product)
print("\nOuter Product:\n", outer_product)
print("\nCross Product:\n", cross_product)
