class Prime:
	def isPrime(self,num : int)->bool:
	  if num<=1:
    	return False
    for i in range(2,num//2):
      if num%i == 0:
      	return False
    return True

	def genPrimeList(self,range:int)->list:
    count = 0
    num=2
    List = []
    while(count<range):
    	if(self.isPrime(num)):
      	List.append(num) 
				count+=1
      num+=1
    return List
