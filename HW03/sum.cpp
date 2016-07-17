#include <iostream>
#include <math.h>

using namespace std;

int sum_of_three(int number){
        
        //number = round(number);
		int numbersum = 0;
		
		do{
		    
            //cout << number << endl;
            //cout << numbersum << endl;

			numbersum = numbersum + number % 10;
			number = number / 10;

        }while(number%10 != 0 );

			return numbersum;
}




int main(){

	int number;
    cout << "Please enter a number to sum" << endl;
	cin >> number;

    while(cin.fail()){
        cout << "Not an interger" << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cout << "Please re-eneter your value: " <<endl;
        cin >> number;
            }

	cout << sum_of_three(number) <<endl;
}
