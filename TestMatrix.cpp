#include <iostream>
#include "Matrix.h"
#include <string>
#include <cassert>

using namespace std;

void Matrix::test_case_Matrix_make()
{
    Matrix res(2, 3);
    assert(res.rows == 2);
    assert(res.cols == 3);
    for (unsigned i = 0; i < rows; i++)
    {
        for (unsigned j = 0; j < cols; j++)
        {
            assert(res.matrix[i][j] == 0);
            cout << res.matrix[i][j] << " " << endl;
        }
    }
    cout << "Test case succeeded" << endl;
}

void Matrix::test_case_Matrix_copy()
{
    Matrix mat(2, 3);

    mat.set(1, 1, 3);
    assert(mat.get(1, 1) == 3);
    Matrix copyOnto(1, 3);

    assert(rows == mat.rows);
    assert(cols == mat.cols);
    for (unsigned i = 0; i < rows; i++)
    {
        for (unsigned j = 0; j < cols; j++)
        {
            assert(matrix[i][j] == mat.matrix[i][j]);
            cout << matrix[i][j] << " " << endl;
        }
    }
}
main()
{
    Matrix a(2, 3);
    a.test_case_Matrix_make();

    return 0;
}