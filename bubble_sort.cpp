#include <iostream>
#include <vector>
#include <stddef.h>

using namespace std;

template <typename T>
void bubbleSort(vector<T>& v) {
    // an empty vector, or vector of size 1
    // does not require sorting
    if(v.size() < 2) {
        return;
    }
    
    for(size_t j=0; j < v.size(); j++) {
        for(size_t i=0; i < (v.size() - 1 - j); i++) {
            if(v[i] > v[i+1]) {
                swap(v[i], v[i+1]);
            }
        }
    }
    return;
}

template <typename T>
void printArray(vector<T>& v) {
    for(auto elem : v) {
        cout << elem << ", ";
    }
    cout << endl;
}

int main() {
    vector<int> v1{9, 9, 8, 7, 4, 3, 2, 1};
    vector<int> v2{9, 1};
    bubbleSort(v1);
    bubbleSort(v2);
    printArray(v1);
    printArray(v2);
}
