#The ability to overload standard operators so that they have appropriate behaviour based on their 
#context. It is the ability to present the same interface for differing underlying forms
#It means that if class B inherits from class A, It doesnt have to inherit everthing about the class
#A; it can do some of the things that class A does diffrently
#It is most commonly used when dealing with inheritance
#Python is implicit;y polymorphic.

a = "Alfa"
b = (1,2,3,4)
c = ['o', ' m', 'e','g', 'a']

print (a[2])
print (b[1])
print (c[3])

class Animal:
    def __init__(self, name):
        self.name = name
    def talk(self):
        pass
class Cat(Animal):
    def talk(self):
        print('Meow!')

class Dog(Animal):
    def talk(self):
        print('Woof!')

a = Animal('Dog')
print(a.name)  





