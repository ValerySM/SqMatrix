//  Creator: Valery Sokolov Morgenshteyn
//  ID : 336424221


#include "sqmatrix.h"

#include "myset.h"

#include <iostream>

#include <iomanip> 

#include <cstdlib>

using namespace std;


SqMatrix::~SqMatrix() 
{
    //TODO
    cout << "\n" << "Destructor called with size = " << size << endl;

    freeArr();
}


ostream& operator<< (ostream& output, const SqMatrix& sqMatrix)
{
    for (int i = 0; i < sqMatrix.size; i++)
    {
        for (int j = 0; j < sqMatrix.size; j++)
        {
            output << setw(5) 
                << sqMatrix.arr[i][j];
        }
        cout << std::endl;
    }

    output << std::endl; 

    return output; 
}
int** SqMatrix::allocate2DSqArray(int size) {   //an helper function for allocating memory to a matrix
    int** array = nullptr;
    if (size <= 0)
        return nullptr;

    array = new int* [size];   // rows pointers allocation
    if (!array)
    {
        cout << "Allocation Error!!\n";
        exit(1);
    }

    for (int i = 0; i < size; i++) {
        array[i] = new int[size];
        if (!array[i])
        {
            cout << "Allocation Error!!\n";
            exit(1);
        }
    }
    return array;
}
SqMatrix SqMatrix::operator+ (const SqMatrix& right)
{
    if (size != right.size)
    {
        cout << "Arrays of different sizes!\n";
        exit(1); 
    }

    SqMatrix result = *this;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            result.arr[i][j] += right.arr[i][j];

    return result; 
}


SqMatrix SqMatrix::operator- (const SqMatrix& right)
{
    if (size != right.size)
    {
        cout << "Arrays of different sizes!\n";
        exit(1); 
    }

    SqMatrix result = *this;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            result.arr[i][j] -= right.arr[i][j];

    return result; 
}

SqMatrix::SqMatrix() {
    
    size = 0;
    arr = nullptr;
}

SqMatrix::SqMatrix(int size, int** arr) {
    this->size = size;
    this->arr = allocate2DSqArray(size);
    copy2DSqArray(size, arr, this->arr);
}

SqMatrix::SqMatrix(const SqMatrix& matrixToCopy) {   //helper function for copying the matrix
    this->size = matrixToCopy.size;
    this->arr = allocate2DSqArray(size);
    copy2DSqArray(size, matrixToCopy.arr, this->arr);
}

void SqMatrix::copy2DSqArray(int size, int** source, int** destination) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            destination[i][j] = source[i][j];

}


void SqMatrix::freeArr() {   //helper function to free the matrix memory
    for (int i = 0; i < size; i++)
        if (arr && arr[i])
            delete[] arr[i];
    if (arr)
        delete[] arr;

}

const SqMatrix& SqMatrix::operator=(const SqMatrix& right) {
    this->size = right.size;
    // freeArr();
    this->arr = allocate2DSqArray(size);
    copy2DSqArray(size, right.arr, arr);
    return *this;
}

SqMatrix SqMatrix::operator*(const SqMatrix& right) {
    if (right.size != size)
    {
        cout << "Size have to be equal as you multiply\n";
        exit(1);
    }
    int** resultArr = allocate2DSqArray(size);
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
        {
            resultArr[i][j] = 0;
            for (int k = 0; k < size; k++)
            {
                resultArr[i][j] += arr[i][k] * right.arr[k][j];
            }
        }
    SqMatrix result(size, resultArr);
    return result;
}