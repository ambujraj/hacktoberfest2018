fact(0,1).
fact(X,Y) :- A is X-1, fact(A,B),Y is B*X.
