#include <iostream>

using namespace std;

template<typename T>
class TilakArray{
public:
    TilakArray(size_t size) : size_{size} {
        if(size_ > 0) {
            ptr_ = new T[size_];
        }
        else {
            ptr_ = nullptr;
        }
    }

    // Copy consructor
    TilakArray(const TilakArray& ta) : size_{ta.size_} {
        if(ta.size_ > 0) {
            ptr_ = new T[ta.size_];
            for(size_t i{0U}; i < size_; i++) {
                ptr_[i] = ta.ptr_[i];
            }
        } else {
            ptr_ = nullptr;
        }
    }

    // Move constructor
    TilakArray(TilakArray&& ta) : size_{ta.size_} {
        ptr_ = ta.ptr_;
        ta.ptr_ = nullptr;
        ta.size_ = 0U;
    }

    // Copy Assignment
    TilakArray& operator=(const TilakArray& ta) {
        if(this == &ta) {
            return *this;
        }
        delete ptr_;
        size_ = ta.size_;
        if(size_ > 0) {
            ptr_ = new T[size_];
            for(size_t i{0U}; i < size_; i++) {
                ptr_[i] = ta.ptr_[i];
            }
        }
        else {
            ptr_ = nullptr;
        }

        return *this;
    }

    // Move assignment
    TilakArray& operator=(TilakArray&& ta) {
        if(this == &ta) {
            return;
        }
        size_ = ta.size_;
        ptr_ = ta.ptr_;
        ta.ptr_ = nullptr;
        ta.size_ = 0U;

        return *this;
    }

    ~TilakArray() {
        delete[] ptr_;
    }
private:
    T *ptr_{};      // nullptr by default
    size_t size_{}; // 0 by default

};

TilakArray<char> makeTilakArray(const TilakArray<char>& ta) {
    TilakArray<char> ta3{ta};
    return ta3;
}

int main() {
    TilakArray<char> ta{20};
    TilakArray<char> ta2{makeTilakArray(ta)};
    int *p = new int[0];
    cout << *p << endl;
}