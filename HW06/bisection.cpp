#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <cstdio>


using namespace std;


float f(float x){
    
    float result;
    result=x - sin(x) - 4;
    return result;
    
}

void bisection (float *x, float a, float b){
    *x=(a+b)/2;
    
    cout<<"x= "<< *x<<endl;
}



int main(int argc, char **argv){
    
    float a, b;
    float eps;
    float itr=0;
    float maxitr;
    float x, x1;
    
    
    cout<<"Enter lower bound "<<endl;
    cin>>a;
    
    cout<<"Enter upper bound "<<endl;
    cin>>b;
    
    cout<<"Enter accuracy "<<endl;
    cin>>eps;
    
    cout<<"Enter max itterations "<<endl;
    cin>>maxitr;
    
    bisection (&x, a, b);
    
    for (itr=0;itr<maxitr;itr++){
    
    if (f(a)*f(x)<0){
        b=x;
    }
    
    else{
        a=x;
    }
    
    bisection (&x1, a, b);
    
    if (fabs(x1-x) < eps){
        cout<<"After "<<itr<<" iterations , root= "<< x1<< endl;
        return 0;
    }
    
    x=x1;
    
    }
    
}
