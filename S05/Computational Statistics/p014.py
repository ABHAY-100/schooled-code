import pandas as pd
import matplotlib.pyplot as plt

x = range(-10, 11)
y = [i**2 for i in x] # y = x^2

df = pd.DataFrame({'x': x, 'y': y})

plt.figure(figsize=(8, 5))
plt.plot(df['x'], df['y'], label='y = x^2', color='blue')
plt.show()
