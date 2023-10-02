#include <iostream>
#include <vector>

using namespace std;

// Searches an array for a target value in a sorted array
// Uses the ==, >, <, >=, <= comparison operators
// Returns true if it exists, else false
template <typename T>
bool binarySearch(vector<T>& v, const T& target) {
    size_t l{0U};           // left bound
    size_t r{v.size() - 1}; // right bound

    while(l <= r) {
        ssize_t search_index = (r + l) / 2; // favors left side on even ranges
        
        if(v[search_index] == target) {
            return true;
        }
        else if(v[search_index] > target) {
            // prevent overflow
            if(search_index == 0) {
                return false;
            }
            else {
                r = search_index - 1;
            }
        }
        else {
            l = search_index + 1; 
        }
    }
    return false;
}

int main() {
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 100, 103, 105, 200};
    if(binarySearch(v, 0)) {
        cout << "Error: 0" << endl;
    }
    if(!binarySearch(v, 1)) {
        cout << "Error: 1" << endl;
    }
    if(!binarySearch(v, 200)) {
        cout << "Error: 200" << endl;
    }
    if(binarySearch(v, 201)) {
        cout << "Error: 201" << endl;
    }
    if(!binarySearch(v, 6)) {
        cout << "Error: 6" << endl;
    }
    if(!binarySearch(v, 7)) {
        cout << "Error: 7" << endl;
    }
    cout << "ALL TESTS COMPLETE" << endl;
}
