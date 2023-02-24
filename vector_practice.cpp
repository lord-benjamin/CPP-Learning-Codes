#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector <int> vector1;
    vector <int> vector2;

    vector1.push_back(10);
    vector1.push_back(20);
    cout << "Elements in vector1:" << endl;
    cout << vector1.at(0) << endl;
    cout << vector1.at(1) << endl;
    cout << "There are " << vector1.size() << " elements in vector1" << endl;

    vector2.push_back(100);
    vector2.push_back(200);
    cout << endl << "Elements in vector2:" << endl;
    cout << vector2.at(0) << endl;
    cout << vector2.at(1) << endl;
    cout << "There are " << vector2.size() << " elements in vector2" << endl;

    vector <vector<int>> vector_2d;
    vector_2d.push_back(vector1);
    vector_2d.push_back(vector2);
    cout << endl << "Elements in vector_2d:" << endl;
    cout << vector_2d.at(0).at(0) << " " << vector_2d.at(0).at(1) << endl;
    cout << vector_2d.at(1).at(0) << " " << vector_2d.at(1).at(1) << endl;

    vector1.at(0) = 1000;   //change will not be shown in vector_2d because
                            //it has taken values from the previous vector1

    cout << endl << "Elements in vector_2d:" << endl;
    cout << vector_2d.at(0).at(0) << " " << vector_2d.at(0).at(1) << endl;
    cout << vector_2d.at(1).at(0) << " " << vector_2d.at(1).at(1) << endl;
    
    cout << endl << "Elements in vector1:" << endl;
    cout << vector1.at(0) << endl;
    cout << vector1.at(1) << endl;
    cout << "There are " << vector1.size() << " elements in vector1" << endl;
    
    return 0;
}