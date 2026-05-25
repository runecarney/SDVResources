#include <iostream>

using namespace std;

/*
This program is based off of the information on the Stardew Valley wiki for the wheel minigame in the Stardew Valley fair.
https://stardewvalleywiki.com/Stardew_Valley_Fair
  
At the Spinning Wheel, the player can bet Star Tokens on whether the spinner will land on green or orange.
With no Luck modifiers, the Wheel is always 2.75 times more likely to land on Green than Orange (73.3% chance of Green vs 26.6% chance of Orange).
The results of previous spins never affect the results of subsequent spins.
For maximum expected profit while protecting against losses, the player should always bet 46.7% of their current stars on Green.
By taking advantage of this, players can quickly earn the star tokens required to purchase all items in the shop.

Luck modifiers affect the results of spins by changing the speed of the spinner.
When the spinner falls below a certain speed, if it would cause the spinner to land on the losing color, 
there is a chance for it to set its speed to a higher speed, proportional to the player's Luck.
This chance is equal to Luck / 15 if the player chose Green, or Luck / 20 if the player chose Orange.
As the player cannot eat or drink in the festival (other than Gus's Survival Burgers), 
the player would need to use any Luck-improving consumables before entering the festival in order to maximize the chance of winning. 
*/
int currentCoins = 0;
int currentBet = 0;
char result = ' ';

int FindNewBet(int coins)
{
    return (coins*46.7)/100;
}

void winBet(int &coins, int bet)
{
    coins += bet;
}

void loseBet(int& coins, int bet)
{
    coins -= bet;
}

int main()
{
    cout << "Initial amount of star coins: ";

    cin >> currentCoins;
    while (currentCoins < 9999) 
    {


        cout << "\nNew Bet: ";
        currentBet = FindNewBet(currentCoins);
        cout << currentBet << endl;

        cout << "\nDid you win or lose: ";
        cin >> result;

        switch (result)
        {
        default:
            break;
        case 'l':
        case 'L':
            loseBet(currentCoins, currentBet);
            break;
        case 'w':
        case 'W':
            winBet(currentCoins, currentBet);
            break;

        }
    }
}
