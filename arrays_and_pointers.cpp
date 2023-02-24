#include<iostream>
using namespace std;

int main()
{
    int scores[]{100,95,89};

    cout << "Values of scores: " << scores << endl;//---------
//                                                           |-------> Both will be equal
    int *score_ptr{scores};//                                |
    cout << "Value of score_ptr: " << score_ptr << endl;//---

    cout << "\nArray subscript notation---------------------" << endl;  // array_name[index]
    cout << scores[0] << endl;
    cout << scores[1] << endl;
    cout << scores[2] << endl;

    cout << "\nPointer subscript notation-------------------" << endl;  // pointer_name[index]
    cout << score_ptr[0] << endl;
    cout << score_ptr[1] << endl;
    cout << score_ptr[2] << endl;

    cout << "\nPointer offset notation----------------------" << endl;  // *(pointer_name + index)
    cout << *(score_ptr + 0) << endl;
    cout << *(score_ptr + 1) << endl;
    cout << *(score_ptr + 2) << endl;

    cout << "\nArray offset notation------------------------" << endl;  // *(array_name + index)
    cout << *(scores + 0) << endl;
    cout << *(scores + 1) << endl;
    cout << *(scores + 2) << endl;

    return 0;
}