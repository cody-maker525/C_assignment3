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
    for (unsigned i = 0; i < res.rows; i++)
    {
        for (unsigned j = 0; j < res.cols; j++)
        {
            cout << res.matrix[i][j] << " ";
        }
        cout << "\n";
    }
}
main()
{
    Matrix a(2, 3);
    a.test_case_Matrix_make();
    return 0;
}