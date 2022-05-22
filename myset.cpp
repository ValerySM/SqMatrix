#include "myset.h"

#include <iostream>
using std::cout; 
using std::cin; 

#include <iomanip> 
using std::setw;   

#include <cstdlib>

MySet::MySet() 
{
    size = 0;
    arr = nullptr;
}



MySet::MySet(int* arr, int len) {
    this->size = len;
    this->arr = new int[size];
    if (!this->arr)
    {
        cout << "Allocation Error!\n";
        exit(1);
    }
    copyArr(size, arr, this->arr);

}

void MySet::copyArr(int len, int* source, int* destination) {
    for (int i = 0; i < len; i++)
        destination[i] = source[i];

}


MySet::~MySet() {
    delete[] arr;

}

MySet::MySet(const MySet& otherSet) {
    this->size = otherSet.size;
    this->arr = new int[size];
    if (!this->arr)
    {
        cout << "Allocation Error!\n";
        exit(1);
    }
    copyArr(size, otherSet.arr, this->arr);

}

int MySet::total_size() const {
    return size;
}

int MySet::total_sum() const {
    int result = 0;
    for (int i = 0; i < size; i++)
        result += arr[i];
    return result;
}

MySet& MySet::operator=(const MySet& other) {
    if (arr)
        delete[] arr;
    this->size = other.size;
    arr = new int[size];
    if (!arr)
    {
        cout << "Allocation Error!\n";
        exit(1);
    }

    copyArr(size, other.arr, arr);
    return *this;
}

bool MySet::operator&&(const int elem) const {
    for (int i = 0; i < size; i++)
        if (arr[i] == elem)
            return true;
    return false;
}

bool MySet::operator==(const MySet& other) const {
    return (*this) <= other && other <= (*this);
}

bool MySet::operator<=(const MySet& other) const {
    for (int i = 0; i < other.size; i++)
        if (!(this->operator&&(other.arr[i])))
            return false;
    return true;
}

MySet& MySet::operator+=(const int& elem) {
    if ((*this) && elem)
        return *this;
    int* newArr = new int[size + 1];
    if (!newArr)
    {
        cout << "Allocation Error!\n";
        exit(1);
    }
    copyArr(size, arr, newArr);
    newArr[size] = elem;
    size++;
    delete[] arr;
    arr = newArr;
    return *this;
}

MySet& MySet::operator-=(const int& elem) {
    if (!((*this) && elem))
        return *this;

    int index;
    for (int i = 0; i < size; i++)
        if (arr[i] == elem)
        {
            index = i;
            break;
        }
    int* newArr = new int[size - 1];
    if (!newArr)
    {
        cout << "Allocation Error!\n";
        exit(1);
    }
    copyArr(index, arr, newArr);
    copyArr(size - index - 1, arr + index + 1, newArr + index);
    size--;
    delete[] arr;
    arr = newArr;
    return *this;

}

ostream& operator<<(ostream& output, const MySet& set) {
    output << "{";
    for (int i = 0; i < set.size - 1; i++)
        output << set.arr[i] << ",";
    output << set.arr[set.size - 1] << "}";
    return output;
}