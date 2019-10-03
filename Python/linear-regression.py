'''
Given dataset:
||Years worked (x) || Salary (y) ||
||		 3 		   ||	  30	 ||
||		 8 		   ||     57     ||
||		 9 		   ||	  64	 ||
||		13 		   ||	  72	 ||
||		 3 		   ||	  36	 ||
||		 6 		   ||	  43	 ||
||		11         ||     59     ||
||      21         ||     90     ||
||       1         ||     20     ||
||       16        ||     83     ||

This program performs linear regression on this dataset.
'''
def average(x):
	return sum(x)/len(x)

x = [3,8,9,13,3,6,11,21,1,16]
y = [30,57,64,72,36,43,59,90,20,83]
xBar = average(x)
yBar = average(y)
xiMinusxBar=[]
yiMinusyBar=[]
for i in x:
	xiMinusxBar.append(i-xBar)
for i in y:
	yiMinusyBar.append(i-yBar)
productSum = sum([xiMinusxBar[i]*yiMinusyBar[i] for i in range((len(xiMinusxBar)))])
squareSum = sum([xiMinusxBar[i]**2 for i in range((len(xiMinusxBar)))])
b1 = productSum/squareSum
b0 = yBar - (b1*xBar)

x = float(input("Enter years and I'll tell you the expected salary: "))
y = b0+(b1*x)
print("Expected salary after ",x," years is: ",y)