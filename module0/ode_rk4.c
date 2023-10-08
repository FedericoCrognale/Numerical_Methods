#include <stdio.h>
#include <math.h>
#include <stdlib.h>
//ODE y'=f(t,y)
float f(float t, float y);

int main(){
    FILE *data;
    int N,i;
    float a,b,y0,h,t,w;
    float k1,k2,k3,k4; //RK parameter
    N=100; //#step
    a=-2; //integration range [a,b] y(a)=y0
    b=2;
    y0=1; //initial condition
    h=(b-a)/N; //step size
    w=y0;
    t=a;

    data=fopen("ode_rk4_data.dat","w"); //namefile.dat where to write on
    fprintf(data,"#1-t\t2-f(t)");
    fprintf(data,"\n %f\t %f",t,w);
    for (int i = 1; i <= N; i++)
    {
        k1=h*f(t,w);
        k2=h*f(t+h/2,w+k1/2);
        k3=h*f(t+h/2,w+k2/2);
        k4=h*f(t+h,w+k3);
        w=w+(k1+2*k2+2*k3+k4)/6;
        t=a+i*h;  
        fprintf(data,"\n %f\t %f",t,w);     
    }
}

//f(t,y)
float f(float t, float y){
    float result;
    result=2*t;
    return result;
}