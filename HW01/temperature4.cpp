#include <iostream>
#include <math.h>
using namespace std;

#define conversion 5/9

/*int temperature_conversion(int temp){

    return (((temp - 32) * 5) / 9);
    
}*/


double FtoC(double temp){

    return (temp  - 32) * conversion;
    
}

double CtoF(double temp){

    return ((temp)* 9/5) + 32;
}

double CtoK(double  temp){

    return (temp) + 273.15;

}

double KtoC(double temp){

    return (temp) - 273.15;
}

double KtoF(double temp){

    return ((temp) - 273.15) * conversion + 32; 
}

int main(){
    
    char temperature;
    double to; //initial temperature that is in Farhenhite 
    int x = 1;

    while(x != 0){
         cout << "To convert from Celcius to Farhenhite type, 'C'"<< endl
             << "To convert from Farhenhite to Celcius type, 'F'"<<endl
             << "To convert from Farhenhite to Kelvin, or Celcius to Kelvin type 'A'"<< endl
             << "To convert from Kelvin to Farhenheit and Celcius type, 'K'" << endl
             << "To exit the program at any point hold Ctrl + C" << endl;
         cin >> temperature;

         switch(temperature){

             case 'C':
                 
                 cout << "Enter a temperature in Celcius: " <<endl;
                 cin >> to;
                 cout << "The temperature in Farhenhite is: " << CtoF(to) <<endl;
                 break;

             case 'F':
                
                 cout << "Enter a temperature in Farhenhite: " <<endl;
                 cin >> to;
                 cout << "The temperature in Celcius is: " <<  FtoC(to) <<endl;
                 break;

             case 'A':
               
                 cout << "Are you converting from, Celcius to Kelvin? Type 'C'" << endl
                      << "Are you converting from, Farhenhite to Kelvin? Type 'F'"<< endl;
                 cin >> temperature;

                 switch(temperature){

                     case 'F':

                         cout << "Enter a temperature in Farhenhite: " <<endl;
                         cin >> to;
                         cout << "The temperature in Kelvin is: " << CtoK(FtoC(to)) <<endl;
                         break;
                     case 'C':

                         cout << "Enter a temperature in Celcius: " <<endl;
                         cin >> to;
                         cout << "The temperature in Kelvin is: " << CtoK(to) <<endl;
                         break;
                 }
                 break;
             case 'K':


                 cout << "Type in a temperature in Kelvin: " << endl;
                 cin >> to;
                 cout << "The temperature in Celcius is: " << KtoC(to) <<endl
                      << "The temperature in Farhenheit is: " << KtoF(to) <<endl;
                 break;    
                     

             
                 
            
    }

    }
    return 0;


}
