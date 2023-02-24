#include<iostream>
using namespace std;

double calculate_mpg(int miles,int gallons){
    if(gallons == 0){
        throw 0;
    }
    return static_cast<double>(miles) / gallons;
}

int main()
{
    int miles{};
    int gallons{};
    double miles_per_gallons{};

    cout << "Enter the miles: ";
    cin >> miles;
    cout << "Enter the gallons: ";
    cin >> gallons;

    try{
        miles_per_gallons = calculate_mpg(miles,gallons);
        cout << "Result: " << miles_per_gallons << endl;
    }
    catch(int &ex){
        cout << "Tried to divide by zero" << endl;
    }

    cout << "Bye" << endl;
    return 0;
}