#include <iostream>
using namespace std;

int main()
{
    cout << "***** Hello, Welcome to Frank's Carpet Cleaning Service *****\n" << endl;
    
    cout << "How many small rooms would you like cleaned? ";
    int small_rooms;
    cin >> small_rooms;
    
    cout << "How many large rooms would you like cleaned? ";
    int large_rooms;
    cin >> large_rooms;

    const double price_per_small_room {25.0};
    const double price_per_large_room {35.0};
    const double sales_tax {0.06};
    const int estimate_expiry {30}; //days

    cout << endl << "Estimate for Carpet Cleaning Service:" << endl;
    cout << "Number of small rooms: " << small_rooms << endl;
    cout << "Number of large rooms: " << large_rooms << endl;
    cout << "Price per small room: $" << price_per_small_room << endl;
    cout << "Price per large room: $" << price_per_large_room << endl;
    cout << "Cost: $" << (small_rooms*price_per_small_room)+(large_rooms*price_per_large_room) << endl;
    cout << "Tax: $" << ((small_rooms*price_per_small_room)+(large_rooms*price_per_large_room))*sales_tax << endl;
    cout << "=======================================================" << endl;
    cout << "Total estimate: $" << ((small_rooms*price_per_small_room)+(large_rooms*price_per_large_room))+(((small_rooms*price_per_small_room)+(large_rooms*price_per_large_room))*sales_tax) << endl;
    cout << "This estimate is valid for " << estimate_expiry << " days" << endl;
    return 0;
}