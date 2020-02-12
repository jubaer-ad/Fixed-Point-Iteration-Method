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
        printf("Derivative of fi function problem. Enter a,b again.\n");
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
