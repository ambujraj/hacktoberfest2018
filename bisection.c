#include<stdio.h>
#include <stdlib.h>
#include <math.h>
#include<time.h>
//bisection method

double  equation(double x){
    return x*x*x*x - x - 10;}

int main(){
    clock_t begin = clock();
double a,b,c=0;
printf("Enter domain a b for the equation X^4 -x-10=0  as 'a' space 'b' for [a, b]\n");
scanf("%lf %lf", &a, &b);
 if(equation(a)==0 || equation(b)==0){
        printf("Root is one of interval bounds. Root is %f\n",equation(a)==0?a:b);
        exit(0);
}
while(equation(a)*equation(b)>0){
    printf("Domain not satisfying intermeadiate value theorem try another\n");
    scanf("%lf %lf", &a, &b);}

c=(a+b)/2;
int iteration=0;
while (fabs(equation(c)) >=0.001){
    c=(a+b)/2;
    iteration = iteration+1;
    if(equation(c)*equation(b)<0){
        a=c;}
    else
        b=c;
    if( equation(c)>=0 && equation(c)<0.001 ){
        break;
    }

}

printf("Iteration: %d\n", iteration);
printf(" solution: %lf and vaue of f(c): %lf\n",c, equation(c));



clock_t end = clock();
double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

printf("Program Running time:  %lf\n",time_spent);
 
    return 0;
}
