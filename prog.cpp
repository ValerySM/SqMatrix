//  Creator: Valery Sokolov Morgenshteyn
//  ID : 336424221

#include<iostream>
#include<cstdlib>
#include<iomanip>
#include<ctime>
using namespace std;

#include "sqmatrix.h"
#include "myset.h"
int** allocate2DSqArray(int size);
#include <cstdlib>
void free2dArray(int** arr, int size);
int main()
{

    SqMatrix m1, m2, m3, m4, m5;
    MySet s1, s2;
    int** arr2d, * arr1d, size, num2add, num2remove;
    cout << "Enter size of first matrix: ";
    cin >> size;
    arr2d = allocate2DSqArray(size);
    cout << "Enter m1:\n";
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            cin >> arr2d[i][j];
    m1 = SqMatrix(size, arr2d);
    // free2dArray(arr2d, size);
    cout << "\n\nEnter size of second matrix: ";
    cin >> size;

    arr2d = allocate2DSqArray(size);
    cout << "Enter m2:\n";
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            cin >> arr2d[i][j];
    m2 = SqMatrix(size, arr2d);
    free2dArray(arr2d, size);
    m3 = m1 + m2;
    m4 = m1 * m2;
    m5 = m2 * m1;
    cout << "\n\nm1+m2:" << endl << m3;
    cout << "\n\nm1*m2:" << endl << m4;
    cout << "\n\nm2*m1:" << endl << m5;
    cout << "\nEnter size of s1";
    cin >> size;
    arr1d = new int[size];
    cout << "Enter s1:\n";
    for (int i = 0; i < size; i++)
        cin >> arr1d[i];
    s1 = MySet(arr1d, size);
    delete[] arr1d;

    cout << "\nEnter size of s2";
    cin >> size;
    arr1d = new int[size];
    cout << "Enter s2:\n";
    for (int i = 0; i < size; i++)
        cin >> arr1d[i];
    s2 = MySet(arr1d, size);
    delete[] arr1d;
    cout << "\ns1=" << s1 << endl;
    cout << "\ns2=" << s2 << endl;
    cout << "\nEnter a number to add to s1: ";
    cin >> num2add;
    cout << "\nEnter a number to remove from s1: ";
    cin >> num2remove;
    s1 += num2add;
    s2 -= num2remove;
    cout << "\ns1=" << s1 << endl;
    cout << "\ns2=" << s2 << endl;
    if (s1 == s2)
        cout << "s1 is equal to s2\n";
    else if (s1 <= s2)
        cout << "s1 is contained in s2\n";
    else if (s2 <= s1)
        cout << "s2 is contained in s1\n";

    cout << "Number of elements " << s1.total_size() + s2.total_size() << endl;
    cout << "Sum of elements " << s1.total_sum() + s2.total_sum() << endl;
    cout << "\ns1 is" << (contain(s1, m1) ? " " : " not ") << "in m1\n";
    cout << "\ns1 is" << (contain(s1, m2) ? " " : " not ") << "in m2\n";
    cout << "\ns2 is" << (contain(s2, m1) ? " " : " not ") << "in m1\n";
    cout << "\ns2 is" << (contain(s2, m2) ? " " : " not ") << "in m2\n";

    return 0;
}


int** allocate2DSqArray(int size) {
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



bool contain(const MySet& set, const SqMatrix& matrix)
{
    MySet copy_set;
    copy_set = set;
    for (int i = 0; i < matrix.size; i++)
        for (int j = 0; j < matrix.size; j++)
            copy_set -= matrix.arr[i][j];
    return copy_set.total_size() == 0;
}
void free2dArray(int** arr, int size) {
    for (int i = 0; i < size; i++)
        delete[] arr[i];
    delete[] arr;
}