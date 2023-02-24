/*
   Frank's Carpet Cleaning Service
   Charges $30 per room
   Sales tax rate id 60%
   Estimates are valid for 30 days

   Prompt the user for the numbers of rooms they would like cleaned
   and provide an estimate such as:

   Estimate for carpet cleaning service:
   Number of rooms: 2
   Price per room: $30
   Cost: $60
   Tax: $3.60
   ===========================================================
   Total estimate: $63.6
   This estimate is valid for 30 days
   
Pseudocode:
   Prompt the user to enter the number of rooms
   Display number od rooms
   Diplay price per room

   Display cost:(number of rooms*price per room)
   Display tax: number of rooms*price per room*tax rate
   Display total estimate:(number of rooms*price per room)+(number of rooms*price oer room*tax rate)
   Display estimate expiration time
*/

#include <iostream>
using namespace std;

int main()
{
    cout << "***** Hello, Welcome to Frank's Carpet Cleaning Service *****\n" << endl;
    cout << "How many rooms would you like cleaned? ";

    int num_of_rooms;
    cin >> num_of_rooms;

    const double price_per_room {30.0};
    const double sales_tax {0.06};
    const int estimate_expiry {30}; //days

    cout << endl << "Estimate for carpet cleaning service:" << endl;
    cout << "Number of rooms: " << num_of_rooms << endl;
    cout << "Price per room: $" << price_per_room << endl;
    cout << "Cost: $" << price_per_room*num_of_rooms << endl;
    cout << "Tax: $" << price_per_room*num_of_rooms*sales_tax << endl;
    cout << "==============================================" << endl;
    cout << "Total estimate: $" << (price_per_room*num_of_rooms)+(price_per_room*num_of_rooms*sales_tax) << endl;
    cout << "This estimate is valid for " << estimate_expiry << " days" << endl;
    return 0;
}
