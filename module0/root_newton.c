#include <stdio.h>
#include <math.h>

float f(float x);
float f1(float x, float h);
float absolute(float x);

int main(){
    float x, x0, epsilon, h, Dx;
    int count;
    epsilon=1E-3; //tolerance
    h=1E-3; //derivative step
    x0=-1; //close to solution
    Dx=f(x0)/f1(x0,h); //x-x0=Dx
    count=0; //interation number
    while (absolute(Dx)>epsilon)
    {       
        x=x0-f(x0)/f1(x0,h);
        x0=x;
        Dx=f(x0)/f1(x0,h);
        count++;
    }
    printf("Solution: %f +- %f\nIteration: %d\n",x,absolute(Dx),count);
}

//function
float f(float x){
    float y;
    y=x*x*x/5+x/5+0.1;
    return y;
}

//derivative
float f1(float x,float h){
    float y1;
    y1=(f(x+h)-f(x-h))/(2*h);
    return y1;
}

//absolute value
float absolute(float x){
    if (x<0)
    {
        x=-x;
    }
    return x;
}