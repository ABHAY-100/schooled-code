import numpy as np

def print_stats(data):
    avg = np.mean(data)
    variance = np.var(data)
    std_dev = np.std(data)
    
    print(f"Average (Mean): {avg}")
    print(f"Variance: {variance}")
    print(f"Standard Deviation: {std_dev}")

data = np.array(input("Enter the input array ( seperated by spaces): ").split(" "), dtype=int)
print_stats(data)
