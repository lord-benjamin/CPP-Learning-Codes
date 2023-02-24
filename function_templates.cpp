#include<iostream>
#include<string>
using namespace std;

template<typename T>
T minimum(T a,T b){
    return (a < b) ? a : b;
}

template<typename T1,typename T2>
void func(T1 a,T2 b){
    cout << a << " " << b << endl;
}

struct Person{
    string name;
    int age;
    bool operator<(const Person &rhs) const{
        return this->age < rhs.age;
    }
};

ostream &operator<<(ostream &os,const Person &obj){
        os << obj.name;
        return os;
    }

template<typename T>
void my_swap(T &a,T &b){
    T temp = a;
    a = b;
    b = temp;
}

int main()
{
    int x{100};
    int y{200};
    cout << x << " " << y << endl;      // 100 200
    my_swap(x,y);
    cout << x << " " << y << endl;      // 200 100
    
    Person p1{"Curly",50};
    Person p2{"Moe",30};

    Person p3 = min(p1,p2);
    cout << p3.name << " is younger" << endl;  // Moe is younger

    func(p1,p2);      // Curly Moe

    cout << minimum<int>(2,3) << endl;   // 2
    cout << minimum(2,3) << endl;        // 2
    cout << minimum('A','B') << endl;    // A
    cout << minimum(12.5,9.2) << endl;   // 9.2
    cout << minimum(5+2*2,7+40) << endl; // 9

    func<int,int>(10,20);                // 10 20
    func(10,20);                         // 10 20
    func<char,double>('A',12.4);         // A 12.4
    func('A',12.4);                      // A 12.4
    func(1000,"Testing");                // 1000 Testing
    func(2000,string{"Frank"});          // 2000 Frank
    return 0;
}