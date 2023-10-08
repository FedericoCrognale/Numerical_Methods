#include <stdio.h>
#include <math.h>

float f(float x);

int main(){
    int count;
    float epsilon,x1,x2,Dx,xm;
    epsilon=1E-3; //error
    x1=-180; //start range
    x2=300; //end range x2>x1
    Dx=x2-x1;
    count=0;

    //Check initial values
    if(f(x1)*f(x2)>0){
        printf("Error: change x1 or x2, we must find a root!\n");
    }

    while(Dx>epsilon){
        count+=1;
        xm=(x1+x2)/2;
        if(f(xm)==0){
            printf("Solution: x=%.5f",xm);
            Dx=0;
        }
        else if(f(x1)*f(x2)<0){
            if(f(x1)*f(xm)<0){
                x2=xm;
                }
            else if(f(xm)*f(x2)<0){
                x1=xm;
                }
            Dx=x2-x1;
        }    
    }
    printf("Solution: x=%.5f +- %.5f\nIterations: %d\n",xm,Dx/2,count);
}

//functions
float f(float x){
    return x*x*x+x*x-1;
}