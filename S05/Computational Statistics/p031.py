import numpy as np

populations = np.array([
    4779736,
    710231,
    6392017,
    2915918,
    37253956,
    5029196,
    3574097,
    897934
])

mean_pop = np.mean(populations)
median_pop = np.median(populations)
variance_pop = np.var(populations)

print("Mean:", mean_pop)
print("Median:", median_pop)
print("Variance:", variance_pop)
