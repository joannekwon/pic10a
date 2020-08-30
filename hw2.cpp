/*
Joanne Kwon
ID: 404654094
Date: January 23, 2017
Homework 2
Description: This code allows the user to input time traveled in seconds and miles per hour to calclulate the total years, hours, minutes, and seconds traveled. Additionally, the code is able to calcualte the total distance traveled.
*/

#include <iostream>
using namespace std;
int main()
{
	int travel_in_seconds; //user input
	int miles_per_hour; //user input
	int year; //total years
	int days; //total days
	int hours; //total hours
	int minutes; //total minutes
	double distance; //total distance
	int second_remain_year; //remaining seconds after year
	int second_remain_day; //remaning seconds after day
	int second_remain_hours; //remaining seconds after hour
	int second_remain_minutes; // remaining seconds after minutes
	const int seconds_per_year = 31556952;
	const int seconds_per_day = 86400;
	const int seconds_per_hour = 3600;
	const int seconds_per_minute = 60;
	double sp = 3600; //seconds per hour (double)


	cout << "Please input your time of travel in seconds. " << endl;
	cin >> travel_in_seconds; //input from the user

	cout << "Please input your speed in miles per hour. "<< endl;
	cin >> miles_per_hour; //input from the user


	year = (travel_in_seconds / seconds_per_year);  //answer for number of years traveled
	second_remain_year = (travel_in_seconds % seconds_per_year); //remaining seconds

	days = (second_remain_year / seconds_per_day);//answer for number of days traveled
	second_remain_day = (second_remain_year % seconds_per_day); //remaining seconds

	hours = (second_remain_day / seconds_per_hour);  //answer for number of hours traveled
	second_remain_hours = (second_remain_year % seconds_per_hour); //remaining seconds

	minutes = (second_remain_hours / seconds_per_minute); // answer for number of minutes traveled
	second_remain_minutes = (second_remain_hours % seconds_per_minute); //remaining seconds

	second_remain_minutes; //answer for number of seconds

	cout << "You have been traveling for: " << year << " year " << days << " days " << hours << " hours " << minutes << " minutes " << second_remain_minutes << " seconds." << endl;

	distance = ((travel_in_seconds / sp) * miles_per_hour);  //calculation for total distance travleded
	cout << "Your distance traveled is: " << distance << " miles." << endl;

	system("pause");
	return 0;
}
