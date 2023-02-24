#include<iostream>
#include<set>
using namespace std;

class Person{
    friend ostream &operator<<(ostream &os,const Person &p);
    string name;
    int age;
public:
    Person() : name{"Unknown"},age{0}{}
    Person(string name,int age) : name{name},age{age}{}
    bool operator<(const Person &rhs) const{
        return this->age < rhs.age;
    }
    bool operator==(const Person &rhs) const{
        return (this->name == rhs.name && this->age == rhs.age);
    }
};

ostream &operator<<(ostream &os,const Person &p){
    os << p.name << ": " << p.age;
    return os;
}

template<typename T>
void display(const set<T> &l){
    cout << "[ ";
    for(const auto &elem : l){
        cout << elem << " ";
    }
    cout << "]" << endl;
}

void test1(){
    cout << "\nTest1==================================" << endl;
    set<int> s1{1,4,3,5,2};
    display(s1);

    s1 = {1,2,3,1,1,2,2,3,3,4,5};
    display(s1);

    s1.insert(0);
    s1.insert(10);

    display(s1);

    if(s1.count(10)){
        cout << "10 is in the set" << endl;
    }
    else{
        cout << "10 is NOT in the set" << endl;
    }
    auto it = s1.find(5);
    if(it != s1.end()){
        cout << "Found: " <<  *it << endl;
    }
    s1.clear();
    display(s1);
}

void test2(){
    cout << "\nTest2==================================" << endl;
    set<Person> stooges{
        {"Larry",1},
        {"Moe",2},
        {"Curly",3}
    };
    display(stooges);       //Note the order of display! operator<

    stooges.emplace("James",50);
    display(stooges);

    stooges.emplace("Frank",50);    //NO -- 50 already exists
    display(stooges);

    auto it = stooges.find(Person{"Moe",2});
    if(it != stooges.end()){
        stooges.erase(it);
    }
    display(stooges);

    it = stooges.find(Person{"XXXX",50});   //Will remove James!!!
                                            //uses operator<
    if(it != stooges.end()){
        stooges.erase(it);
    }
    display(stooges);
}

void test3(){
    cout << "\nTest3==================================" << endl;
    set<string> s{"A","B","C"};
    display(s);

    auto result = s.insert("D");
    display(s);

    cout << boolalpha;
    cout << "first: " << *(result.first) << endl;
    cout << "second: " << result.second << endl;

    cout << endl;

    result = s.insert("A");
    display(s);
    
    cout << boolalpha;
    cout << "first: " << *(result.first) << endl;
    cout << "second: " << result.second << endl;
}

int main()
{
    test1();
    test2();
    test3();
    return 0;
}