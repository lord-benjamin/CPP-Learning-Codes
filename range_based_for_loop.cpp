#include <iostream>
#include <vector>
#include <iomanip>  //for line 24
using namespace std;

int main()
{
    // int scores[]{10,20,30};
    // for(auto score : scores){
    //     cout << score << endl;
    // }

    // vector<double> temperature{87.9,77.9,80.0,72.5};
    // double average_temp{};
    // double total{};
    // for(auto temp : temperature){
    //     total += temp;
    // }
    // if(temperature.size() != 0){
    //     average_temp = total / temperature.size();
    // }
    // cout << fixed << setprecision(1);  //for rounding off
    // cout << "Average temperature is " << average_temp << endl;
    
    // for(auto val : {1,2,3,4,5}){
    //     cout << val << endl;
    // }

    // for(auto c : "This is a test"){
    //     if(c != ' '){
    //         cout << c;
    //     }
    // }

    for(auto c : "This is a test"){
        if(c == ' '){
            cout << "\t";
        }
        else{
            cout << c;
        }
    }
    return 0;
}