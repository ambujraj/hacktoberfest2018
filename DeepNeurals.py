
import numpy as np
import h5py
import matplotlib.pyplot as plt
from testCases_v2 import *
from dnn_utils_v2 import sigmoid, sigmoid_backward, relu, relu_backward

get_ipython().magic('matplotlib inline')
plt.rcParams['figure.figsize'] = (5.0, 4.0)  # set default size of plots
plt.rcParams['image.interpolation'] = 'nearest'
plt.rcParams['image.cmap'] = 'gray'

get_ipython().magic('load_ext autoreload')
get_ipython().magic('autoreload 2')

np.random.seed(1)


# **Expected output**:
#
# <table style="width:80%">
#   <tr>
#     <td> **W1** </td>
#     <td> [[ 0.01624345 -0.00611756]
#  [-0.00528172 -0.01072969]] </td>
#   </tr>
#
#   <tr>
#     <td> **b1**</td>
#     <td>[[ 0.]
#  [ 0.]]</td>
#   </tr>
#
#   <tr>
#     <td>**W2**</td>
#     <td> [[ 0.00865408 -0.02301539]]</td>
#   </tr>
#
#   <tr>
#     <td> **b2** </td>
#     <td> [[ 0.]] </td>
#   </tr>
#
# </table>

# ### 3.2 - L-layer Neural Network
#
# The initialization for a deeper L-layer neural network is more complicated because there are many more weight matrices and bias vectors. When completing the `initialize_parameters_deep`, you should make sure that your dimensions match between each layer. Recall that $n^{[l]}$ is the number of units in layer $l$. Thus for example if the size of our input $X$ is $(12288, 209)$ (with $m=209$ examples) then:
#
# <table style="width:100%">
#
#
#     <tr>
#         <td>  </td>
#         <td> **Shape of W** </td>
#         <td> **Shape of b**  </td>
#         <td> **Activation** </td>
#         <td> **Shape of Activation** </td>
#     <tr>
#
#     <tr>
#         <td> **Layer 1** </td>
#         <td> $(n^{[1]},12288)$ </td>
#         <td> $(n^{[1]},1)$ </td>
#         <td> $Z^{[1]} = W^{[1]}  X + b^{[1]} $ </td>
#
#         <td> $(n^{[1]},209)$ </td>
#     <tr>
#
#     <tr>
#         <td> **Layer 2** </td>
#         <td> $(n^{[2]}, n^{[1]})$  </td>
#         <td> $(n^{[2]},1)$ </td>
#         <td>$Z^{[2]} = W^{[2]} A^{[1]} + b^{[2]}$ </td>
#         <td> $(n^{[2]}, 209)$ </td>
#     <tr>
#
#        <tr>
#         <td> $\vdots$ </td>
#         <td> $\vdots$  </td>
#         <td> $\vdots$  </td>
#         <td> $\vdots$</td>
#         <td> $\vdots$  </td>
#     <tr>
#
#    <tr>
#         <td> **Layer L-1** </td>
#         <td> $(n^{[L-1]}, n^{[L-2]})$ </td>
#         <td> $(n^{[L-1]}, 1)$  </td>
#         <td>$Z^{[L-1]} =  W^{[L-1]} A^{[L-2]} + b^{[L-1]}$ </td>
#         <td> $(n^{[L-1]}, 209)$ </td>
#     <tr>
#
#
#    <tr>
#         <td> **Layer L** </td>
#         <td> $(n^{[L]}, n^{[L-1]})$ </td>
#         <td> $(n^{[L]}, 1)$ </td>
#         <td> $Z^{[L]} =  W^{[L]} A^{[L-1]} + b^{[L]}$</td>
#         <td> $(n^{[L]}, 209)$  </td>
#     <tr>
#
# </table>
#
# Remember that when we compute $W X + b$ in python, it carries out broadcasting. For example, if:
#
# $$ W = \begin{bmatrix}
#     j  & k  & l\\
#     m  & n & o \\
#     p  & q & r
# \end{bmatrix}\;\;\; X = \begin{bmatrix}
#     a  & b  & c\\
#     d  & e & f \\
#     g  & h & i
# \end{bmatrix} \;\;\; b =\begin{bmatrix}
#     s  \\
#     t  \\
#     u
# \end{bmatrix}\tag{2}$$
#
# Then $WX + b$ will be:
#
# $$ WX + b = \begin{bmatrix}
#     (ja + kd + lg) + s  & (jb + ke + lh) + s  & (jc + kf + li)+ s\\
#     (ma + nd + og) + t & (mb + ne + oh) + t & (mc + nf + oi) + t\\
#     (pa + qd + rg) + u & (pb + qe + rh) + u & (pc + qf + ri)+ u
# \end{bmatrix}\tag{3}  $$

