/*
 Joanne Kwon
 PIC 10A
 February 4, 2017
 Description: Create a tic-tac-toe game that allows the 2 players to take turns and make their moves until the all 9 tic-tac-toe boxes are full.
*/


#include <iostream>
#include "ccc_x11.h"
#include "ccc_shap.h"
#include "ccc_win.h"
int ccc_win_main()

{
    int i;
    string response;
    
    //beginning of game response
    cout << "Do you want to play? [y/n]";
    cin >> response;
    while (response == "y" || response == "n")
        
    //lines for the tic-tac-toe game
    cwin << Line(Point(2.5, 7.5), Point(2.5, -7.5));
    cwin << Line(Point(-2.5, 7.5), Point(-2.5, -7.5));
    cwin << Line(Point(-7.5, 2.5), Point(7.5, 2.5));
    cwin << Line(Point(-7.5, 2.5), Point(7.5, -2.5));
    
    //making game loop for X and O
    for (int i = 0; i < 9; i++) //this will loop 9 times
            cout << "X";
    if (i % 2 == 1) { //if i is odd then X
        
    //player 1 clicks for X
    //forming points to make X
    Point P = cwin.get_mouse ("Click to place X");
    Point P2 (P.get_x()+2, P.get_y()-2);
    Point P3 (P.get_x()+2, P.get_y()+2);
    Point P4 (P.get_x()-2, P.get_y()-2);
    Point P5 (P.get_x()-2, P.get_y()+2);
        
    //forming lines to make X
    Line L1(P5,P2);
    Line L2(P4,P3);
        
    cwin << L1 << L2; //X
        
    }
        else {
            cout << "O"; //if i is even then O
            
    //player 2 clicks for O
    Point P1;
    P1 = cwin.get_mouse ("Click to place O");
    Circle C1 (P1, 2.5);
    cwin << C1;
 
    }

    //end of game response
    response = cwin.get_string("Game Over. Play again [y/n]?");
    cin >> response;
    while (response == "y" || response == "n");
    
    cwin.clear(); //erases the screen
    int c_win_main();
    
        return 0;
}



