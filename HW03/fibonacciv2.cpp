/* Version Number 2, with dynamically allocated memory to handle any amount of
 * numbers if necessary*/


#include <iostream>
#include <stdlib.h>

using namespace std;

long int fibonacci(long int n){
   
    if (n == 0)
        return 0;

    else if (n == 1)
        return 1;
    
    else 
        return (fibonacci(n-1) + fibonacci(n-2));
}




int main(void){
    
    long int n,*ptr = NULL,sum;
    
    cout << "Enter the number of elements: " << endl;
    cin >> n;


    ptr = (long int*)malloc(n * sizeof(long int)); //dynamically memory allocated using malloc

    if ( ptr == NULL ){

        cout << "Memory not allocated" << endl;
        exit(0);
    }

    


   /* cout << "How many fibonacci numbers would you like (20 max)?: " <<endl;
    cin >> n;*/


     while(cin.fail()){
        cout << "Not an interger" << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cout << "How many fibonacci numbers would you like?: " <<endl;
        cin >> n;
            }


        for(int i = 0; i < n; i++){
            

            *ptr = fibonacci(i);
            cout << *ptr << endl;
        
        }
        
        free(ptr);
        return 0;
    }

   