#
# **Instructions**:
# - The model's structure is *[LINEAR -> RELU] $ \times$ (L-1) -> LINEAR -> SIGMOID*. I.e., it has $L-1$ layers using a ReLU activation function followed by an output layer with a sigmoid activation function.
# - Use random initialization for the weight matrices. Use `np.random.rand(shape) * 0.01`.
# - Use zeros initialization for the biases. Use `np.zeros(shape)`.
# - We will store $n^{[l]}$, the number of units in different layers, in a variable `layer_dims`. For example, the `layer_dims` for the "Planar Data classification model" from last week would have been [2,4,1]: There were two inputs, one hidden layer with 4 hidden units, and an output layer with 1 output unit. Thus means `W1`'s shape was (4,2), `b1` was (4,1), `W2` was (1,4) and `b2` was (1,1). Now you will generalize this to $L$ layers!
# - Here is the implementation for $L=1$ (one layer neural network). It should inspire you to implement the general case (L-layer neural network).
# ```python
#     if L == 1:
#         parameters["W" + str(L)] = np.random.randn(layer_dims[1], layer_dims[0]) * 0.01
#         parameters["b" + str(L)] = np.zeros((layer_dims[1], 1))
# ```

# In[4]:

# GRADED FUNCTION: initialize_parameters_deep

def initialize_parameters_deep(layer_dims):
    """
    Arguments:
    layer_dims -- python array (list) containing the dimensions of each layer in our network

    Returns:
    parameters -- python dictionary containing your parameters "W1", "b1", ..., "WL", "bL":
                    Wl -- weight matrix of shape (layer_dims[l], layer_dims[l-1])
                    bl -- bias vector of shape (layer_dims[l], 1)
    """

    np.random.seed(3)
    parameters = {}
    L = len(layer_dims)  # number of layers in the network

    for l in range(1, L):
        ### START CODE HERE ### (≈ 2 lines of code)
        parameters['W' + str(l)] = np.random.randn(layer_dims[l], layer_dims[l - 1]) * 0.01
        parameters['b' + str(l)] = np.zeros((layer_dims[l], 1))
        ### END CODE HERE ###

        assert (parameters['W' + str(l)].shape == (layer_dims[l], layer_dims[l - 1]))
        assert (parameters['b' + str(l)].shape == (layer_dims[l], 1))

    return parameters


# In[5]:

parameters = initialize_parameters_deep([5, 4, 3])
print("W1 = " + str(parameters["W1"]))
print("b1 = " + str(parameters["b1"]))
print("W2 = " + str(parameters["W2"]))
print("b2 = " + str(parameters["b2"]))


# **Expected output**:
#
# <table style="width:80%">
#   <tr>
#     <td> **W1** </td>
#     <td>[[ 0.01788628  0.0043651   0.00096497 -0.01863493 -0.00277388]
#  [-0.00354759 -0.00082741 -0.00627001 -0.00043818 -0.00477218]
#  [-0.01313865  0.00884622  0.00881318  0.01709573  0.00050034]
#  [-0.00404677 -0.0054536  -0.01546477  0.00982367 -0.01101068]]</td>
#   </tr>
#
#   <tr>
#     <td>**b1** </td>
#     <td>[[ 0.]
#  [ 0.]
#  [ 0.]
#  [ 0.]]</td>
#   </tr>
#
#   <tr>
#     <td>**W2** </td>
#     <td>[[-0.01185047 -0.0020565   0.01486148  0.00236716]
#  [-0.01023785 -0.00712993  0.00625245 -0.00160513]
#  [-0.00768836 -0.00230031  0.00745056  0.01976111]]</td>
#   </tr>
#
#   <tr>
#     <td>**b2** </td>
#     <td>[[ 0.]
#  [ 0.]
#  [ 0.]]</td>
#   </tr>
#
# </table>

