#include <iostream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

// double vectors_two_dimensional(double x, double y, double &result, double &angle);
// {
//   result = sqrt(x*x + y*y);
//   angle = atan2(y,x);
// }
//
double vectors_two_dimensional(double x, double y, double *result, double *angle){


    *result = sqrt(x*x + y*y);

    *angle = atan2(y,x);

}

double vectors_three_dimensional(double *x, double *y, double *z, double *result, double *angle_x_y,double *angle_y_z, double *angle_z_x){


    *result = sqrt(((*x)*(*x)*(*x))+(*y)*(*y)*(*y)+(*z)*(*z)*(*z));
    
    *angle_x_y = atan2(*y,*x);
    *angle_y_z = atan2(*z,*y);
    *angle_z_x = atan2(*x,*z);

}


int main(int argc, const char *argv[])
{
    
    double x,y,z,result,angle, angle2, angle3;
    int vector;

    cout << "My name is " << argv[0] << endl;
    int nvec;

    if (argc > 1) {
      vector = atoi(argv[1]);
    } else {
    cout << "For two dimensional vector type in 1" << endl;
    cout << "For three dimensional type in 2" << endl;
    cout << "To exit the program type 3" << endl;
    cin >> vector;
}
   
    while ( vector < 1 || vector > 3) {

        cout << "Wrong input." << endl;
        cin.clear();
        cout << " Please try again" << endl;
    cin >> vector;
    }

    // Can we take a look at this section of code in class, not able to do a
    // check for the entry, however, switch cases do work. 

    switch(vector){
        

        case 1:

            cout << "Enter your x and then your y coordinate: " << endl;
            cin >> x;

    

    
    
            while(cin.fail()){

                cout << "Not a number." << endl;
                cin.clear();
                cin.ignore(256,'\n');
                cout << "This is not a valid entry" <<endl;
                cin >> x;
            }
            
        
            cin >> y;
        
            while(cin.fail()){
        
                cout << "Not a number." << endl;
                cin.clear();
                cin.ignore(256,'\n');
                cout << "This is not a valid entry" <<endl;
                cin >> y;
            }
            
        
        
            vectors_two_dimensional(x, y, &result, &angle);  
            
            printf("Result: %lf \n", result);
            printf("Angle: %lf \n", angle);
     
                break;

        
        case 2:

            cout << "Enter your x, y, and z coordinates: " << endl;
            cin >> x;
   
            while(cin.fail()){

                cout << "Not a number." << endl;
                cin.clear();
                cin.ignore(256,'\n');
                cout << "This is not a valid entry" <<endl;
                cin >> x;
            }
            
        
            cin >> y;
        
            while(cin.fail()){
        
                cout << "Not a number." << endl;
                cin.clear();
                cin.ignore(256,'\n');
                cout << "This is not a valid entry" <<endl;
                cin >> y;
            }

            cin >> z;
   
            while(cin.fail()){

                cout << "Not a number." << endl;
                cin.clear();
                cin.ignore(256,'\n');
                cout << "This is not a valid entry" <<endl;
                cin >> z;
            }
 
        
        
            vectors_three_dimensional(&x, &y, &z, &result, &angle, &angle2, &angle3);  
            
            printf("Result: %lf \n", result);
            printf("Angle x and y coordinate: %lf \n", angle);
            printf("Angle y and z coordinate: %lf \n", angle2);
            printf("Angle z and x coordinate: %lf \n", angle3);
            
                break;

        case '3':
                cout << "Goodbye" << endl;
                break;

        }
    return 0;
}
