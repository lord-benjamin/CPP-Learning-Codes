#include <iostream>
#include <vector>  //don't forget this in order to use vectors
using namespace std;

int main()
{
//  vector <char> vowels;   //empty
//  vector <char> vowels (5);   //5 elements all initialized to zero
    vector <char> vowels {'a','e','i','o','u'};

    cout << vowels[0] << endl;
    cout << vowels[4] << endl;

//  vector <int> test_scores (3); //3 elements all initialized to zero
//  vector <int> test_scores (3,100); //3 elements all initialized to 100
    vector <int> test_scores {100,98,89};

    cout << endl << "Test scores using array syntax:" << endl;
    cout << test_scores[0] << endl;
    cout << test_scores[1] << endl;
    cout << test_scores[2] << endl;

    cout << endl << "Test scores using vector syntax:" << endl;
    cout << test_scores.at(0) << endl;
    cout << test_scores.at(1) << endl;
    cout << test_scores.at(2) << endl;
    cout << "There are " << test_scores.size() << " elements in the vector" << endl; //vector_name.size()
                                                                                     //gives the size
                                                                                     //of the vector
    cout << endl << "Enter 3 test scores: ";
    cin >> test_scores.at(0);
    cin >> test_scores.at(1);
    cin >> test_scores.at(2);
    
    cout << endl << "Updated test scores:" << endl;
    cout << test_scores.at(0) << endl;
    cout << test_scores.at(1) << endl;
    cout << test_scores.at(2) << endl;

    cout << endl << "Enter a test score to add to the vector: ";
    int score_to_add;
    cin >> score_to_add;

    test_scores.push_back(score_to_add);

    cout << endl << "Enter one more test score to add to vector: ";
    cin >> score_to_add;

    test_scores.push_back(score_to_add);

    cout << endl << "Test scores are now:" << endl;
    cout << test_scores.at(0) << endl;
    cout << test_scores.at(1) << endl;
    cout << test_scores.at(2) << endl;
    cout << test_scores.at(3) << endl;
    cout << test_scores.at(4) << endl;
    cout << "There are now " << test_scores.size() << " elements in the vector" << endl;

    //cout << "This should cause an exception!!" << test_scores.at(10) << endl;  //will not print anything

    
    //Example of a 2D vector
    vector <vector<int>> movie_ratings
    {
        {1,2,3,4},
        {1,2,4,4},
        {1,3,4,5}
    };

    cout << endl << "Here are the movie ratings for reviewer #1 using array syntax:" << endl;
    cout << movie_ratings[0][0] << endl;
    cout << movie_ratings[0][1] << endl;
    cout << movie_ratings[0][2] << endl;
    cout << movie_ratings[0][3] << endl;

    cout << endl << "Here are the movie ratings for reviewer #1 using vector syntax:" << endl;
    cout << movie_ratings.at(0).at(0) << endl;
    cout << movie_ratings.at(0).at(1) << endl;
    cout << movie_ratings.at(0).at(2) << endl;
    cout << movie_ratings.at(0).at(3) << endl;
    return 0;
}