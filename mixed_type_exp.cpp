/*
    Ask the user to enter 3 integers
    Calculate the sum of the integers then calculate the average of the 3 integers

    Display the 3 integers entered
    thesum of the 3 integers and
    the average og the 3 intregers
*/

#include <iostream>
using namespace std;

int main()
{
    int total {};
    int num1 {},num2 {},num3 {};
    const int count {3};

    cout << "Enter 3 integers separated with spaces: ";
    cin >> num1 >> num2 >> num3;

    total = num1 + num2 + num3;
    
    double average {};
    average = static_cast<double>(total) / count; //converts total from int to double
    //average = (double)total / count;  //Old Style

    cout << "The 3 numbers were: " << num1 << "," << num2 << "," << num3 << endl;
    cout << "The sum of the 3 numbers is: " << total << endl;
    cout << "The average of the numbers is: " << average << endl;   
    
    return 0;
}