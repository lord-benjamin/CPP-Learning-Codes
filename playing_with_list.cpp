#include<iostream>
#include<vector>
using namespace std;

int main()
{
    string selection{};
    vector<int> list{};
    vector<int> list_copy{};
    
    do{
        cout << endl << "***** MENU *****" << endl;
        cout << "1 - Print numbers" << endl;
        cout << "2 - Add a number" << endl;
        cout << "3 - Display mean of the numbers" << endl;
        cout << "4 - Display the smallest number" << endl;
        cout << "5 - Display the largest number" << endl;
        cout << "6 - Find a number and how many times it occurred" << endl;
        cout << "7 - Clear the list (make it empty)" << endl;
        cout << "8 - Remove duplicate numbers" << endl;
        cout << "9 - Dimension (size) of the list" << endl;
        cout << "10 - QUIT" << endl;

        cout << endl << "Enter your choice : ";
        cin >> selection;
        
        
        int num_to_add{},sum{0},num_to_find{},count{0},duplicate_num{};

        if(selection == "1"){
            if(list.size() == 0){
                cout << "[] - the list is empty" << endl;
            }
            else{
                cout << "[ ";
                for(auto val : list){
                    cout << val << " ";
                }
                cout << "]" << endl;
            }
        }
        else if(selection == "2"){
            cout << "Enter an integer to add to the list: ";
            cin >> num_to_add;
            list.push_back(num_to_add);
            cout << num_to_add << " added" << endl;
        }
        else if(selection == "3"){
            if(list.size() == 0){
                cout << "Unable to calculate the mean - no data" << endl;
            }
            else{
                for(auto val : list){
                    sum += val;
                }
                cout << "The mean is: " << static_cast<double>(sum) / list.size() << endl;
            }
        }
        else if(selection == "4"){
            if(list.size() == 0){
                cout << "Unable to determine the smallest number - list is empty" << endl;
            }
            else{
                int min{list.at(0)};
                for(auto val : list){
                    if(val < min){
                        min = val;
                    }
                }
                cout << "The smallest number is: " << min << endl;
            }
        }
        else if(selection == "5"){
            if(list.size() == 0){
                cout << "Unable to determine the largest number - list is empty" << endl;
            }
            else{
                int max{list.at(0)};
                for(auto val : list){
                    if(val > max){
                        max = val;
                    }
                }
                cout << "The largest number is: " << max << endl;
            }
        }
        else if(selection == "6"){
            if(list.size() == 0){
                cout << "You will find nothing - list is empty" << endl;
            }
            else{
                cout << "Enter the integer you want to find: ";
                cin >> num_to_find;
                for(auto val : list){
                    if(val == num_to_find){
                        count++;
                    }
                }
                if(count >= 1){
                    cout << "The integer " << num_to_find << " was found " << count << " time(s) in the list" << endl;
                }
                else{
                    cout << "The integer " << num_to_find << " is not in list" << endl;
                }
            }
        }
        else if(selection == "7"){
            if(list.size() == 0){
                cout << "The list is already empty" << endl;
            }
            else{
                list.clear();
                cout << "The list is now empty" << endl;
            }
        }
        else if(selection == "8"){
            if(list.size() == 0){
                cout << "The list is empty" << endl;
            }
            else{
                cout << "Enter the number whose duplicate(s) you want to remove: ";
                cin >> duplicate_num;
                for(auto val : list){
                    if(val == duplicate_num){
                        count++;
                    }
                }
                if(count == 0){
                    cout << "The number is not in the list" << endl;
                }
                else if(count == 1){
                    cout << "The number is present only 1 time in the list (no duplicates found)" << endl;
                }
                else{
                    list_copy = list;
                    list.clear();
                    for(auto val : list_copy){
                        if(val != duplicate_num){
                            list.push_back(val);
                        }
                    }
                    list.push_back(duplicate_num);
                    cout << "The duplicate(s) of " << duplicate_num << " have been removed from the list" << endl;
                }
            }
        }
        else if(selection == "9"){
            if(list.size() == 0){
                cout << "The list has currently no number" << endl;
            }
            else if(list.size() == 1){
                cout << "The list currently has " << list.size() << " number" << endl;
            }
            else{
                cout << "The list currently has " << list.size() << " numbers" << endl;
            }
        }
        else if(selection == "10"){
            cout << endl << "Goodbye..." << endl;
        }
        else{
            cout << endl << "Unknown selection... Please try again!!" << endl;
        }
    }while(selection != "10");
    
    return 0;
}