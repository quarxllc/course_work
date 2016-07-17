#include <iostream>

using namespace std;
//better use 5./9.
//must use a float for the temperature!
#define conversion 5/9

/*int temperature_conversion(int temp){

    return (((temp - 32) * 5) / 9);
    
}*/


int temperature_conversion(int temp){

    return (temp - 32) * conversion;
    
}

int main(){


    int to = 40; //initial temperature that is in Farhenhite 

    cout << "The temperature in Farhenheit is: " << to << " The temperature in Celsius is: " << temperature_conversion(to) << endl;

    return 0;


}
