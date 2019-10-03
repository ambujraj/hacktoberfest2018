#The Flajolet-Martin algorithm allows us to find the approximate number of elements in a data stream.
#Here is a demonstration of that algorithm in action.
#https://en.wikipedia.org/wiki/Flajolet%E2%80%93Martin_algorithm -> Wikipedia link for how the algorithm works.

data = [3,1,4,1,5,9,2,6,5]
print("Hash functions are defined as (a*x+b)\%c, where x is an element of the set.")
inputCount = int(input("Enter the number of hash functions: "))
abcList = []

for i in range(inputCount):
	inputList = input("Enter the space-separated values of a, b and c: ").split(" ")
	abcList.append([int(i) for i in inputList])
finalCountsRecorded = []

for i in abcList:
	binElems = []
	for j in set(data):													#Evaluates the hash function, then converts it to binary. 
		binElems.append(str(bin((i[0]*j+i[1])%i[2])).split("b")[1])		#Appends binary output to a list
	greatestTrailing = 0												 
	for k in binElems:													#Processes every element for that specific hash
		reversedCount = k[::-1]				
		count = 0
		for i in reversedCount:											
			if(i=='1'):
				if(count>greatestTrailing):
					greatestTrailing = count							#The greatest number of trailing zeros are established
				break
			else:
				count+=1
	finalCountsRecorded.append(2**greatestTrailing)						#The formula R = 2^r is applied, where R is number of elems,
																		#and r is max trailing zeros recorded
print("Counts recorded for each hash: ",finalCountsRecorded)

divider = inputCount//2
set1 = finalCountsRecorded[:divider]
set2 = finalCountsRecorded[divider:]
means = [sum(set1)/inputCount,sum(set2)/inputCount]						#Note: For demonstration purposes, we only have two sets here.
median = sum(means)/2													#	   Thus, median is defined as (sum of means)/2 

print("Approximate number of elements from mean-median approximation: ",int(median))