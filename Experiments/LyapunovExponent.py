import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

data = pd.read_csv("Integrators\lorenz_divergence.csv")

t = data["t"]
d = data["distance"]

log_d = np.log(d)

plt.plot(t, log_d)
plt.xlabel("time")
plt.ylabel("log(distance)")
plt.show()

coeff = np.polyfit(t, log_d, 1)

lyapunov = coeff[0]

print("Estimated Lyapunov exponent:", lyapunov)