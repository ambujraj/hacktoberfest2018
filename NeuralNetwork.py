import numpy
import os
import scipy.special
import matplotlib.pyplot7
import PIL
%matplotlib inline

class neuralNetwork:
	
	def __init__(self,inputNodes, hiddenNodes, outputNodes, learningRate):
		self.inNodes = inputNodes
		self.hidNodes = hiddenNodes
		self.outNodes = outputNodes
		
		self.wih = (numpy.random.rand(self.hidNodes, self.inNodes)-0.5)
		self.woh = (numpy.random.rand(self.outNodes, self.hidNodes)-0.5)
		
		
		self.lRate = learningRate
		
		self.actFunc = lambda x: scipy.special.expit(x)
		
		pass
		
	def query(self, inputs_list):
	
	
		inputs = numpy.array(inputs_list, ndmin=2).T
		
		hidden_inputs = numpy.dot(self.wih, inputs)
		hidden_outputs = self.actFunc(hidden_inputs)
		
		final_inputs = numpy.dot(self.woh, hidden_outputs)
		final_outputs = self.actFunc(final_inputs)
		
		return final_outputs
		
	def train(self, inputs_list, target_list):
		inputs = numpy.array(inputs_list, ndmin=2).T
		targets = numpy.array(target_list, ndmin=2).T
		
		hidden_inputs = numpy.dot(self.wih, inputs)
		hidden_outputs = self.actFunc(hidden_inputs)
		
		final_inputs = numpy.dot(self.woh, hidden_outputs)
		final_outputs = self.actFunc(final_inputs)
		
		output_errors = targets - final_outputs
		hidden_errors = numpy.dot(self.woh.T, output_errors)

		self.woh += self.lRate * numpy.dot((output_errors* final_outputs * (1-final_outputs)), numpy.transpose(hidden_outputs))
		self.wih += self.lRate * numpy.dot((hidden_errors* hidden_outputs *(1-hidden_outputs)), numpy.transpose(inputs))

		pass