#include <iostream>
using namespace std;

int main()
{
    bool equal_result{};
    bool not_equal_result{};

    cout << boolalpha;  //will display true/false instead of 1/0 for booleans

    // int num1{},num2{};
    // cout << "Enter two integers separated by a space: ";
    // cin >> num1 >> num2;
    // equal_result = (num1 == num2);
    // not_equal_result = (num1 != num2);
    // cout << "Comparison result (equals): " << equal_result << endl;
    // cout << "Comparison result (not equals): " << not_equal_result << endl;
    
    // char char1{},char2{};
    // cout << "Enter two characters separated by spaces: ";
    // cin >> char1 >> char2;
    // equal_result = (char1 == char2);
    // not_equal_result = (char1 != char2);
    // cout << "Comparison result (equals): " << equal_result << endl;
    // cout << "Comparison result (not equals): " << not_equal_result << endl;
    
    // double double1{},double2{};
    // cout << "Enter two doubles separated by a space: ";
    // cin >> double1 >> double2;
    // equal_result = (double1 == double2);
    // not_equal_result = (double1 != double2);
    // cout << "Comparison result (equals): " << equal_result << endl;
    // cout << "Comparison result (not equals): " << not_equal_result << endl;
    
    int n{};
    double d{};
    cout << "Enter an integer and a double separated by a space: ";
    cin >> n >> d;
    equal_result = (n == d);
    not_equal_result = (n != d);
    cout << "Comparison result (equals): " << equal_result << endl;
    cout << "Comparison result (not equals): " << not_equal_result << endl;
    
    return 0;
}