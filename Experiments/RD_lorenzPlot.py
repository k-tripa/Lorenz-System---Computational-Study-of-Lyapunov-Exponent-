import pandas as pd
import matplotlib.pyplot as plt

data1 = pd.read_csv("Integrators\\lorenz_RK4.csv")
data2 = pd.read_csv("Integrators\\lorenz2_RK4.csv")

fig = plt.figure()
ax = fig.add_subplot(projection='3d')

ax.plot(data1["x"], data1["y"], data1["z"], label="System 1")
ax.plot(data2["x"], data2["y"], data2["z"], label="System 2")

ax.legend()
plt.show()