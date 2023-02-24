#include<iostream>
#include<vector>
using namespace std;

void print(const int *const arr,size_t size){
    cout << "[ ";
    for(int i{0}; i<size; ++i){
        cout << arr[i] << " ";
    }
    cout << "]" << endl;
}

int *apply_all(int arr1[],size_t arr1_size,int arr2[],size_t arr2_size){
    int *arr = new int[arr1_size*arr2_size];
    int i{0};
    while(i < arr1_size*arr2_size){
        for(int j{0}; j<arr2_size; ++j){
            for(int k{0}; k<arr1_size; ++k){
                arr[i] = arr2[j] * arr1[k];
                i++;
            }
        }
    }
    return arr;
    delete [] arr;
}

int main()
{
    const size_t array1_size{5};
    const size_t array2_size{3};
    
    int array1[]{1,2,3,4,5};
    int array2[]{10,20,30};

    cout << "Array 1: ";
    print(array1,array1_size);

    cout << "Array 2: ";
    print(array2,array2_size);
    
    int *results = apply_all(array1,array1_size,array2,array2_size);
    constexpr size_t results_size{array1_size*array2_size};

    cout << "Result: ";
    print(results,results_size);
    return 0;
}