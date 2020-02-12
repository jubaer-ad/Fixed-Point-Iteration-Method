# Fixed-Point-Iteration-Method
This is an example of fixed point iteration method in c.

![picture of example output](Fixed-Point%20Iteration.JPG)
-----------------------------------



Assignment on Numerical Method


By
P. A. W.
 


Group Members


I.	A. N. M. JuBaer (162-15-7850)
II.	Abu Sayem (162-15-7682)
III.	Md. Ashiqur Rahman (162-15-7723)
IV.	Abdullah Al Azmi  (162-15-7959)
V.	Md. Ismail Hossain (162-15-7838)
 
 
Bisection Method
 
Fixed Point Iteration
 
Newton’s Method

Bisection Method
It is a method to find roots of a function by repeatedly bisects an interval and take that half in which root must lies for further processing.

Given function is f(x).
Algorithm:
1.	Find the value of a and b such that f(a)*f(b) < 0.
2.	Let an integer r =1.
3.	Then find xr = (a+b)/2.
4.	If f(xr) is positive then replace a or b for which f(x) is positive.
Else replace a or b for which f(x) is negative.
5.	r++ and and find xr by replaced value and unchanged value.
6.	If | xr – xr-1 |  ≈ Tolerance then go to next step.
Else do from step 4 again.
7.	Print root.
8.	Stop.

C Code
#include<stdio.h>
int main ()
{
printf("\t\tC code for Bisection method\n\n");
double lower, upper, criterion, checker, funLower, funUpper, funChecker;
printf("Enter data:\n1.Lower Limit = ?\n2.Upper Limit = ?\n3.Criterion = ?\n");
scanf("%lf %lf %lf",&lower, &upper, &criterion);

    /// given function: x^3 - x - 1

    funLower = (lower*lower*lower)-lower-1;
    funUpper = (upper*upper*upper)-upper-1;
    checker = funLower * funUpper;

    if( checker<0 )
    {
        double root[100];
        int i;

        for (i = 0; i<200; i++)
        {
            root[i] = (lower+upper) /  2;
            funChecker = (root[i] * root[i] * root[i]) - root[i] - 1;
            if (funChecker < 0)
            {
                lower = root[i];
            }
            else if (funChecker > 0)
            {
                upper = root[i];
            }

            if( i >= 1)
            {
                double result, absResult;
                result = root[i-1] - root[i];
                absResult = fabs(result);

                if (criterion >= absResult)
                {
                    printf("Required Root = %lf\n",  root[i]);
                    //break;
                    exit(0);
                }
                else
                 continue;
            }
            else
                continue;
        }
    }
    else
        printf("This data is INVALID");

    return 0;
}
 
 
Fixed Point Iteration
In mathematics Fixed Point Iteration Method is a method to compute fixed points of iterated functions. It is a method to find roots of a function.

