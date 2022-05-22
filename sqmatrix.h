//  Creator: Valery Sokolov Morgenshteyn
//  ID : 336424221


#ifndef SQMATRIX_H
#define SQMATRIX_H

#include "myset.h"
#include "iosfwd"
using namespace std;
class MySet;
class SqMatrix
{
    friend ostream& operator<< (ostream&, const SqMatrix&); // overloaded output statement
    friend bool contain(const MySet& set, const SqMatrix& matrix);
private:
    int** arr; // a pointer to a matrix of type Array
    int size; // matrix size

    int** allocate2DSqArray(int size);  //an helper function for allocating memory to a matrix
    void copy2DSqArray(int size, int** source, int** destination);  //helper function for copying the matrix
    void freeArr();  //helper function to free the matrix memory

public:
    SqMatrix();
    SqMatrix(int size, int** arr);
    SqMatrix(const SqMatrix& matrixToCopy);
    ~SqMatrix(); 

    SqMatrix operator+ (const SqMatrix& right);
    SqMatrix operator- (const SqMatrix& right);
    SqMatrix operator* (const SqMatrix& right);
    const SqMatrix& operator= (const SqMatrix& right); 
};

#endif 