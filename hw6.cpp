/*
 Joanne Kwon
 February 20, 2017
 Description: write a single-player version of Blackjack (get cards whose total value comes closests to 21 without going over)
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

void draw_card(string &card, int &total) //function for random cards
{
    string suit;
    string rank;
    
    //random numbers
    int card1 = 1+rand()%13;
    int card2 = 1+rand()%4;
    
    //rank output
    if (card1 == 1)
    {
        rank = "  Ace";
        total = 11;
    }
    else if (card1 == 2)
    {
        rank = "  Two";
        total = 2;
    }
    else if (card1 == 3)
    {
        rank = "  Three";
        total = 3;
    }
    else if (card1 == 4)
    {
        rank = "  Four";
        total = 4;
    }
    else if (card1 == 5)
    {
        rank = "  Five";
        total = 5;
    }
    else if (card1 == 6)
    {
        rank = "  Six";
        total = 6;
    }
    else if (card1 == 7)
    {
        rank = "  Seven";
        total = 7;
    }
    else if (card1 == 8)
    {
        rank = "  Eight";
        total = 8;
    }
    else if (card1 == 9)
    {
        rank = "  Nine";
        total = 9;
    }
    else if (card1 == 10)
    {
        rank = "  Ten";
        total = 10;
    }
    else if (card1 == 11)
    {
        rank = "  Jack";
        total = 10;
    }
    else if (card1 == 12)
    {
        rank = "  Queen";
        total = 10;
    }
    else if (card1 == 13)
    {
        rank = "  King";
        total = 10;
    }
    
    //card2 output
    if (card2 == 1)
    {
        suit = "Hearts";
    }
    else if (card2 == 2)
    {
        suit = "Diamonds";
    }
    else if (card2 == 3)
    {
        suit = "Spades";
    }
    else if (card2 == 4)
    {
        suit = "Clubs";
    }
    
    card = rank + " of " + suit;
}

int main()
{
    double bet;
    string response;
    string card_to_draw;
    int O;
    double money = 100;
    
    srand ((int) time (0)); //for random cards
    
    while (money < 1000 && money > 0)
    {
        //make bet
        cout << "You only have $" << money << " to bet. Enter bet: ";
        cin >> bet; //user output for their bet
    
        //maximum bet
        while (bet > money)
        {
            cout << "You only have $" << money << " to bet. Enter bet: ";
            cin >> bet; //user output for their bet
        }
        
        cout << endl;
    
        //PLAYER'S PART
        cout << "Your cards are: " << endl;
    
        int total_value = 0; //total value of player's cards
        int dealer_total_value = 0; //total value of dealer's cards
        
        //drawing random card
        draw_card (card_to_draw, O);
        total_value += O;
        cout << card_to_draw << endl;
    
        //drawing random card
        draw_card (card_to_draw, O);
        total_value += O;
        cout << card_to_draw << endl;
    
        cout << "Your total is " << total_value << ".";
    
        while (total_value < 21) //allows player to repeatedly draw cards as long as their total value is below 21
        {
            cout << " Do you want another card (y/n)? ";
            cin >> response;
            cout << endl;
        
            if (response == "y")
            {
                cout << "You draw a: " << endl;
                
                //drawing random card
                draw_card (card_to_draw, O);
                total_value += O;
                cout << card_to_draw << endl;
            
                cout << "Your total is " << total_value << ".";
            }
            else if (response == "n")
            {
                break;
            }
        }
    
        if (total_value > 21) //player is "busted" when their total balue is greater than 21
        {
            cout <<  " You busted!" << endl;
        }
        cout << endl;
        
        //DEALER'S PART
        cout << "The dealer's cards are:" << endl;
    
        //drawing random card
        draw_card (card_to_draw, O);
        dealer_total_value += O;
        cout << card_to_draw << endl;
    
        //drawing random card
        draw_card (card_to_draw, O);
        dealer_total_value += O;
        cout << card_to_draw << endl;
    
        cout << "The dealer's total is " << dealer_total_value << "." << endl;
        cout << endl;
    
        //allows dealer to repeatedly draw cards until they reach a total value that is less than or equal to 16
        while (dealer_total_value <= 16)
        {
            cout << "The dealer draws a card." << endl;
        
                //drawing random card
                draw_card (card_to_draw, O);
                dealer_total_value += O;
                cout << card_to_draw << endl;
        
            cout << "The dealer's total is " << dealer_total_value << "." << endl;
            cout << endl;
        }
        
        if (dealer_total_value > 21) // dealer is "busted" when their total value is greater than 21
        {
            cout <<  "Dealer busted!" << endl;
        }
    
        
        //SENARIOS
        //player loses (player's total value is over 21)
        if (total_value > 21)
        {
            cout << "Too bad. ";
            money -= bet;
            cout << "You lose $" << bet << "." << endl;
        }
        
        //player wins (player's total value is equal to 21 and the dealer's total value doen't equal 21)
        else if (total_value == 21 && dealer_total_value != 21 )
        {
            cout << "You win $";
            money += bet;
            cout << bet << "!" << endl;
        }
        
        //player wins (dealer's total value is greater than 21 and players total value is less than 21)
        else if (dealer_total_value > 21 && total_value < 21)
        {
            cout << "You win $";
            money += bet;
            cout << bet << "!" << endl;
        }
        
        //player wins (player's total value is greater than the dealer's total value)
        else if (total_value > dealer_total_value)
        {
            cout << "You win $";
            money += bet;
            cout << bet << "!" << endl;
        }
        
        //player loses (player's total value is greater than 21 and the dealer's total is less than 21)
        else if (total_value > 21 && dealer_total_value <= 21)
        {
            cout << "Too bad. ";
            money -=bet;
            cout << "You lose $" << bet << "." << endl;
        }
        
        //player loses (player's total value is greater than 21 and dealer's total value is greater than 21)
        else if (total_value > 21 && dealer_total_value > 21)
        {
            cout << "Too bad. ";
            money -= bet;
            cout << "You lose $" << bet << "." << endl;
        }
        
        //player loses (player's total value is less than the dealer's total value)
        else if (total_value < dealer_total_value)
        {
            cout << "Too bad. ";
            money -= bet;
            cout << "You lose $" << bet << "." << endl;
        }
        
        //player and dealer draws (player's total value is the same as the dealer's total value)
        else if (total_value == dealer_total_value)
        {
            cout << "A draw! You get back your $" << bet << "!" << endl;
        }
        cout << endl;
        
        //OVERALL GAME
        if (money >= 1000) //player wins overall game (player's money is greater than or equal to 1000)
        {
            cout << "You have $" << money << "! YOU WIN!" << endl;
        }
        if (money <= 0) // player loses overall game (player's money is less than or equal to 0)
        {
            cout << "You have $" << money << ". GAME OVER." << endl;
        }
    }
    system ("pause");
    return 0;
}
