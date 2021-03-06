#import numpy as np
#import matplotlib.pyplot as plt

#with open("all_points.txt") as f:
#data = f.read()

#data = data.split('\n')

#x = [row.split(' ')[0] for row in data]
#y = [row.split(' ')[1] for row in data]

#plt.plot(x,y,"o")

from matplotlib import pyplot;
from pylab import genfromtxt;  
mat0 = genfromtxt("all_points.txt");
mat1 = genfromtxt("triangles.txt");
pyplot.scatter(mat0[:,0], mat0[:,1]);
pyplot.plot(mat1[:,0], mat1[:,1]);
pyplot.legend();
pyplot.show();
