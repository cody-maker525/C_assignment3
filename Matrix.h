#include <iostream>
using namespace std;

class Matrix
{
private:
    unsigned int rows;
    unsigned int cols;
    unsigned int **matrix;

public:
    Matrix(unsigned int m, unsigned int n);
    Matrix(const Matrix &mat);

    ~Matrix()
    {
        for (int i = 0; i < rows; i++)
        {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

public:
    void printMatrix()
    {
        for (unsigned int i = 0; i < rows; i++)
        {

            for (unsigned int j = 0; j < cols; j++)
            {
                cout << matrix[i][j] << " " << endl;
            }
        }
    }
};