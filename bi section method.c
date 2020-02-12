#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double eqn(int p, int q, int r, double x){
    double eqn = (p*x*x*x) + (q*x*x) - r;
	return eqn;
}

double eqn2(int p, int q, int r, double x){
    double eqn2 = sqrt(r)*(1/(sqrt((p*x)+q))); // ϕ(x)
	return eqn2;
}

double der_eqn(int p, int q, int r, double x){
    double der_eqn = sqrt(r)*(-.5)*(1/(sqrt(p*x) + q))*1/((p*x)+q); // ϕ'(x)
	return der_eqn;
}
double fixed_point(int p, int q, int r, double tolerance){
    double x, a, b;
    printf("Enter value of a and b: ");
    scanf("%lf%lf",&a, &b);
    x = a;
    double eqnV1 = eqn(p, q, r, x);
    printf("eqnV1 : %lf",eqnV1);
    double der_eqn2V1 = eqn2(p, q, r, x);
    if(der_eqn2V1 < 0){
        der_eqn2V1 = der_eqn2V1 * (-1);
    }
    if (der_eqn2V1 > (1)){
        printf("a and b are not right for ϕ(x). Enter a, b again.");
        fixed_point(p, q, r, tolerance);
    }
    x = b;
    double eqnV2 = eqn(p, q, r, x);
    double der_eqn2V2 = eqn2(p, q, r, x);
    if(der_eqn2V2 < 0){
        der_eqn2V2 = der_eqn2V2 * (-1);
    }
    if (der_eqn2V2 > (1)){
        printf("a and b are not right for ϕ(x). Enter a, b again.");
        fixed_point(p, q, r, tolerance);
    }
    if(eqnV1 * eqnV2 >= 0){
        printf("a * b !< 0. Enter a, b again.");
        fixed_point(p, q, r, tolerance);
    }

    double xv[20];
    int k = 0;
    xv[k] = a;
    x = xv[k];
    xv[k+1] = eqn2(p, q, r, x);
    double preTol = xv[k] - xv[k+1];
    if (preTol < 0){
        preTol = preTol * (-1);
    }
    while( (preTol != tolerance) || (preTol > tolerance) ){
        k++;
        x = xv[k];
        xv[k+1] = eqn2(p, q, r, x);
        double preTol = xv[k] - xv[k+1];
        if (preTol < 0){
            preTol = preTol * (-1);
        }
    }


    return xv[k+1];

















     /* ϕ(x)
    double der_eqn = sqrt(r)*(-.5)*1/(sqrt(p*x + q))*1/(p*x+q); // ϕ'(x)

    x = a;
    double eqn = eqn(p, q, r, x);
    double eqnV1 = eqn;
    printf("%lf",&eqn);
    double der_eqnV1 = der_eqn;
    if(der_eqnV1 < 0){
        der_eqnV1 = der_eqnV1 * (-1);
    }
    x = b;
    double eqnV2 = eqn;
    printf("%lf",&eqn);
    double der_eqnV2 = der_eqn;
    if(der_eqnV2 < 0){
        der_eqnV2 = der_eqnV2 * (-1);
    }
    if(eqnV1 * eqnV2 >= 0){
        printf("a * b !< 0. Enter a, b again.");
        fixed_point(p, q, r, tolerance);
    }
    if (der_eqnV1 <! (1)){
        printf("a and b are not right for ϕ(x). Enter a, b again.");
        fixed_point(p, q, r, tolerance);
    }
    if (der_eqnV2 <! (1)){
        printf("a and b are not right for ϕ(x). Enter a, b again.");
        fixed_point(p, q, r, tolerance);
    }
    double xv[20];
    int k = 0;
    xv[k] = a;
    x = xv[k];
    xv[k+1] = eqn2;
    double preTol = xv[k] - xv[k+1];
    if (preTol < 0){
        preTol = preTol * (-1);
    }
    while( preTol <! tolerance ){
        k++;
        x = xv[k];
        xv[k+1] = eqn2;
        double preTol = xv[k] - xv[k+1];
        if (preTol < 0){
            preTol = preTol * (-1);
        }
    }
    return xv[k+1];


    */


}



int main()
{
    int p, q, r, tolerance;
    printf("Enter constant of X^3: ");
    scanf("%d",&p);
    printf("Enter constant of X^2: ");
    scanf("%d",&q);
    printf("Enter constant: ");
    scanf("%d",&r);
    printf("Enter tolerance: ");
    scanf("%lf",&tolerance);
    double result = fixed_point(p, q, r, tolerance);
    int h = 0, count = 0;
    while(h == 0){
        h = tolerance * 10;
        count ++;
    }


    printf("So root of inputed function is: %.(count)f",result);
    return 0;
}
