#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<cctype>
#include<string>
using namespace std;

class Person{
    string name;
    int age;
public:
    Person() = default;
    Person (string name,int age)
        :name{name},age{age} {}
    bool operator<(const Person &rhs) const{
        return this->age < rhs.age;
    }
    bool operator==(const Person &rhs) const{
        return (this->name == rhs.name && this->age == rhs.age);
    }
};

//Find an element in a container

void find_test(){
    cout << "\n===========================" << endl;
    vector<int> vec{1,2,3,4,5};
    auto loc = find(begin(vec),end(vec),1);
    if(loc != end(vec)){
        cout << "Found the number:  " << *loc << endl;
    }
    else{
        cout << "Couldn't find the number" << endl;
    }

    list<Person> players{
        {"Larry",18},
        {"Moe",20},
        {"Curly",21},
    };

    auto loc1 = find(players.begin(),players.end(),Person{"Moe",20});
    if(loc1 != players.end()){
        cout << "Found Moe" << endl;
    }
    else{
        cout << "Moe not found" << endl;
    }
}

//Count the number of elements in the container
void count_test(){
    cout << "\n===========================" << endl;

    vector<int> vec{1,2,3,4,5,1,2,1};
    int num = count(vec.begin(),vec.end(),1);
    cout << num << " occurrences found" << endl;
}

//Count the number of occurrences in a container based on a predicate using a lambda function
void count_if_test(){
    cout << "\n===========================" << endl;

    //count only if the element is even
    vector<int> vec{1,2,3,4,5,1,2,1,100};
    int num = count_if(vec.begin(),vec.end(),[](int x){
        return x%2 == 0;
    });
    cout << num << " even numbers found" << endl;
    
    num = count_if(vec.begin(),vec.end(),[](int x){
        return x%2 != 0;
    });
    cout << num << " odd numbers found" << endl;

    //how can we determine how many elements in vec are >=5?
    num = count_if(vec.begin(),vec.end(),[](int x){
        return x>=5;
    });
    cout << num << " numbers are >=5" << endl;
}

//Replace occurrences of elements in a container
void replace_test(){
    cout << "\n===========================" << endl;
    
    vector<int> vec{1,2,3,4,5,1,2,1};
    for(auto i : vec){
        cout << i << " ";
    }
    cout << endl;

    replace(vec.begin(),vec.end(),1,100);
    for(auto i : vec){
        cout << i << " ";
    }
    cout << endl;
}

void all_of_test(){
    cout << "\n===========================" << endl;

    vector<int> vec1{1,3,5,7,9,1,3,13,19,5};
    if(all_of(vec1.begin(),vec1.end(),[](int x){ return x > 10;})){
        cout << "All the elements are > 10" << endl;
    }
    else{
        cout << "Not all the elements are > 10" << endl;
    }

    if(all_of(vec1.begin(),vec1.end(),[](int x){ return x < 20;})){
        cout << "All the elements are < 20" << endl;
    }
    else{
        cout << "Not all the elements are < 20" << endl;
    }
}

void string_transform_test(){
    cout << "\n===========================" << endl;
    string str1{"This is a test"};
    cout << "Before transform: " << str1 << endl;
    transform(str1.begin(),str1.end(),str1.begin(),::toupper);
    cout << "After transform: " << str1 << endl;
}

int main()
{
    find_test();
    count_test();
    count_if_test();
    replace_test();
    all_of_test();
    string_transform_test();
    return 0;
}