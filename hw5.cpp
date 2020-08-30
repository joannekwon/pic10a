/*
Joanne Kwon
February 10, 2017
homework # 5
Description: create an interactive animation program.
*/

#include "ccc_win.h"
#include <string>
#include <time.h>
using namespace std;

void pause(int x)
{
	clock_t goal = x + clock();
	while (goal > clock());
}
void draw_heart(Point center, double scale)
{
	//heart
	Point H1 = center;
	Point H2 = center;
	Point H3 = center;
	Point H4 = center;
	Point H5 = center;
	Point H6 = center;
	Point H7 = center;
	Point H8 = center;

	H1.move(0 * scale, 0.5*scale);
	H2.move(-1 * scale, 1.5*scale);
	H3.move(-2 * scale, 1.5*scale);
	H4.move(-2 * scale, 0.5*scale);
	H5.move(0 * scale, -1.5*scale);
	H6.move(2 * scale, 0.5*scale);
	H7.move(2 * scale, 1.5*scale);
	H8.move(1 * scale, 1.5*scale);

	Line HL1(H1, H2);
	Line HL2(H2, H3);
	Line HL3(H3, H4);
	Line HL4(H4, H5);
	Line HL5(H5, H6);
	Line HL6(H6, H7);
	Line HL7(H7, H8);
	Line HL8(H8, H1);

	cwin << HL1 << HL2 << HL3 << HL4 << HL5 << HL6 << HL7 << HL8;
}

int ccc_win_main()
{
	Point C1;
	Point C2;
	Point C3;


	//user click
	C1 = cwin.get_mouse("Please click anywhere for first point."); //user interaction for first point
	C2 = cwin.get_mouse("Please click anywhere for second point."); //user interaction for second point
	C3 = cwin.get_mouse("Please click anywhere for thrid point."); //user interaction for third point
	cwin << C1 << C2 << C3;


	//making animation loop
	for (int i = 0; i < 50; i++) //this will loop 50 times
	{
		//ground
		Point G1(-10, -7);
		Point G2(10, -7);
		Line GL1(G1, G2);
		cwin << GL1;

		//face 1
		Point Q1(3, 2);
		Point E1(2, 2);
		Point E2(3.5, 2);
		Point M2(2.6, 1);
		Circle MM2(M2, 0.5);
		Circle F1(Q1, 2.0);
		cwin << F1;
		cwin << E1 << E2 << MM2;

		//face 2
		Point Q2(-3, 2);
		Point E3(-2, 2);
		Point E4(-3.5, 2);
		Point M1(-2.6, 1);
		Circle MM1(M1, 0.5);
		Circle F2(Q2, 2);
		cwin << F2;
		cwin << E3 << E4 << MM1;

		//body 
		Point B3(3, 0);
		Point B4(3, -4);
		Point B1(-3, 0); //body 2
		Point B2(-3, -4); //body 2
		Line BL2(B3, B4);
		Line BL1(B1, B2); //body 2
		cwin << BL1 << BL2;

		//arms 
		Point A1(3, -1);
		Point A2(6, -3);
		Point A3(0, -3);
		Point A4(-3, -1); //arm 2
		Point A5(-6, -3); //arm 2
		Line AL1(A1, A2);
		Line AL2(A1, A3);
		Line AL3(A4, A5); //arm 2
		Line AL4(A4, A3); //arm 2
		cwin << AL1 << AL2 << AL3 << AL4;

		//legs 
		Point K1(3, -4);
		Point K2(5, -7);
		Point K3(1, -7);
		Point K4(-3, -4); //leg 2
		Point K5(-1, -7); //leg 2
		Point K6(-5, -7); //leg 2
		Line KL1(K1, K2);
		Line KL2(K1, K3);
		Line KL3(K4, K5); //leg 2
		Line KL4(K4, K6); //leg 2
		cwin << KL1 << KL2 << KL3 << KL4;

		//hearts
		draw_heart(C1, 0.1*i);
		draw_heart(C2, 0.1*i);
		draw_heart(C3, 0.1*i);
		pause(60);
		cwin.clear();
		C1.move(-0.5, 1);
		C2.move(0.5, -0.5);
		C3.move(0.5, 0.5);

	}
	return 0;
}