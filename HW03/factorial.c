#include <stdio.h>
#include <math.h>
#include <fenv.h>
#include <iostream>


//original program used the cpp version since it had a better library for
//handling character exceptions
double factorial(double n){

    double result = 1;
    double j = n;

    if (n == 0)
        return 1;

    else if ( n == 1 )
        return 1;

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
    
    double number;

    printf("Input your number including decimal: \n");
    cin >> number;

    while(cin.fail()){
        cout << "Not a number." <<endl;
        cin.clear();
        cin.ignore(256,'\n');
        cout << "Re-enter, the number you would like to factor"<< endl;
        cin >> number;
    }

    printf("%lf",factorial(number));

}
