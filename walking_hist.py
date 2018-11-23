import numpy as np
import matplotlib as plt

serial=np.genfromtxt("walk_s.dat",delimiter=	",")
paralel=np.genfromtxt("walk_p.dat",delimiter=	",")
bins = np.linspace(-10, 10, 100)

plt.hist(serial[:][0], bins, normed=True, alpha=0.5,label='caminata en serie')
plt.hist(paralel[:][0], bins, normed=True,alpha=0.5,color='red',label='caminata paralelizada')
plt.legend(loc='best')
plt.savefig('caminatas.pdf')

