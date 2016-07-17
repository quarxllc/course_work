#include <math.h>
#include <stdio.h>
#include <iostream>
#include "integral.h"
#include <string.h>
#include <stdlib.h>

#define PI 3.14159265

using namespace std;

int main(int argc, char *arv[]){

    int choice,input,i;
    double minimum, maximum, max, min, sum, *iterations;
    double (*ptr)(double);
    const char *name_of_function;

    FILE *f = fopen("result.txt","w");
    
    if (f == NULL){

        cout << "Error Opening File!" << endl;
        return 1;
    }


    double (*function_ptr[])(double) = {&sine, &cosine, &x_squared, &tangent}; //inserting functions into the pointers

    cout << "Enter choice for " << endl;
    cout << "0: for sine" << endl;
    cout << "1: for cosine" << endl;
    cout << "2: for x_squared" << endl;
    cout << "3: for tangent" << endl;
    cin >> choice;

    while(cin.fail()){

        cout << "Invalid Entry." << endl;
        cin.clear();
        cin.ignore(256,'\n');

        cout << "Enter choice for " << endl;
        cout << "0: for sine" << endl;
        cout << "1: for cosine" << endl;
        cout << "2: for x_squared" << endl;
        cout << "3: for tangent" << endl;
        cin >> choice;
    }

    switch (choice){

        case 0:
            ptr = function_ptr[choice];
            name_of_function = "Sine";
            break;

        case 1:

            ptr = function_ptr[choice];
            name_of_function = "Cosine";
            break;

        case 2: 

            ptr = function_ptr[choice];
            name_of_function = "x^2";
            break;
        
        case 3: 

            ptr = function_ptr[choice];
            name_of_function = "Tangent";
            break;


        default:
            cout << "You have entered the wrong input" <<endl;
            return 1; 
   }

    cout << "How many different iterations would you like: " << endl;
    
    cin >> input;


    while(input == 0 || cin.fail()){
        cout << "Your number has to be greater than 0" << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cin >> input;
    }

    iterations = (double*)malloc(input * sizeof(double));


    cout << "How many iterations you would like: " << endl;
    
    for(i = 0; i < input; i++){
        
        cout << "Press enter after each iteration enetered: " << endl;
        cin >> iterations[i];

        while (iterations[i] == 0){
            cout << "Not a valid entry." << endl;
            cin.clear();
            cin.ignore(256,'\n');
            cin >> iterations[i];
        }
    }

        
    cout << "Enter your min: " <<endl;
    cin >> minimum;

    cout << "Enter your max: " << endl;
    cin >> maximum;

    if(minimum > maximum){
        
        max = minimum;
        min = maximum;
        maximum = max;
        minimum = min;


    }
 

    for ( i = 0; i < input; i++){

    sum = rectangle_method(ptr, minimum, maximum, iterations[i]);

    fprintf(f, "The Rectangle Method for %s of %lf iterations: %lf \n", name_of_function, iterations[i], sum);

    sum = midpoint_method(ptr, minimum, maximum, iterations[i]);

    fprintf(f, "The Midpoint Method for %s of %lf iterations: %lf \n", name_of_function, iterations[i], sum);

    sum = trapezoid_method(ptr, minimum, maximum, iterations[i]);

    fprintf(f, "The Trapezoid Method for %s of %lf iterations: %lf \n", name_of_function, iterations [i], sum);


    }

    
    fclose(f);
    return 0;

}
