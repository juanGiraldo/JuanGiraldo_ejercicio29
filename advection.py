import numpy as np
import matplotlib.pyplot as plt

u0=np.loadtxt('cond_init.dat')	
uf=np.loadtxt('Advect.dat')	

plt.plot(u0,label='inicial')
plt.plot(uf,label='final')
plt.legend()
plt.savefig('adveccion.pdf')