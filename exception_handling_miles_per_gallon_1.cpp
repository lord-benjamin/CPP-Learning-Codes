#include<iostream>
using namespace std;

int main()
{
    int miles{},gallons{};
    double miles_per_gallons{};

    cout << "Enter the miles: ";
    cin >> miles;
    cout << "Enter the gallons: ";
    cin >> gallons;

    // miles_per_gallons = miles / gallons;
    if(gallons != 0){
        miles_per_gallons = static_cast<double>(miles) / gallons;
        cout << "Result: " << miles_per_gallons << endl;
    }
    else{
        cerr << "Sorry, can't divide by zero" << endl;
    }

    cout << "Bye" << endl;
    return 0;
}