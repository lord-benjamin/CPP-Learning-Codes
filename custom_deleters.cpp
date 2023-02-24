#include<iostream>
#include<memory>
using namespace std;

class Test{
private:
    int data;
public:
    Test() : data{0}{
        cout << "\tTest Constructor (" << data << ")" << endl;
    }
    Test(int data) : data{data}{
        cout << "\tTest Constructor (" << data << ")" << endl;
    }
    int get_data() const{
        return data;
    }
    ~Test(){
        cout << "\tTest Destructor (" << data << ")" << endl;
    }
};

void my_deleter(Test *ptr){
    cout << "\tUsing my custom function deleter" << endl;
    delete ptr;
}

int main()
{
    {
        //Using a function
        shared_ptr<Test> ptr1{new Test{100},my_deleter};
    }
    cout << "================================================" << endl;
    {
        //Using lambda function
        shared_ptr<Test> ptr2(new Test{1000},
        [](Test *ptr){
            cout << "\tUsing my custom lambda deleter" << endl;
            delete ptr;
        });
    }
    return 0;

}