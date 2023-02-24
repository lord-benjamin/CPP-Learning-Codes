#include<iostream>
using namespace std;

int main()
{
    int miles{},gallons{};
    double miles_per_gallons{};

    cout << "Enter the miles driven: ";
    cin >> miles;
    cout << "Enter the gallons used: ";
    cin >> gallons;

    try{
        if(gallons == 0){
            throw 0;       // will throw the error - 0 (int ; will be handled by line 21)
        }
        miles_per_gallons = static_cast<double>(miles) / gallons;
        cout << "Result: " << miles_per_gallons << endl;
    }
    catch(int &ex){        // will catch the error (int ; from line 16)
        cerr << "Sorry, can't divide by zero" << endl;
    }

    cout << "Bye" << endl;
    return 0;
}