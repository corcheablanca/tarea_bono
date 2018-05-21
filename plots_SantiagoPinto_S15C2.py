import numpy as np
import matplotlib.pyplot as plt
from matplotlib.pylab import hist, show

M=np.loadtxt("datosc.txt")
M2=np.loadtxt("Canal_ionico.txt")

plt.figure()
hist(M[:,1])
plt.savefig("histograma_x")
plt.close()

plt.figure()
hist(M[:,2])
plt.savefig("histograma_y")
plt.close()

l=list(M[:,1])
l2=list(M[:,2])
lr=list(M[:,0])
 
def repetido(l):  
	repeticiones = 0                                                                    
	for i in l:                                                                              
    		apariciones = l.count(i)                                                             
    		if apariciones > repeticiones:                                                       
			repeticiones = apariciones 
			repetido=i
	return repetido

ex=repetido(l)
ye=repetido(l2)
radio=repetido(lr)

th=np.linspace(0,2*np.pi,40)
plt.figure()
plt.title("parametros: x ="+ str(ex) +", "+"y ="+ str(ye) + "  radio="+ str(radio))
plt.axis("equal")
plt.scatter(M2[:,0],M2[:,1])
plt.scatter(ex,ye)
plt.plot(radio*np.cos(th)+ex,radio*np.sin(th)+ye)
plt.savefig("grafica")
plt.close()








