/*
    + addition
    - subtraction
    * multiplication
    / division
    % modulo or remainder (works only with integers)

    +, -, *, / operators are overloaded to work with multiple types such as int, double, etc
    % only for integer types
*/
#include <iostream>
using namespace std;

int main()
{
    int num1 {200};
    int num2 {100};

    cout << num1 << " + " << num2 << " = " << num1+num2 << endl << endl;

    int result;

    result = num1 + num2;
    cout << num1 << " + " << num2 << " = " << result << endl;

    result = num1 - num2;
    cout << num1 << " - " << num2 << " = " << result << endl;

    result = num1 * num2;
    cout << num1 << " * " << num2 << " = " << result << endl;

    result = num1 / num2;
    cout << num1 << " / " << num2 << " = " << result << endl;
    
    result = num2 / num1;
    cout << num2 << " / " << num1 << " = " << result << endl;  //will omit whatever is after the decimal
                                                               //as it is integer division
                                                               //(0.5 will become 0)
    result = num1 % num2;
    cout << num1 << " % " << num2 << " = " << result << endl;
    
    num1 = 10;
    num2 = 3;

    result = num1 % num2;
    cout << num1 << " % " << num2 << " = " << result << endl;

    result = num1 * 10 + num2; //can use any number of arithmetic operators in a single line

    cout << 5/10 << endl; //will give 0 as it is integer division

    cout << 5.0/10.0 << endl; //will give 0.5 as it is float division

    cout << 12 / 2 * 3 + 6 - 1 << endl;  //will follow BODMAS rule
    return 0;
}