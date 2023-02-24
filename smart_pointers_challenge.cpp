#include<iostream>
#include<vector>
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

unique_ptr<vector<shared_ptr<Test>>> make(){
    return make_unique<vector<shared_ptr<Test>>>();
}

void fill(vector<shared_ptr<Test>> &vec,int num){
    for(int i{0}; i<num; ++i){
        int n{};
        cout << "Enter data point [" << i+1 << "]: ";
        cin >> n;
        shared_ptr<Test> ptr = make_shared<Test>(n);
        vec.push_back(ptr);
    }
}

ostream &operator<<(ostream &os,const Test &obj){
    os << obj;
    return os;
}

void display(const vector<shared_ptr<Test>> &vec){
    cout << "\nDisplaying vector data" << endl;
    cout << "=======================" << endl;
    for(const auto &val : vec){
        cout << val -> get_data() << endl;
    }
    cout << "=======================" << endl;
}

int main()
{
    unique_ptr<vector<shared_ptr<Test>>> vec_ptr;
    vec_ptr = make();
    cout << "How many data points do you want to enter: ";
    int num{};
    cin >> num;
    fill(*vec_ptr,num);
    display(*vec_ptr);
    return 0;
}