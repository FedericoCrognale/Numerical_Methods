#include <stdio.h>
#include <math.h>

float f(float x);
float f1(float x,float h);

int main(){
    float x,h;
    x=2; //computing point
    h=1E-5; //increase parameter
    printf("x=%f\t h=%f\nf(x)=%f\t f1(x)=%f\n",x,h,f(x),f1(x,h));
}

//function
float f(float x){
    return 1/x;
}

//derivative
float f1(float x,float h){
    float result;
    result=(f(x+h)-f(x-h))/(2*h);
    return result;
}