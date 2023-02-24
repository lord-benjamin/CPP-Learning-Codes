//Calculate the area of the room in square feet
#include <iostream>
using namespace std;

int main() 
{
    cout << "Enter the width of the room: ";
    int room_width {0};   //initializes the variable to 0,can use anything
    cin >> room_width;

    cout << "Enter the length of the room: ";
    int room_length {0};  //declare the variable close to where we are going to us it
    cin >> room_length;

    cout << "The area of the room is " << room_width*room_length << " square feet" << endl;
    return 0;
}
