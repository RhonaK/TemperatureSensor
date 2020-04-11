import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

f=open("TemperatureData.txt", "r")

line = f.readline()
lines = []

_x, temperature= [], []
_i = 0

while line:
	_x.insert(_i, _i)	
	temperature.insert(_i, float(line.rstrip()))
	line = f.readline()
	_i = _i + 1
	
f.close()
	
plt.figure(1)
plt.plot(_x, temperature)
plt.title('Temperature[*C]')
plt.grid(True)
plt.xlim([0, _i])
plt.ylim([0, 100])

plt.savefig("TempPlot.png")