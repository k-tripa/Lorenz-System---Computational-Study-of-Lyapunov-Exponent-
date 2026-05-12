import pandas as pd
import numpy as np

d_0 = 1e-8
sum = 0.0
n = 0.0
d = pd.read_csv("Integrators\\lorenz_divergence_RD.csv")

for j in range(2000,8000):
    d_j = d.iloc[j,2]
    g_k = np.log(d_j/d_0)
    sum += g_k
    n += 1


dt = d.iloc[1,1] - d.iloc[0,1]
lyap = sum / (n*dt)

print('The lyapunov exponent is : ', lyap)