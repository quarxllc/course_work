#include <iostream>
#include <stdlib.h>

using namespace std;

void find_min_max(float list[], int size, float *min, float *max){

    int i = 0;

    float smallest,largest;

    for (i = 0; i < size; i++){

        cin >> list[i];

        while(cin.fail()){
        

            cout << "Not a number" << endl;
            cin.clear();
            cin.ignore(256,'\n');
            cout << "Please enter your number now: " << endl;

        }


    }

    smallest = list[0];

    for (i = 0; i < size; i++){

        if (list[i] < smallest){
            
            smallest = list[i];
        }

    }

    *min = smallest;

    largest = list[0];

    for (i = 0; i < size; i++){
        
        if(list[i] > largest){

            largest = list[i];
        }
    }

    *max = largest;


}

int main(void){

    long int size;
    float min,max;
    float *list = NULL;

    cout << "Enter how many numbers you would like in the list: " <<endl;
    cin >> size;

    list = (float*)malloc(size * sizeof(float));

    while(cin.fail() || list == NULL || size == 0){
        
        cout << "Not a numberi, your list is not allocated or the size of your array is zero" << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cout << "Please re-enter your size of the array: " << endl;
        cin >> size;
        }

    cout << "Enter your numbers now: "<< endl;


    find_min_max(list, size, &min, &max);
    
    cout << "Your minimum is: " << min << endl;
    cout << "Your maximum is: " << max << endl;


}
