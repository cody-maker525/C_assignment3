#include <iostream>
using namespace std;

class Matrix
{
private:
    unsigned int rows;
    unsigned int cols;
    int **matrix;

public:
    // first one, rows + cols input
    Matrix(unsigned int m, unsigned int n);
    // first test case
    static void test_case_Matrix_make();

    // 2nd, copy matrix onto new matrix
    Matrix(const Matrix &mat);
    // test case, copy matrix onto new matrix
    static void test_case_Matrix_copy();

    // 3rd, copy matrix values onto new matrix with mxn dimensions
    Matrix(int **array, unsigned int m, unsigned int n);
    // 3rd test case, copy matrix values onto new matrix with mxn dimensions
    static void test_case_Matrix_copy_with_dimensions();

    // 4th, return row value method
    unsigned int rows1() const;
    // 4th test case, return row value
    static void test_case_Matrix_rows();

    // 5th, return column value method
    unsigned int cols1() const;
    // 5th test case, return row value
    static void test_case_Matrix_cols();

    // 6th, get method from i and j row and col indexes
    int get(unsigned i, unsigned j) const;
    // 6th, test case get method from i and j row and col indexes
    static void test_case_Matrix_get();

    // 7th, set method using index i and j row and col
    void set(unsigned i, unsigned j, int value);
    // 7th, test case set method using index i and j row and col
    static void test_case_Matrix_set();

    // 8th, add 2 matrixes together and return matrix with total
    Matrix operator+(const Matrix &mat);
    // 8th, test case to test both matrixes added together
    static void test_case_Matrix_operator_plus();

    // 9th, minus 2 matrixes and return matrix with total
    Matrix operator-(const Matrix &mat);
    // 9th, test case minus 2 matrixes and return matrix with total
    static void test_case_Matrix_operator_minus();

    Matrix operator*(const Matrix &mat);

    Matrix operator~() const;

    bool operator==(const Matrix &mat);

    string toStr();

    void printMatrix();

    ~Matrix()
    {
        for (int i = 0; i < rows; i++)
        {
            delete[] matrix[i];
        }
        delete[] matrix;
    }
};