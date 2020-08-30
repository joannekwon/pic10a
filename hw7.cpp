/*

Joanne Kwon

March 1, 2017

Description: design a group of houses on a street with house numbers and point location. Add a chimney and smoke for extra credit.

*/

#include "ccc_win.h"
#include <string>
#include <iostream>

using namespace std;

class House
{

	public:

		House();
		House(int num, Point center);
		int getHouseNumber();
		double getX();
		double getY();
		void draw_house();

	private:

		int houseNum;
		Point houseCenter;

};

//created default constructor
House::House()
{
	
}

House::House(int num, Point center)

{
	houseNum = num;
	houseCenter = center;
}

double House::getX() {

	return houseCenter.get_x();

}

double House::getY() {

	return houseCenter.get_y();
}

int House::getHouseNumber()
{
	return houseNum;
}


void House::draw_house()

{
	//house

	Point H1 = houseCenter;
	Point H2 = houseCenter;
	Point H3 = houseCenter;
	Point H4 = houseCenter;
	Point H5 = houseCenter;
	Point MD = houseCenter;

	H1.move(-1, 1);
	H2.move(-1, -1);
	H3.move(1, -1);
	H4.move(1, 1);
	H5.move(0, 2);

	Line HL1(H1, H2);
	Line HL2(H2, H3);
	Line HL3(H3, H4);
	Line HL4(H4, H1);
	Line roofL(H1, H5);
	Line roofR(H4, H5);
	Message M(MD, houseNum);

	cwin << M<< HL1 << HL2 << HL3 << HL4 << roofL << roofR ;

}

class Street

{

	public:

		Street(House first, House last, int num_houses);
		void plot_house();

	private:

		House firstHouse;
		House lastHouse;
		int houseNumber;

};

Street::Street(House first, House last, int num_houses)
{
	firstHouse = first;
	lastHouse = last;
	houseNumber = num_houses;
}

void Street::plot_house() {

	//getting the x and y coordinates of each house
	double xFirst = firstHouse.getX();
	double yFirst = firstHouse.getY();
	double xLast = lastHouse.getX();
	double yLast = lastHouse.getY();

	//calculating the spaces between the houses
	double xIncrement = ((xLast-xFirst)/(houseNumber-1));
	double yIncrement = ((yLast - yFirst) / (houseNumber -1));

	//drawing the first and last house
	firstHouse.draw_house();
	lastHouse.draw_house();
	
	//getting access to the house addresses of each house
	double houseAddress1 = firstHouse.getHouseNumber();
	double houseAddress2 = lastHouse.getHouseNumber();
	double houseAddIncre = 0;

	//creating a point variable with point value of the first house
	Point firstPoint(firstHouse.getX(), firstHouse.getY());


	//if the first house address is smaller than last
	if (houseAddress1 < houseAddress2) {
		for (int i = 0; i < houseNumber - 2; i++) {

			//moving the point variable
			firstPoint.move(xIncrement, yIncrement);

			//calculating the new house address
			(double)houseAddIncre = (((double)(houseAddress2 - houseAddress1)) / ((double)(houseNumber)));
			(double)houseAddress1 += (double)houseAddIncre;

			//creating house and drawing it
			House between(houseAddress1, firstPoint);
			between.draw_house();

		}
	}


	//if the last house address is greater than the first, everything else same as above
	else {
		for (int i = 0; i < houseNumber - 2; i++) {

			firstPoint.move(xIncrement, yIncrement);

			(double)houseAddIncre = (double)(houseAddress2 - houseAddress1) / (double)(houseNumber);
			(double)houseAddress2 -= (double)houseAddIncre;

			House between(houseAddress2, firstPoint);
			between.draw_house();
		}
	}
}







int ccc_win_main()

{

	//will keep on playing until you say no
	bool cont = true;
	while (cont == true) {

		//getting the house address of first house
		double h_address1 = cwin.get_int("Please enter the address of the first house: ");
		//getting the Point location for the houses
		Point first = cwin.get_mouse("Click on the first house location."); 
		//drawing a circle on the first click
		cwin << first;
		//creating first house variable
		House firstHouse(h_address1, first);

		//everything same as above
		double h_address2 = cwin.get_int("Please enter the address of the last house: ");
		//getting the Point location for the houses
		Point last = cwin.get_mouse("Click on the last house location.");
		cwin << last;
		House lastHouse(h_address2, last);
		int numHouse = cwin.get_int("Please enter the number of houses in the street: ");

		//creating street variable
		Street street1(firstHouse, lastHouse, numHouse);
		//drawing street
		street1.plot_house();

		//option
		string answer = cwin.get_string("Would you like to draw another street?  (y/n)");
		if (answer == "n")
		{
				cont = false;
		}
	}



	return 0;

}


