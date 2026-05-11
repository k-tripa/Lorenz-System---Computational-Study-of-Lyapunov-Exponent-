import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

data = pd.read_csv("Integrators\\lorenz_divergence_RK4.csv")
data1 = pd.read_csv("Integrators\\lorenz_divergence_B.csv")

t = data["t"]
d = data["distance"]

log_d = np.log(d)

t1 = data1["t"]
d1 = data1["distance"]

log_d1 = np.log(d1)

plt.subplot(1,2,1)
plt.plot(t, log_d)
plt.xlabel("time")
plt.ylabel("log(distance)")
plt.title("direct divergence method")
plt.subplot(1,2,2)
plt.plot(t1, log_d1)
plt.xlabel("time")
plt.ylabel("log(distance)")
plt.title("benettin algorithm")
plt.show()
