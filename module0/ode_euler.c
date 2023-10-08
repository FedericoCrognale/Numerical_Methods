#include <stdio.h>
#include <math.h>
#include <stdlib.h> //write on files

//ODE y'=f(y,t)
float f(float t, float y);

int main(){
    FILE *data;
    int i,N;
    float a,b,y0,h,t,w;
    N=100; //#step
    a=-2; //integration range [a,b]
    b=2;
    y0=1; //initial condition
    h=(b-a)/N; //step size
    w=y0; //impose initial condition
    t=a;

    data=fopen("ode_euler_data.dat","w"); //namefile.dat where to write on
    fprintf(data,"#1-t\t2-f(t)");
    fprintf(data,"\n %f\t %f",t,w);
    for (int i = 1; i <= N; i++)
    {   
        w=w+h*f(t,w); //y(n+1)=y(n-1)+hy'(n)+O(h^2)
        t=a+i*h;
        fprintf(data,"\n%f\t %f",t,w);
    }  
}

//function f(y,t)=y'
float f(float t, float y){
    float result;
    result=2*t;
    return result;
}