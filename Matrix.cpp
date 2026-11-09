#include <iostream>
#include "Matrix.h"
using namespace std;

Matrix::Matrix(unsigned int m, unsigned int n)
{
    rows = m;
    cols = n;
    matrix = new unsigned int *[rows]; // creates pointer for amount of rows

    for (unsigned int i = 0; i < rows; i++)
    {
        matrix[i] = new unsigned int[cols]; // creates new block of cols pointers per row
        for (unsigned int j = 0; j < cols; j++)
        {
            matrix[i][j] = 0;
        }
    }
}

Matrix::Matrix(const Matrix &mat)
{
    rows = mat.rows;
    cols = mat.cols;
    matrix = new unsigned int *[rows];

    for (unsigned int i = 0; i < rows; i++)
    {
        matrix[i] = new unsigned int[cols]; // creates new block of cols pointers per row
        for (unsigned int j = 0; j < cols; j++)
        {
            matrix[i][j] = mat.matrix[i][j];
        }
    }
}

void Matrix::printMatrix()
{
    for (unsigned int i = 0; i < rows; i++)
    {

        for (unsigned int j = 0; j < cols; j++)
        {
            cout << matrix[i][j] << " " << endl;
        }
    }
}
void test_case_1()
{
    Matrix mat1(2, 3);
    mat1.printMatrix();
}
int main()
{

    test_case_1();
    return 0;
}