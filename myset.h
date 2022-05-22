#ifndef MYSET_H
#define MYSET_H

#include <istream>
#include <ostream>
#include "sqmatrix.h"

using std::istream;
using std::ostream;
class SqMatrix;
class MySet
{
    friend ostream& operator<< (ostream&, const MySet&); 
    friend bool contain(const MySet& set, const SqMatrix& matrix);
private:
    int* arr;
    int size; 
    void copyArr(int len, int* source, int* destination);
public:
    MySet(); 
    MySet(int* arr, int len); 
    MySet(const MySet&); 
    ~MySet(); 

    int total_size() const;
    int total_sum() const;
    MySet& operator= (const MySet&); 
    bool operator&& (int elem) const;
    bool operator== (const MySet&) const; 
    MySet& operator+= (const int&); 
    MySet& operator-= (const int&); 
    bool operator<= (const MySet&) const;

};

#endif 