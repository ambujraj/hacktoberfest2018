import math
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.cm as cm

# Constants that define the attractor
a = -0.966918
b = 2.879879
c = 0.765145
d = 0.744728

# Values are in range [-2,2]
num_iter = 100000
num_pix = 256
im_mat = np.zeros([num_pix, num_pix], dtype=int)

x = 0.1
y = 0.23
for i in range(num_iter):
    xnew = math.sin(y*b) + c*math.sin(x*b)
    ynew = math.sin(x*a) + d*math.sin(y*a)
    ind_x = int((xnew+2)*(num_pix/4))
    ind_y = int((ynew+2)*(num_pix/4))
    im_mat[ind_x,ind_y] = im_mat[ind_x,ind_y] + 1
    x = xnew
    y = ynew

fig = plt.figure()
ax1 = fig.add_subplot(121)
# Bilinear interpolation - this will look blurry
ax1.imshow(im_mat, interpolation='bilinear', cmap=cm.Greys_r)

ax2 = fig.add_subplot(122)
# 'nearest' interpolation - faithful but blocky
ax2.imshow(im_mat, interpolation='nearest', cmap=cm.Greys_r)

plt.show()

