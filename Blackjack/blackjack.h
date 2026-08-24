// Blackjack.h
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int playerSetup();

int dealerSetup();

int playerPhase(int playerTotal);

int dealerPhase(int dealerTotal);

void resultCompare(int playerTotal, int dealerTotal, bool playerBust, bool dealerBust);

int playerAce();
