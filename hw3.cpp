/* 
Joanne Kwon
January 27, 2017
Description: calculate the ratio between two quanitites
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	
	string object_one, object_two; //objects inputted by the user
	double number_one, number_two; //number inputted by the user
	double ratio_one; //ratio between quanitites
	double ratio_two; //ratio between quantities

	cout << "How many in the first category? ";
	cin >> number_one >> object_one; //user input

	cout << "How many in the second category? ";
	cin >> number_two >> object_two; //user input

	int space = object_one.length() + object_two.length();

	cout << setw(space + 8) << object_one << " " << setw(10) << number_one << endl;
	cout << setw(space + 8) << object_two << " " << setw(10) << number_two << endl;

	ratio_one = (number_one / number_two); //ratio of object one to object two
	cout << fixed;
	cout << setprecision(2); //two decimal places
	
	object_one.erase(object_one.length() - 1, object_one.length()); //plural to singular
	object_two.erase(object_two.length() - 1, object_two.length()); //plural to singular

	cout << setw(space) << object_one + "-to-" + object_two + " ratio" << " " << setw(10) << ratio_one << endl; 

	ratio_two = (number_two / number_one); //ratio of object two to object one
	cout << setprecision(2); // two decimal places
	cout << setw(space) << object_two + "-to-" + object_one + " ratio" << " " << setw(10) << ratio_two << endl; 

	system("pause");
	return 0;

}