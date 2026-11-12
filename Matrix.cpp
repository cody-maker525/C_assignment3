#include <iostream>
#include "Matrix.h"
#include <string>
using namespace std;

/* *
 * Constructs a Matrix with dimensions of unsigned int m and unsigned int n (given by the specification).
 * All values will be 0 in the array.
 * @param m = number of rows
 * @param n = number of cols
 * @throw out_of_range if m or n are 0.
 * @return nothing but a Matrix is created of dimensions m and n and
 * all values within the array will be initialized as 0.
 */
Matrix::Matrix(unsigned int m, unsigned int n)
{
    if (m <= 0 || n <= 0)
    {
        throw out_of_range("Matrix constructor (unsigned int m, unsigned int n) method index out of bounds");
    }
    rows = m;
    cols = n;
    matrix = new int *[rows]; // creates pointer for amount of rows

    for (unsigned int i = 0; i < rows; i++)
    {
        matrix[i] = new int[cols];
        for (unsigned int j = 0; j < cols; j++)
        {
            matrix[i][j] = 0;
        }
    }
}

/* *
 * Create a new Matrix that is a copy of an inputted matrix, copying the same dimensions and values.
 * The row and column value will come from the row and cols value from the inputted matrix.
 * The values will be in the same positions as the inputted matrix.
 * @param mat is another matrix.
 * @throws out_of_range if m or n is 0, the inputs variable names are stated in the sentence to
 * differentiate between the Matrix classes.
 * @return nothing but a new Matrix created which is a copy of the inputted array.
 */

Matrix::Matrix(const Matrix &mat)
{
    if (rows == 0 || cols == 0)
    {
        throw out_of_range("Matrix constructor (&mat) method index out of bounds");
    }
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

/* *
 * Construct a new Matrix with dimensions from m and n and values copied from an inputted Matrix.
 * @param m = number of rows.
 * @param n = number of cols.
 * @param array = pointer to the array that called the function.
 * @throw out_of_range if m or n are 0.
 * @return nothing but a Matrix is created with values copied from inputted Matrix and
 * dimensions m and n from input.
 */

Matrix::Matrix(int **array, unsigned int m, unsigned int n)
{
    if (rows == 0 || cols == 0)
    {
        throw out_of_range("Matrix constructor (int **array, unsigned int m, unsigned int n) method index out of bounds");
    }

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

/**
 * Returns the row value of the array.
 * @param none.
 * @throw an out_of_range exception if rows is 0.
 * @return an unsigned int value called rows which represents the row value.
 *
 */
unsigned int Matrix::rows1() const
{
    if (rows == 0)
    {
        throw out_of_range("Rows method index out of bounds");
    }
    return rows;
}

/**
 * Returns the column value of the array.
 * @param none.
 * @throw an out_of_range exception if rows is 0.
 * @return an unsigned int value called cols which represents the column value.
 */
unsigned int Matrix::cols1() const
{
    if (cols == 0)
    {
        throw out_of_range("Rows method index out of bounds");
    }
    return cols;
}

/**
 * Returns the value of row value i and column value j in the array.
 * @param i = row value number.
 * @param j = column value number.
 * @throw an out_of_range exception if  i or j is 0 or rows or cols are 0.
 * @return an unsigned int value called cols which represents the column value.
 */
int Matrix::get(unsigned i, unsigned j) const
{
    if (rows <= i || cols <= j || rows == 0 || cols == 0)
    {
        throw out_of_range("GET method index out of bounds");
    }
    return matrix[i][j];
}

/**
 * Sets the value using the inputted value onto row value i and column value j in the array.
 * @param i = row value number.
 * @param j = column value number.
 * @param value = value to set array[i][j] to.
 * @throw an out_of_range exception if  i, j,rows, cols are 0.
 * @return nothing but set value of array[i][j] as inputted value.
 */

void Matrix::set(unsigned i, unsigned j, int value)
{
    if (rows <= i || cols <= j || rows == 0 || cols == 0)
    {
        throw out_of_range("SET method index out of bounds");
    }
    matrix[i][j] = value;
}

/**
 * Creates a new array that adds 2 arrays together and stores the totals
 * The 2 arrays are the inputted array and the array that calls the function.
 * @param mat is another matrix.
 * @throw an out_of_range exception if rows or cols is 0.
 * @return an array called result that stores the totals.
 */

Matrix Matrix::operator+(const Matrix &mat)
{

    Matrix result(rows, cols);

    if (rows == 0 || cols == 0)
    {
        throw out_of_range("Operator+ method index out of bounds");
    }

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