# ## 4 - Forward propagation module
#
# ### 4.1 - Linear Forward
# Now that you have initialized your parameters, you will do the forward propagation module. You will start by implementing some basic functions that you will use later when implementing the model. You will complete three functions in this order:
#
# - LINEAR
# - LINEAR -> ACTIVATION where ACTIVATION will be either ReLU or Sigmoid.
# - [LINEAR -> RELU] $\times$ (L-1) -> LINEAR -> SIGMOID (whole model)
#
# The linear forward module (vectorized over all the examples) computes the following equations:
#
# $$Z^{[l]} = W^{[l]}A^{[l-1]} +b^{[l]}\tag{4}$$
#
# where $A^{[0]} = X$.
#
# **Exercise**: Build the linear part of forward propagation.
#
# **Reminder**:
# The mathematical representation of this unit is $Z^{[l]} = W^{[l]}A^{[l-1]} +b^{[l]}$. You may also find `np.dot()` useful. If your dimensions don't match, printing `W.shape` may help.

# In[8]:

# GRADED FUNCTION: linear_forward

def linear_forward(A, W, b):
    """
    Implement the linear part of a layer's forward propagation.
    Arguments:
    A -- activations from previous layer (or input data): (size of previous layer, number of examples)
    W -- weights matrix: numpy array of shape (size of current layer, size of previous layer)
    b -- bias vector, numpy array of shape (size of the current layer, 1)
    Returns:
    Z -- the input of the activation function, also called pre-activation parameter
    cache -- a python dictionary containing "A", "W" and "b" ; stored for computing the backward pass efficiently
    """

    ### START CODE HERE ### (≈ 1 line of code)
    Z = np.dot(W, A) + b
    ### END CODE HERE ###

    assert (Z.shape == (W.shape[0], A.shape[1]))
    cache = (A, W, b)

    return Z, cache


# In[9]:

A, W, b = linear_forward_test_case()

Z, linear_cache = linear_forward(A, W, b)
print("Z = " + str(Z))


# **Expected output**:
#
# <table style="width:35%">
#
#   <tr>
#     <td> **Z** </td>
#     <td> [[ 3.26295337 -1.23429987]] </td>
#   </tr>
#
# </table>

# ### 4.2 - Linear-Activation Forward
#
# In this notebook, you will use two activation functions:
#
# - **Sigmoid**: $\sigma(Z) = \sigma(W A + b) = \frac{1}{ 1 + e^{-(W A + b)}}$. We have provided you with the `sigmoid` function. This function returns **two** items: the activation value "`a`" and a "`cache`" that contains "`Z`" (it's what we will feed in to the corresponding backward function). To use it you could just call:
# ``` python
# A, activation_cache = sigmoid(Z)
# ```
#
# - **ReLU**: The mathematical formula for ReLu is $A = RELU(Z) = max(0, Z)$. We have provided you with the `relu` function. This function returns **two** items: the activation value "`A`" and a "`cache`" that contains "`Z`" (it's what we will feed in to the corresponding backward function). To use it you could just call:
# ``` python
# A, activation_cache = relu(Z)
# ```

# For more convenience, you are going to group two functions (Linear and Activation) into one function (LINEAR->ACTIVATION). Hence, you will implement a function that does the LINEAR forward step followed by an ACTIVATION forward step.
#
# **Exercise**: Implement the forward propagation of the *LINEAR->ACTIVATION* layer. Mathematical relation is: $A^{[l]} = g(Z^{[l]}) = g(W^{[l]}A^{[l-1]} +b^{[l]})$ where the activation "g" can be sigmoid() or relu(). Use linear_forward() and the correct activation function.

