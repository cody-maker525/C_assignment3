#include <iostream>
#include "Matrix.h"
#include <string>
#include <cassert>

using namespace std;

// test case 1 for creating matrix with mxn dimensions and all values = 0
void Matrix::test_case_Matrix_make()
{
    Matrix res(2, 3);
    assert(res.rows == 2);
    assert(res.cols == 3);
    cout << "Test case 1 Matrix Make method succeeded" << endl;
}

// test case 2 for create new matrix and copy dimensions and values from inputted matrix
void Matrix::test_case_Matrix_copy()
{
    Matrix mat(2, 3);
    mat.set(1, 1, 3);

    Matrix copy(mat);

    assert(copy.get(1, 1) == 3);
    cout << "Test case 2 Matrix Copy method succeeded" << endl;
}

// test case 3 for create new matrix and initialize with mxn dimensions and values from inputted matrix.
void Matrix::test_case_Matrix_copy_with_dimensions()
{
    Matrix mat(2, 3);
    mat.set(1, 1, 3);
    mat.set(0, 1, 4);

    Matrix copyWithDimensions(mat.matrix, 2, 3);

    assert(copyWithDimensions.get(1, 1) == 3);
    assert(copyWithDimensions.get(0, 1) == 4);
    assert(copyWithDimensions.get(0, 0) == 0);
    cout << "Test case 3 Matrix Copy method and initialize with mxn dimensions succeeded" << endl;
}

// test case 4, return row value
void Matrix::test_case_Matrix_rows()
{
    Matrix res(2, 3);
    assert(res.rows1() == 2);
    cout << "Test case 4 Matrix return row value succeeded" << endl;
}

//  test case 5, return column value
void Matrix::test_case_Matrix_cols()
{
    Matrix res(2, 3);
    assert(res.cols1() == 3);
    cout << "Test case 5 Matrix return row value succeeded" << endl;
}

//  test case 6, get method from index i and j
void Matrix::test_case_Matrix_get()
{
    Matrix mat(2, 3);
    mat.set(1, 1, 3);

    assert(mat.get(1, 1) == 3);
    cout << "Test case 6 Matrix get method succeeded" << endl;
}

//  test case 7, set method from index i and j
void Matrix::test_case_Matrix_set()
{
    Matrix mat(2, 3);
    mat.set(0, 1, 3);

    assert(mat.get(0, 1) == 3);
    cout << "Test case 7 Matrix set method succeeded" << endl;
}

// test case 8 for add 2 matrixes together and output result matrix with totals
void Matrix::test_case_Matrix_operator_plus()
{
    Matrix a(2, 2);
    Matrix b(2, 2);

    //  make a values all 3 and b values all 4

    for (int i = 0; i < a.rows; i++)
    {

        for (int j = 0; j < a.cols; j++)
        {
            a.set(i, j, 3);
            b.set(i, j, 4);
        }
    }
    Matrix total = a.operator+(b);
    assert(total.get(0, 0) == 7);
    assert(total.get(0, 1) == 7);
    assert(total.get(1, 0) == 7);
    assert(total.get(1, 1) == 7);

    cout << "Test case 8 Matrix Operator+ method succeeded" << endl;
}

void Matrix::test_case_Matrix_operator_minus()
{
    Matrix a(2, 2);
    Matrix b(2, 2);

    //  make a values all 3 and b values all 4

    for (int i = 0; i < a.rows; i++)
    {

        for (int j = 0; j < a.cols; j++)
        {
            a.set(i, j, 3);
            b.set(i, j, 4);
        }
    }
    Matrix total = a.operator-(b);
    assert(total.get(0, 0) == -1);
    assert(total.get(0, 1) == -1);
    assert(total.get(1, 0) == -1);
    assert(total.get(1, 1) == -1);

    cout << "Test case 9 Matrix Operator- method succeeded" << endl;
}

int main()
{
    Matrix::test_case_Matrix_make();
    Matrix::test_case_Matrix_copy();
    Matrix::test_case_Matrix_copy_with_dimensions();
    Matrix::test_case_Matrix_rows();
    Matrix::test_case_Matrix_cols();
    Matrix::test_case_Matrix_get();
    Matrix::test_case_Matrix_set();
    Matrix::test_case_Matrix_operator_plus();
    Matrix::test_case_Matrix_operator_minus();

    return 0;
}