// Blackjack.cpp
#include <iostream>
#include <iomanip>
#include <cmath>
#include "Blackjack.h"
using namespace std;

int playerSetup()
{
    int total = 0;
    
    for (int i = 0; i < 2; i++)
    {
        int card = rand() % 10 + 1;
        
        if (card == 1)
        {
            card = playerAce();
        }
        
        cout << "Player Card Value: " << card << endl;
        
        total += card;
    }
    return total;
}

int dealerSetup()
{
    int total = 0;
    int card1 = rand() % 10 + 1;
    int card2 = rand() % 10 + 1;
    int hand = rand() % 2 + 1;
    
    if (card1 == 1)
    {
        card1 = 11;
    }
    
    if (hand == 1)
    {
        cout << "One Dealer Face Up Card Value: " << card1 << endl;
    }
    else
    {
        cout << "One Dealer Face Up Card Value: " << card2 << endl;
    }
    
    total = card1 + card2;
    return total;
}

int playerPhase(int playerTotal)
{
    int playerCard;
    int hitOrstand;

    while (true)
    {
        if (playerTotal == 21)
            {
                cout << "Blackjack!" << endl << endl;
                break;
            }
        
        cout << "Would you like hit (1) or (2) stand? ";
        cin >> hitOrstand;
        
        playerCard = rand() % 10 + 1;
        
        if (hitOrstand == 1)
        {
            if (playerCard == 1)
            {
                if (playerTotal > 10)
                {
                    playerCard = 1;
                }
                else
                {
                    playerCard = playerAce();
                }
            }
            
            playerTotal += playerCard;
            cout << "Card Drawn: " << playerCard << " points" << endl;
            cout << "New Total: " << playerTotal << " points" << endl << endl;
            
            if (playerTotal > 21)
            {
                cout << "The Player has busted" << endl;
                break;
            }
            
        }
        else if (hitOrstand == 2)
        {
            cout << "Final Total: " << playerTotal << endl << endl;
            break;
        }
        else
        {
            cout << "Invalid Choice, try again." << endl;
        }
    }
    return playerTotal;
}

int dealerPhase(int dealerTotal)
{
    while (true)
    {
        if (dealerTotal <= 16)
        {
            cout << "The dealer draws a card..." << endl;
            dealerTotal += rand() % 10 + 1;
        }
        else if (dealerTotal >= 17)
        {
            cout << "The dealer does not draw any more cards..." << endl;
            break;
        }
    }
    return dealerTotal;
}

void resultCompare(int playerTotal, int dealerTotal, bool playerBust, bool dealerBust)
{
    int playerDiff = 21 - playerTotal;
    int dealerDiff = 21 - dealerTotal;
    
    cout << "Player Total: " << playerTotal << endl << "Dealer Total: " << dealerTotal << endl;
    
    if (playerBust == true)
    {
        cout << "The House Wins, better luck next time." << endl << endl;
    }
    
    if (dealerBust == true)
    {
        cout << "The player wins, great job." << endl << endl;
    }
    
    if (playerBust == false && dealerBust == false)
    {
        if (playerDiff < dealerDiff)
        {
            cout << "The player wins, great job." << endl << endl;
        }
        else if (playerDiff == dealerDiff)
        {
            cout << "Tied Round, even split." << endl << endl;
        }
        else
        {
            cout << "The House wins, better luck next time." << endl << endl;    
        }
    }
}

int playerAce()
{
    int aceResult;
    while (true)
    {
        cout << "Would you like your Ace to be 1 Point (1) or 11 Points (2)? ";
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            aceResult = 1;
            cout << "Card is now worth 1 point" << endl;
            break;
        }
        else if (choice == 2)
        {
            aceResult = 11;
            cout << "Card is now worth 11 points" << endl;
            break; 
        }
        else
        {
            cout << "Invalid Choice, try again." << endl;
        }
    }
    return aceResult;
}
