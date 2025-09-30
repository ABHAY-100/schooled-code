import matplotlib.pyplot as plt

heights = [150, 155, 160, 162, 158, 165, 170, 172, 160, 167, 150, 155, 160]

plt.hist(heights, bins=5, edgecolor='black')

plt.title("Histogram of Classmates' Heights")
plt.xlabel("Height (cm)")
plt.ylabel("Number of Students")

plt.show()
