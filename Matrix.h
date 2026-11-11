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
    void test_case_Matrix_make();
    Matrix(const Matrix &mat);

    void test_case_Matrix_copy(const Matrix &mat);

    Matrix(int **array, unsigned int m, unsigned int n);

    unsigned int rows1() const;

    unsigned int columns() const;

    int get(unsigned i, unsigned j) const;

    void set(unsigned i, unsigned j, int value);

    Matrix operator+(const Matrix &mat);

    Matrix operator-(const Matrix &mat);

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