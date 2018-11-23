import numpy as np
import matplotlib as plt

text=np.genfromtxt("walks.dat",delimiter=	",")

bins = np.linspace(-10, 10, 100)

plt.hist(muestra[:][0], bins, normed=True, alpha=0.5)
plt.savefig('caminatas.pdf')

