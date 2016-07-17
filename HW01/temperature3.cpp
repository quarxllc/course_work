#include <iostream>

using namespace std;

#define conversion 5/9

/*int temperature_conversion(int temp){

    return (((temp - 32) * 5) / 9);
    
}*/


float temperature_conversion(float temp){

    return (temp - 32) * conversion;
    
}

int main(){


    float to; //initial temperature that is in Farhenhite 

    cout << "This program converts Farhenhite to Celcius" << endl
       << "Enter a value in degrees Farhenhite to convert: "<< endl;

    cin >> to;

    cout << "The temperature in Farhenheit is: " << to << " The temperature in Celsius is: " << temperature_conversion(to) << endl;

    return 0;


}
