import numpy as np

def print_stats(data):
    arr = np.array(data)
    avg = np.mean(arr)
    variance = np.var(arr)
    std_dev = np.std(arr)
    
    print(f"Average (Mean): {avg}")
    print(f"Variance: {variance}")
    print(f"Standard Deviation: {std_dev}")

data = [10, 20, 30, 40, 50]
print_stats(data)
