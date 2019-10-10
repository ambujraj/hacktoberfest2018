import matplotlib.pyplot as plt
import numpy as np

x = np.arange(0,4*np.pi,0.1)
sin_x = np.sin(x)
cos_x = np.cos(x)

plt.plot(x, sin_x, x, cos_x)
plt.title('Plot of sin(x) and cos(x) from 0 to 4pi')
plt.legend(['sin(x)', 'cos(x)'])
plt.grid(True);
axes = plt.gca()
axes.set_xlim([0,4*np.pi])
axes.set_ylim([-1,1])
plt.show()
