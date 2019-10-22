#include <bits/stdc++.h> 
using namespace std; 

double f(double x) 
{ 
	return x*x*x*x -x -10; 
} 

void secant(float x1, float x2, float E) 
{ 
	float n = 0, xm, x0, c; 
	if (f(x1) * f(x2) < 0) { 
		do { 	
			x0 = (x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1)); 			
			c = f(x1) * f(x0); 		
			x1 = x2; 
			x2 = x0; 
			n++; 
			if (c == 0) 
				break; 
			xm = (x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1)); 
		} while (fabs(xm - x0) >= E); 								
		cout << "Root of the given equation=" << x0 << endl; 
		cout << "No. of iterations = " << n << endl; 
	} else
		cout << "Can not find a root in the given inteval"; 
} 
 
int main() 
{ 
	clock_t begin = clock();
double a = 0, b = 1, E = 0.0001; 


printf("Enter domain a b for the equation X^4 -x-10=0  as 'a' space 'b' for [a, b]\n");
scanf("%lf %lf", &a, &b);

	secant(a, b, E); 

	clock_t end = clock();
double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

printf("Program Running time:  %lf\n",time_spent);
	return 0; 
} 