# In[10]:

# GRADED FUNCTION: linear_activation_forward

def linear_activation_forward(A_prev, W, b, activation):
    """
    Implement the forward propagation for the LINEAR->ACTIVATION layer
    Arguments:
    A_prev -- activations from previous layer (or input data): (size of previous layer, number of examples)
    W -- weights matrix: numpy array of shape (size of current layer, size of previous layer)
    b -- bias vector, numpy array of shape (size of the current layer, 1)
    activation -- the activation to be used in this layer, stored as a text string: "sigmoid" or "relu"
    Returns:
    A -- the output of the activation function, also called the post-activation value
    cache -- a python dictionary containing "linear_cache" and "activation_cache";
             stored for computing the backward pass efficiently
    """

    if activation == "sigmoid":
        # Inputs: "A_prev, W, b". Outputs: "A, activation_cache".
        ### START CODE HERE ### (≈ 2 lines of code)
        Z, linear_cache = linear_forward(A_prev, W, b)
        A, activation_cache = sigmoid(Z)
        ### END CODE HERE ###

    elif activation == "relu":
        # Inputs: "A_prev, W, b". Outputs: "A, activation_cache".
        ### START CODE HERE ### (≈ 2 lines of code)
        Z, linear_cache = linear_forward(A_prev, W, b)
        A, activation_cache = relu(Z)
        ### END CODE HERE ###

    assert (A.shape == (W.shape[0], A_prev.shape[1]))
    cache = (linear_cache, activation_cache)

    return A, cache


# In[11]:

A_prev, W, b = linear_activation_forward_test_case()

A, linear_activation_cache = linear_activation_forward(A_prev, W, b, activation="sigmoid")
print("With sigmoid: A = " + str(A))

A, linear_activation_cache = linear_activation_forward(A_prev, W, b, activation="relu")
print("With ReLU: A = " + str(A))

# **Expected output**:
#
# <table style="width:35%">
#   <tr>
#     <td> **With sigmoid: A ** </td>
#     <td > [[ 0.96890023  0.11013289]]</td>
#   </tr>
#   <tr>
#     <td> **With ReLU: A ** </td>
#     <td > [[ 3.43896131  0.        ]]</td>
#   </tr>
# </table>
#

# **Note**: In deep learning, the "[LINEAR->ACTIVATION]" computation is counted as a single layer in the neural network, not two layers.

# ### d) L-Layer Model
#
def L_model_forward(X, parameters):
    """
    Implement forward propagation for the [LINEAR->RELU]*(L-1)->LINEAR->SIGMOID computation

    Arguments:
    X -- data, numpy array of shape (input size, number of examples)
    parameters -- output of initialize_parameters_deep()

    Returns:
    AL -- last post-activation value
    caches -- list of caches containing:
                every cache of linear_relu_forward() (there are L-1 of them, indexed from 0 to L-2)
                the cache of linear_sigmoid_forward() (there is one, indexed L-1)
    """

    caches = []
    A = X
    L = len(parameters) // 2  # number of layers in the neural network

    # Implement [LINEAR -> RELU]*(L-1). Add "cache" to the "caches" list.
    for l in range(1, L):
        A_prev = A
        ### START CODE HERE ### (≈ 2 lines of code)
        A, cache = linear_activation_forward(A_prev, parameters['W' + str(l)], parameters['b' + str(l)],
                                             activation="relu")
        caches.append(cache)
        ### END CODE HERE ###

    # Implement LINEAR -> SIGMOID. Add "cache" to the "caches" list.
    ### START CODE HERE ### (≈ 2 lines of code)
    AL, cache = linear_activation_forward(A, parameters['W' + str(L)], parameters['b' + str(L)], activation="sigmoid")
    caches.append(cache)
    ### END CODE HERE ###

    assert (AL.shape == (1, X.shape[1]))

    return AL, caches


# In[25]:

