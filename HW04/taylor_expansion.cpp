#include <stdio.h>
#include <math.h>
#include <fenv.h>
#include <iostream>

using namespace std;

double factorial(double n){

    double result = 1;

    if (n == 0)
         result = 1;

    else if ( n == 1 )
         result =  1;

    else if ( fmod (n, 1) != 0 ){
    
        result = tgamma(n);    
    }

    else{
        
        while( n  > 1){
            result = result * n;
            n--;
    
        }
    }

    return result;
}


int main(void){
    
    double x = 0;
    double sum = 0, sum2 = 0;
    int n;

    cout << "Input x to be evaluated for cos(x) - Taylor Expansion: " << endl;
    cin >> x;

    
    while(cin.fail()){
        cout << "Not a number." <<endl;
        cin.clear();
        cin.ignore(256,'\n');
        cout << "Re-enter, the number you would like to factor"<< endl;
        cin >> x;
    }

    printf("How many digits would you like: \n");
    cin >> n;
    
    
    while(cin.fail()){
        cout << "Not a number." <<endl;
        cin.clear();
        cin.ignore(256,'\n');
        cout << "Re-enter, the number you would like to factor"<< endl;
        cin >> n;
    }

    for (int i = 0; i < n; i++){
        
        sum = sum + (pow(-1,i) * pow(x,2*i))/(factorial(2*i));
        //cout << sum << endl;
    }

    sum2 = cos(x);

    cout << "The actual value: " << sum2 << endl;
    cout << "Taylor expansion value: " << sum << endl;
    
    sum2 = (fabs(sum2 - sum)/sum2) * 100;
    
    cout << "Percent error: " << sum2 <<endl;


}


    
