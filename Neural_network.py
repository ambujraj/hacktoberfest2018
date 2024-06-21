from numpy import *
import numpy as np
from random import random
np.random.seed(0)
class MLP:
	def __init__(self,n_inputs=3,n_hidden=[2,3],n_outputs=2):
		self.n_inputs = n_inputs
		self.n_hidden = n_hidden
		self.n_outputs = n_outputs

		self.layers = [self.n_inputs] + self.n_hidden + [self.n_outputs]

		weights = []
		activation = []
		derivative = []

		for _ in range(len(self.layers)-1):
			temp = np.random.rand(self.layers[_],self.layers[_+1])
			weights.append(temp)
		self.weights = weights

		for _ in range(len(self.layers)-1):
			temp = np.zeros((self.layers[_],self.layers[_+1]))
			derivative.append(temp)
		self.derivative = derivative

		for _ in range(len(self.layers)):
			temp = np.zeros(self.layers[_])
			activation.append(temp)
		self.activation = activation
 
		
	def forward(self,_input):
		self.activation[0] = _input
		activation = _input
		for i,w in enumerate(self.weights):
			output = np.dot(activation,w)
			activation = self._sigmoid(output)
			self.activation[i+1] = activation
		return activation


	def back_propogation(self,error):
		for i in reversed(range(len(self.weights))):
			delta = error*self.sigmoid_derivative(self.activation[i+1])
			delta_reshaped = delta.reshape(delta.shape[0],-1).T
			activation = self.activation[i]
			activation = activation.reshape(activation.shape[0],1)
			self.derivative[i] = np.dot(activation,delta_reshaped)
			error = np.dot(delta,self.weights[i].T)
		return error


	def gradient_descent(self,learning_rate=0.1):
		for i in range(len(self.weights)):
			self.weights[i] += self.derivative[i]*learning_rate


	def sigmoid_derivative(self,x):
		return x*(1-x)


	def _sigmoid(self,_):
		return 1/(1+np.exp(-_))

	def train(self,inputs,targets,epochs,learning_rate):
		for _ in range(epochs):
			sum_error = 0
			for i,t in zip(inputs,targets):
				output = self.forward(i)
				error = t - output
				self.back_propogation(error)
				sum_error += (t-output)**2
				self.gradient_descent(learning_rate)
			print("{} - {}".format(_,sum_error/len(inputs)))	


if __name__ == '__main__':
	a = MLP(2,[3],1)
	train_x = np.array([[random()/2 for _ in range(2)]for i in range(0,10000)])
	train_y = np.array([a[0] + a[1] for a in train_x])
	a.train(train_x,train_y,50,0.1)
	x = np.array([0.1,0.1])
	y = a.forward(x)
	print(y)