X, parameters = L_model_forward_test_case()
AL, caches = L_model_forward(X, parameters)
print("AL = " + str(AL))
print("Length of caches list = " + str(len(caches)))


# <table style="width:40%">
#   <tr>
#     <td> **AL** </td>
#     <td > [[ 0.17007265  0.2524272 ]]</td>
#   </tr>
#   <tr>
#     <td> **Length of caches list ** </td>
#     <td > 2</td>
#   </tr>
# </table>

# GRADED FUNCTION: compute_cost

def compute_cost(AL, Y):
    """
    Implement the cost function defined by equation (7).
    Arguments:
    AL -- probability vector corresponding to your label predictions, shape (1, number of examples)
    Y -- true "label" vector (for example: containing 0 if non-cat, 1 if cat), shape (1, number of examples)
    Returns:
    cost -- cross-entropy cost
    """

    m = Y.shape[1]

    # Compute loss from aL and y.
    ### START CODE HERE ### (≈ 1 lines of code)
    cost = -1 / m * (np.dot(Y, np.log(AL.T)) + np.dot(1 - Y, np.log(1 - AL).T))
    ### END CODE HERE ###

    cost = np.squeeze(cost)  # To make sure your cost's shape is what we expect (e.g. this turns [[17]] into 17).
    assert (cost.shape == ())

    return cost


# In[29]:

Y, AL = compute_cost_test_case()

print("cost = " + str(compute_cost(AL, Y)))


# **Expected Output**:
#
# <table>
#
#     <tr>
#     <td>**cost** </td>
#     <td> 0.41493159961539694</td>
#     </tr>
# </table>
def linear_backward(dZ, cache):
    """
    Implement the linear portion of backward propagation for a single layer (layer l)
    Arguments:
    dZ -- Gradient of the cost with respect to the linear output (of current layer l)
    cache -- tuple of values (A_prev, W, b) coming from the forward propagation in the current layer
    Returns:
    dA_prev -- Gradient of the cost with respect to the activation (of the previous layer l-1), same shape as A_prev
    dW -- Gradient of the cost with respect to W (current layer l), same shape as W
    db -- Gradient of the cost with respect to b (current layer l), same shape as b
    """
    A_prev, W, b = cache
    m = A_prev.shape[1]

    ### START CODE HERE ### (≈ 3 lines of code)
    dW = 1 / m * (np.dot(dZ, A_prev.T))
    db = 1 / m * (np.sum(dZ, axis=1, keepdims=True))
    dA_prev = np.dot(W.T, dZ)
    ### END CODE HERE ###

    assert (dA_prev.shape == A_prev.shape)
    assert (dW.shape == W.shape)
    assert (db.shape == b.shape)

    return dA_prev, dW, db


# In[33]:

# Set up some test inputs
dZ, linear_cache = linear_backward_test_case()

dA_prev, dW, db = linear_backward(dZ, linear_cache)
print("dA_prev = " + str(dA_prev))
print("dW = " + str(dW))
print("db = " + str(db))


# **Expected Output**:
#
# <table style="width:90%">
#   <tr>
#     <td> **dA_prev** </td>
#     <td > [[ 0.51822968 -0.19517421]
#  [-0.40506361  0.15255393]
#  [ 2.37496825 -0.89445391]] </td>
#   </tr>
#
#     <tr>
#         <td> **dW** </td>
#         <td > [[-0.10076895  1.40685096  1.64992505]] </td>
#     </tr>
#
#     <tr>
#         <td> **db** </td>
#         <td> [[ 0.50629448]] </td>
#     </tr>
#
# </table>
#
#
def linear_activation_backward(dA, cache, activation):
    """
    Implement the backward propagation for the LINEAR->ACTIVATION layer.

    Arguments:
    dA -- post-activation gradient for current layer l
    cache -- tuple of values (linear_cache, activation_cache) we store for computing backward propagation efficiently
    activation -- the activation to be used in this layer, stored as a text string: "sigmoid" or "relu"

    Returns:
    dA_prev -- Gradient of the cost with respect to the activation (of the previous layer l-1), same shape as A_prev
    dW -- Gradient of the cost with respect to W (current layer l), same shape as W
    db -- Gradient of the cost with respect to b (current layer l), same shape as b
    """
    linear_cache, activation_cache = cache

    if activation == "relu":
        ### START CODE HERE ### (≈ 2 lines of code)
        dZ = relu_backward(dA, activation_cache)
        dA_prev, dW, db = linear_backward(dZ, linear_cache)
        ### END CODE HERE ###

    elif activation == "sigmoid":
        ### START CODE HERE ### (≈ 2 lines of code)
        dZ = sigmoid_backward(dA, activation_cache)
        dA_prev, dW, db = linear_backward(dZ, linear_cache)
        ### END CODE HERE ###

    return dA_prev, dW, db


