#include <iostream>
using namespace std;

int main()
{
    char vowels[5] {'a','e','i','o','u'};
    cout << "The first vowel is: " << vowels[0] << endl;
    cout << "The last vowel is: " << vowels[4] << endl;
    
    double hi_temps[] {90.1,89.8,77.5,81.6};
    cout << endl << "The first high temperature is: " << hi_temps[0] << endl;
    hi_temps[0] = 100.7;  //set the first element in hi_temps to 100.7
                          //use of assignment operator
    cout << "The first high temperature is now: " << hi_temps[0] << endl;

    
    int test_scores[5] {100,90,80,70,60};
    cout << endl << "First score at index 0: " << test_scores[0] << endl;
    cout << "First score at index 1: " << test_scores[1] << endl;
    cout << "First score at index 2: " << test_scores[2] << endl;
    cout << "First score at index 3: " << test_scores[3] << endl;
    cout << "First score at index 4: " << test_scores[4] << endl;
    
    cout << "Enter 5 test scores: ";
    cin >> test_scores[0];
    cin >> test_scores[1];
    cin >> test_scores[2];
    cin >> test_scores[3];
    cin >> test_scores[4];

    cout << endl << "The updated array is:" << endl;
    cout << "First score at index 0: " << test_scores[0] << endl;
    cout << "First score at index 1: " << test_scores[1] << endl;
    cout << "First score at index 2: " << test_scores[2] << endl;
    cout << "First score at index 3: " << test_scores[3] << endl;
    cout << "First score at index 4: " << test_scores[4] << endl;
    
    cout << endl << "Notice what the value of the array name is: " << test_scores << endl;  
        //will give the memory address or the storage location of the array

    return 0;
}