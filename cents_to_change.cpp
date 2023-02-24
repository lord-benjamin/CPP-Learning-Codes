/*
    write a program that asks the user to enter the following
    An integer representing the number of cents

    You may assume that the number of cents entered is greater than or equal to zero

    The program should then display how to provide that change to the user

    In the US:
        1 dollar is 100 cents
        1 quarter is 25 cents
        1 dime is 10 cents
        1 nickel is 5 cents
        1 penny is 1 cent
    
    Sample:

    Enter an amount in cents: 92

    You can provide this change as follows:
    dollars: 0
    quarters: 3
    dimes: 1
    nickels: 1
    penny: 2
*/

#include <iostream>
using namespace std;

int main()
{
    int cents{};
    cout << "Enter an amount in cents: ";
    cin >> cents;

    int dollars{};
    const int cents_per_dollar{100};
    dollars = cents / cents_per_dollar;
    cents -= dollars * cents_per_dollar;

    int quarters{};
    const int cents_per_quarter{25};
    quarters = cents / cents_per_quarter;
    cents -= quarters * cents_per_quarter;

    int dimes{};
    const int cents_per_dime{10};
    dimes = cents / cents_per_dime;
    cents -= dimes * cents_per_dime;

    int nickels{};
    const int cents_per_nickel{5};
    nickels = cents / cents_per_nickel;
    cents -= nickels * cents_per_nickel;

    int pennies{};
    const int cents_per_penny{1};
    pennies = cents / cents_per_penny;
    cents -= pennies * cents_per_penny;

    cout << "You can provide this change as follows:" << endl;
    cout << "dollars  : " << dollars << endl;
    cout << "quarters : " << quarters << endl;
    cout << "dimes    : " << dimes << endl;
    cout << "nickels  : " << nickels << endl;
    cout << "pennies  : " << pennies << endl;

    return 0;

}