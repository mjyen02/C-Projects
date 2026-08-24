#include <iostream>
#include <iomanip>
#include <cmath>
#include "Blackjack.h"
using namespace std;

int main()
{
    while (true)
    {
        bool playerBust = false;
        bool dealerBust = false;
        int dealerTotal;
        int playerTotal;
        
        srand(time(0));
        
        int startPlayerTotal = playerSetup();
        int startDealerTotal = dealerSetup();
        
        cout << "\nYour Starting Total: " << startPlayerTotal << endl;
        
        playerTotal = playerPhase(startPlayerTotal);
        if (playerTotal > 21)
        {
            dealerTotal = startDealerTotal;
            playerBust = true;
        }
        
        if (playerBust == false)
        {
            dealerTotal = dealerPhase(startDealerTotal);
            if (dealerTotal > 21)
            {
                dealerBust = true;
            }
        }
        
        resultCompare(playerTotal, dealerTotal, playerBust, dealerBust);
        
        cout << "Play another round? Yes (1) or No (Any Other Key)?";
        int rematch;
        cin >> rematch;
        
        if (rematch == 1)
        {
            cout << endl;
        }
        else
        {
            break;
        }
    }   
    return 0;
}