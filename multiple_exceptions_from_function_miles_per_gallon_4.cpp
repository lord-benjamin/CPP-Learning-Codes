#include<iostream>
#include<string>
using namespace std;

double calculate_mpg(int miles,int gallons){
    if(gallons == 0){
        throw 0;
    }
    if(miles < 0 || gallons < 0){
        throw string{"Negative value error"};
    }
    return static_cast<double>(miles) / gallons;
}

int main()
{
    int miles{};
    int gallons{};
    double miles_per_gallon{};

    cout << "Enter the miles: ";
    cin >> miles;
    cout << "Enter the gallons: ";
    cin >> gallons;

    try{
        miles_per_gallon = calculate_mpg(miles,gallons);
        cout << "Result: " << miles_per_gallon << endl;
    }
    catch(int &ex){
        cerr << "Tried to divide by zero" << endl;
    }
    catch(string &ex){
        cerr << ex << endl;
    }
    catch(...){                               // catch all exception
        cerr << "Unknown Exception" << endl;
    }
    cout << "Bye" << endl;
    return 0;
}