# In[35]:

AL, linear_activation_cache = linear_activation_backward_test_case()

dA_prev, dW, db = linear_activation_backward(AL, linear_activation_cache, activation="sigmoid")
print("sigmoid:")
print("dA_prev = " + str(dA_prev))
print("dW = " + str(dW))
print("db = " + str(db) + "\n")

dA_prev, dW, db = linear_activation_backward(AL, linear_activation_cache, activation="relu")
print("relu:")
print("dA_prev = " + str(dA_prev))
print("dW = " + str(dW))
print("db = " + str(db))


# **Expected output with sigmoid:**
#
# <table style="width:100%">
#   <tr>
#     <td > dA_prev </td>
#            <td >[[ 0.11017994  0.01105339]
#  [ 0.09466817  0.00949723]
#  [-0.05743092 -0.00576154]] </td>
#
#   </tr>
#
#     <tr>
#     <td > dW </td>
#            <td > [[ 0.10266786  0.09778551 -0.01968084]] </td>
#   </tr>
#
#     <tr>
#     <td > db </td>
#            <td > [[-0.05729622]] </td>
#   </tr>
# </table>
#
#

# **Expected output with relu**
#
# <table style="width:100%">
#   <tr>
#     <td > dA_prev </td>
#            <td > [[ 0.44090989  0.        ]
#  [ 0.37883606  0.        ]
#  [-0.2298228   0.        ]] </td>
#
#   </tr>
#
#     <tr>
#     <td > dW </td>
#            <td > [[ 0.44513824  0.37371418 -0.10478989]] </td>
#   </tr>
#
#     <tr>
#     <td > db </td>
#            <td > [[-0.20837892]] </td>
#   </tr>
# </table>
#
#
def L_model_backward(AL, Y, caches):
    """
    Implement the backward propagation for the [LINEAR->RELU] * (L-1) -> LINEAR -> SIGMOID group

    Arguments:
    AL -- probability vector, output of the forward propagation (L_model_forward())
    Y -- true "label" vector (containing 0 if non-cat, 1 if cat)
    caches -- list of caches containing:
                every cache of linear_activation_forward() with "relu" (it's caches[l], for l in range(L-1) i.e l = 0...L-2)
                the cache of linear_activation_forward() with "sigmoid" (it's caches[L-1])

    Returns:
    grads -- A dictionary with the gradients
             grads["dA" + str(l)] = ...
             grads["dW" + str(l)] = ...
             grads["db" + str(l)] = ...
    """
    grads = {}
    L = len(caches)  # the number of layers
    m = AL.shape[1]
    Y = Y.reshape(AL.shape)  # after this line, Y is the same shape as AL

    # Initializing the backpropagation
    ### START CODE HERE ### (1 line of code)
    dAL = - (np.divide(Y, AL) - np.divide(1 - Y, 1 - AL))
    ### END CODE HERE ###

    # Lth layer (SIGMOID -> LINEAR) gradients. Inputs: "AL, Y, caches". Outputs: "grads["dAL"], grads["dWL"], grads["dbL"]
    ### START CODE HERE ### (approx. 2 lines)
    current_cache = caches[L - 1]
    grads["dA" + str(L)], grads["dW" + str(L)], grads["db" + str(L)] = linear_activation_backward(dAL, current_cache,
                                                                                                  activation="sigmoid")
    ### END CODE HERE ###

    for l in reversed(range(L - 1)):
        # lth layer: (RELU -> LINEAR) gradients.
        # Inputs: "grads["dA" + str(l + 2)], caches". Outputs: "grads["dA" + str(l + 1)] , grads["dW" + str(l + 1)] , grads["db" + str(l + 1)]
        ### START CODE HERE ### (approx. 5 lines)
        current_cache = caches[l]
        dA_prev_temp, dW_temp, db_temp = linear_activation_backward(grads["dA" + str(L)], current_cache,
                                                                    activation="relu")
        grads["dA" + str(l + 1)] = dA_prev_temp
        grads["dW" + str(l + 1)] = dW_temp
        grads["db" + str(l + 1)] = db_temp
        ### END CODE HERE ###

    return grads


