#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;

void display_menu();
char get_selection();

void handle_display(const vector<int> &list);
void handle_add(vector<int> &list);
void handle_mean(const vector<int> &list);
void handle_smallest(const vector<int> &list);
void handle_largest(const vector<int> &list);
void handle_find(const vector<int> &list);
void handle_quit();
void handle_unknown();

void display_list(const vector<int> &list);
double calculate_mean(const vector<int> &list);
int get_smallest(const vector<int> &list);
int get_largest(const vector<int> &list);

int main()
{
    char selection{};
    vector<int> list;

    do{
        display_menu();
        selection = get_selection();
        switch(selection){
            case 'P':
                handle_display(list);
                break;
            case 'A':
                handle_add(list);
                break;
            case 'M':
                handle_mean(list);
                break;
            case 'S':
                handle_smallest(list);
                break;
            case 'L':
                handle_largest(list);
                break;
            case 'F':
                handle_find(list);
                break;
            case 'Q':
                handle_quit();
                break;
            default:
                handle_unknown();
                break;
        }
    }while(selection != 'Q');
    return 0;
}

void display_menu(){
    cout << endl << "***** MENU *****" << endl;
    cout << "P - Print numbers" << endl;
    cout << "A - Add a number" << endl;
    cout << "M - Display mean of the numbers" << endl;
    cout << "S - Display the smallest number" << endl;
    cout << "L - Display the largest number" << endl;
    cout << "F - Find a number and how many times it occurred" << endl;
    cout << "Q - QUIT" << endl;

    cout << endl << "Enter your choice : ";
}

char get_selection(){
    char selection{};
    cin >> selection;
    return toupper(selection);
}

void handle_display(const vector<int> &list){
    if(list.size() == 0){
        cout << "[] - the list is empty" << endl;
    }
    else{
        display_list(list);
    }
}

void display_list(const vector<int> &list){
    cout << "[ ";
    for(auto val : list){
        cout << val << " ";
    }
    cout << "]" << endl;
}

void handle_add(vector<int> &list){
    int num_to_add{};
    cout << "Enter an integer to add to the list: ";
    cin >> num_to_add;
    list.push_back(num_to_add);
    cout << num_to_add << " added" << endl;
}

void handle_mean(const vector<int> &list){
    if(list.size() == 0){
        cout << "Unable to calculate the mean - no data" << endl;
    }
    else{
        cout << "The mean is: " << calculate_mean(list) << endl;
    }
}

double calculate_mean(const vector<int> &list){
    int sum{0};
    for(auto val : list){
            sum += val;
    }
    return static_cast<double>(sum) / list.size();
}

void handle_smallest(const vector<int> &list){
    if(list.size() == 0){
        cout << "Unable to determine the smallest number - list is empty" << endl;
    }
    else{
        cout << "The smallest number is: " << get_smallest(list) << endl;
    }
}

int get_smallest(const vector<int> &list){
    return *min_element(list.begin(),list.end());
}

void handle_largest(const vector<int> &list){
    if(list.size() == 0){
        cout << "Unable to determine the largest number - list is empty" << endl;
    }
    else{
        cout << "The largest number is: " << get_largest(list) << endl;
    }
}

int get_largest(const vector<int> &list){
    return *max_element(list.begin(),list.end());
}

void handle_find(const vector<int> &list){
    if(list.size() == 0){
        cout << "You will find nothing - list is empty" << endl;
    }
    else{
        int num_to_find{};
        int count{0};
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

void handle_quit(){
    cout << endl << "Goodbye..." << endl;
}

void handle_unknown(){
    cout << endl << "Unknown selection... Please try again!!" << endl;
}