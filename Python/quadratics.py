# favourite snippet bc it saved me way too much time during a quadratics unit
def work():
    coeffs = list(map(float,input("Enter quadratic coeffs : ").split()))
    determinant = ((coeffs[1]**2)-(4*coeffs[0]*coeffs[2]))**0.5
    plus = (-coeffs[1]+determinant)/(2*coeffs[0])
    minus = (-coeffs[1]-determinant)/(2*coeffs[0])
    print(str(plus) + " " + str(minus))