# In[39]:

AL, Y_assess, caches = L_model_backward_test_case()
grads = L_model_backward(AL, Y_assess, caches)
print("dW1 = " + str(grads["dW1"]))
print("db1 = " + str(grads["db1"]))
print("dA1 = " + str(grads["dA1"]))


# **Expected Output**
#
# <table style="width:60%">
#
#   <tr>
#     <td > dW1 </td>
#            <td > [[ 0.41010002  0.07807203  0.13798444  0.10502167]
#  [ 0.          0.          0.          0.        ]
#  [ 0.05283652  0.01005865  0.01777766  0.0135308 ]] </td>
#   </tr>
#
#     <tr>
#     <td > db1 </td>
#            <td > [[-0.22007063]
#  [ 0.        ]
#  [-0.02835349]] </td>
#   </tr>
#
#   <tr>
#   <td > dA1 </td>
#            <td > [[ 0.          0.52257901]
#  [ 0.         -0.3269206 ]
#  [ 0.         -0.32070404]
#  [ 0.         -0.74079187]] </td>
#
#   </tr>
# </table>
#
#

def update_parameters(parameters, grads, learning_rate):
    """
    Update parameters using gradient descent

    Arguments:
    parameters -- python dictionary containing your parameters
    grads -- python dictionary containing your gradients, output of L_model_backward

    Returns:
    parameters -- python dictionary containing your updated parameters
                  parameters["W" + str(l)] = ...
                  parameters["b" + str(l)] = ...
    """

    L = len(parameters) // 2  # number of layers in the neural network

    # Update rule for each parameter. Use a for loop.
    ### START CODE HERE ### (≈ 3 lines of code)
    for l in range(L):
        parameters["W" + str(l + 1)] = parameters["W" + str(l + 1)] - learning_rate * grads["dW" + str(l + 1)]
        parameters["b" + str(l + 1)] = parameters["b" + str(l + 1)] - learning_rate * grads["db" + str(l + 1)]
    ### END CODE HERE ###

    return parameters


# In[42]:

parameters, grads = update_parameters_test_case()
parameters = update_parameters(parameters, grads, 0.1)

print("W1 = " + str(parameters["W1"]))
print("b1 = " + str(parameters["b1"]))
print("W2 = " + str(parameters["W2"]))
print("b2 = " + str(parameters["b2"]))


# **Expected Output**:
#
# <table style="width:100%">
#     <tr>
#     <td > W1 </td>
#            <td > [[-0.59562069 -0.09991781 -2.14584584  1.82662008]
#  [-1.76569676 -0.80627147  0.51115557 -1.18258802]
#  [-1.0535704  -0.86128581  0.68284052  2.20374577]] </td>
#   </tr>
#
#     <tr>
#     <td > b1 </td>
#            <td > [[-0.04659241]
#  [-1.28888275]
#  [ 0.53405496]] </td>
#   </tr>
#   <tr>
#     <td > W2 </td>
#            <td > [[-0.55569196  0.0354055   1.32964895]]</td>
#   </tr>
#
#     <tr>
#     <td > b2 </td>
#            <td > [[-0.84610769]] </td>
#   </tr>
# </table>
#

#