Given function is f(x).
Algorithm: 
1.	Find value of  a and b such that f(a)*f(b) < 0.
2.	Rearrange f(x) such that x = ϕ(x)
3.	Find first derivative of ϕ(x), ϕ’(x).
4.	If | ϕ’(x) | < 1 for x ∈ (a, b) then go to step 5
Else change a, b or find another ϕ(x) and check step 4 again.
5.	Let an integer k = 0.
6.	Pick xk from range a to b.
7.	Put xk in xk+1 = ϕ(xk)
8.	If | xk+1 - xk | ≈ Tolerance then go to step 9
Else k++ and go to step 7 again.
9.	Print root.
10.	Stop.
C Code

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double function(double x){
    return ((x*x*x)+(x*x)-1);
}
double fifunction(double x){
    return (1/sqrt(x+1));
}
double der_of_fifunction(double x){
    return (-.5*(1/sqrt(x+1))*(1/(x+1)));
}
void nm2(){
    double a,b;
    printf("Enter value of a: ");
    scanf("%lf",&a);
    printf("Enter value of b: ");
    scanf("%lf",&b);



    double function_value_for_a = function(a);
    double function_value_for_b = function(b);
    if(function_value_for_a*function_value_for_b >= 0){
        printf("Enter a,b again.\n");
        nm2();
    }
    double der_of_fifunction_value_for_a = der_of_fifunction(a);
    if(der_of_fifunction_value_for_a < 0){
        der_of_fifunction_value_for_a = der_of_fifunction_value_for_a * (-1);
    }
    double der_of_fifunction_value_for_b = der_of_fifunction(b);
    if(der_of_fifunction_value_for_b < 0){
        der_of_fifunction_value_for_b = der_of_fifunction_value_for_b * (-1);
    }
    if((der_of_fifunction_value_for_a > 1) || (der_of_fifunction_value_for_b > 1)){
        printf("Derivative of fi function problem. Enter a, b again.\n");
        nm2();
    }



    double tolerance;
    printf("Enter tolerance: ");
    scanf("%lf",&tolerance);
    double x = a;
    double X = fifunction(x);
    double difference = X -x;
    if(difference<0){
        difference = difference * (-1);
    }
    while(difference >= tolerance){
        x = X;
        X = fifunction(x);
        difference = X - x;
        if(difference<0){
            difference = difference * (-1);
        }
    }




    int h = 0, count = 0;
    while(h == 0){
        tolerance = tolerance * 10;
		h = tolerance;
        count ++;
    }
    printf("Result is: ");
    if(count == 1){
        printf("%.1lf",X);
    }
    if(count == 2){
        printf("%.2lf",X);
    }
    if(count == 3){
        printf("%.3lf",X);
    }
    if(count == 4){
        printf("%.4lf",X);
    }
    if(count == 5){
        printf("%.5lf",X);
    }
    if(count == 6){
        printf("%.6lf",X);
    }
    if(count == 7){
        printf("%.7lf",X);
    }
    if(count == 8){
        printf("%.8lf",X);
    }
    if(count == 9){
        printf("%.9lf",X);
    }
    if(count == 10){
        printf("%.10lf",X);
    }
}

int main()
{
    printf("Fixed-Point Iteration Method.\n");
    nm2();
    return 0;
}
 





Newton’s Method
The Newton’s Method (Newton-Raphson Method) is a numerical method to find roots of an equation. It gives successively better approximations of roots of a real valued function.

Given function is f(x).
Algorithm:
1.	Calculate the first derivative f’(x) of given function f(x).
2.	Find a and b such that f(a)*f(b) < 0.
3.	Let an integer k = 0.
4.	Pick a value for  xk from range a to b.
5.	Put xk in xk+1 = xk – f(xk)/f’(xk)
6.	If| xk+1- xk| ≈ Tolerance then go to step 7.
else k++ and go to step 5 again.
7.	Print root.
8.	Stop

C Code
#include<stdio.h>
int main ()
{
    printf("\t\tC code for Newton-Raphson method\n\n");
    double lower, upper, criterion, checker, funLower, funUpper, funChecker;
    printf("Enter data:\n1.Lower Limit = ?\n2.Upper Limit = ?\n3.Criterion = ?\n");
    scanf("%lf %lf %lf",&lower, &upper, &criterion);

    /// given function: x^3 - 3x - 5

    funLower = (lower*lower*lower) - (3*lower) - 5;
    funUpper = (upper*upper*upper) - (3*upper) - 5;
    checker = funLower * funUpper;

    if( checker<0 )
    {
        double root[10];
        int i;
        root[1] = 2;

        for (i = 2; i<200; i++)
        {
            root[i] = ((2*root[i-1]*root[i-1]*root[i-1]) + 5) / ((3*root[i-1]*root[i-1]) - 3);

            if( i >= 3)
            {
                double result, absResult;
                result = root[i-1] - root[i];
                absResult = fabs(result);

                if (criterion >= absResult)
                {
                    printf("Required Root = %lf\n",  root[i]);
                    //break;
                    exit(0);
                }
                else
                 continue;
            }
            else
                continue;
        }
    }
    else
        printf("This data is INVALID");

    return 0;
}

**The End**

