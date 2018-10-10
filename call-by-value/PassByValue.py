#python supports call by value where an value is always an object reference

#PassByValue (Object Reference)
def add(list):
    list.append('new') 
list = ['Edureka']
add(list)
print(list) 