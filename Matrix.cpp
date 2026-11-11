#include <iostream>
#include "Matrix.h"
#include <string>
#include <cassert>
using namespace std;

Matrix::Matrix(unsigned int m, unsigned int n)
{
    rows = m;
    cols = n;
    matrix = new int *[rows]; // creates pointer for amount of rows

    for (unsigned int i = 0; i < rows; i++)
    {
        matrix[i] = new int[cols]; // creates new block of cols pointers per row
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
    matrix = new int *[rows];

    for (unsigned int i = 0; i < rows; i++)
    {
        matrix[i] = new int[cols]; // creates new block of cols pointers per row
        for (unsigned int j = 0; j < cols; j++)
        {
            matrix[i][j] = mat.matrix[i][j];
        }
    }
}

Matrix::Matrix(int **array, unsigned int m, unsigned int n)
{

    rows = m;
    cols = n;
    matrix = new int *[rows]; // array of rows and each element is address
                              // of a row

    for (unsigned int i = 0; i < rows; i++)
    {
        matrix[i] = new int[cols]; // returns one extra star (memory of star)
        for (unsigned int j = 0; j < cols; j++)
        {
            matrix[i][j] = array[i][j];
        }
    }
}
unsigned int Matrix::rows1() const
{
    return rows;
}

unsigned int Matrix::columns() const
{
    return cols;
}

int Matrix::get(unsigned i, unsigned j) const
{
    return matrix[i][j];
}

void Matrix::set(unsigned i, unsigned j, int value)
{
    if (rows)
        matrix[i][j] = value;
}

Matrix Matrix::operator+(const Matrix &mat)
{
    Matrix result(rows, cols);

    for (unsigned int i = 0; i < rows; i++)
    {
        for (unsigned int j = 0; j < cols; j++)
        {
            result.matrix[i][j] = matrix[i][j] + mat.matrix[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator-(const Matrix &mat)
{

    Matrix result(rows, cols);

    for (unsigned int i = 0; i < rows; i++)
    {
        for (unsigned int j = 0; j < cols; j++)
        { // assuming it doesn't matter which order the matrices are although this will change the answer
            result.matrix[i][j] = matrix[i][j] - mat.matrix[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator*(const Matrix &mat)
{

    Matrix result(rows, cols);

    for (unsigned int i = 0; i < rows; i++)
    {
        for (unsigned int j = 0; j < cols; j++)
        {
            result.matrix[i][j] = matrix[i][j] * mat.matrix[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator~() const
{

    Matrix res(rows, cols);

    for (unsigned int i = 0; i < rows; i++)
    {
        for (unsigned int j = 0; j < cols; j++)
        {
            res.matrix[i][j] = res.matrix[j][i];
        }
    }
    return res;
}

bool Matrix::operator==(const Matrix &mat)
{
    for (unsigned int i = 0; i < rows; i++)
    {
        for (unsigned int j = 0; j < cols; j++)
        {
            if (matrix[i][j] != mat.matrix[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

string Matrix::toStr()
{
    string str = "";
    for (unsigned int i = 0; i < rows; i++)
    {
        for (unsigned int j = 0; j < cols; j++)
        {
            str += to_string(matrix[i][j]) + '\n';
        }
    }
    return str;
}

void test_case_1()
{
    Matrix mat1(2, 3);
    mat1.printMatrix();
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