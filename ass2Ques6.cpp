/*6) Write a program to implement the following operations on a Sparse Matrix,
assuming the matrix is represented using a triplet.
(a) Transpose of a matrix.
(b) Addition of two matrices.
(c) Multiplication of two matrices.*/
#include <iostream>
using namespace std;
int main()
{
    int part;
    cout << "Enter the part (1 for Transpose, 2 for Addition, 3 for Multiplication): ";
    cin >> part;
    int mat[4][4] = {{0, 1, 0, 0}, {0, 0, 2, 0}, {0, 0, 0, 3}, {4, 0, 0, 0}};
    int sparse[4][3];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (mat[i][j] != 0)
            {
                sparse[i][0] = i;
                sparse[i][1] = j;
                sparse[i][2] = mat[i][j];
            }
        }
    }
    cout << "sparse matrix as triplet:" << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << sparse[i][0] << " " << sparse[i][1] << " " << sparse[i][2] << endl;
    }
    if (part == 1)
    {
        cout << "Transpose of the matrix:" << endl;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                int temp = sparse[i][0];
                sparse[i][0] = sparse[i][1];
                sparse[i][1] = temp;
            }
        }
        for (int i = 0; i < 4; i++)
        {
            cout << sparse[i][0] << " " << sparse[i][1] << " " << sparse[i][2] << endl;
        }
    }
    else if (part == 2)
    {
        int mat2[4][4] = {{0, 5, 0, 0}, {0, 2, 0, 0}, {0, 0, 0, 7}, {0, 9, 0, 0}};
        int sparse2[4][3];
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (mat2[i][j] != 0)
                {
                    sparse2[i][0] = i;
                    sparse2[i][1] = j;
                    sparse2[i][2] = mat2[i][j];
                }
            }
        }
        cout << "Second matrix as triplet:" << endl;
        for (int i = 0; i < 4; i++)
        {
            cout << sparse2[i][0] << " " << sparse2[i][1] << " " << sparse2[i][2] << endl;
        }
        int add[8][3];
        for (int i = 0; i <6; i++)
        {

            if (sparse[i][0] == sparse2[i][0] && sparse[i][1] == sparse2[i][1])
            {
                add[i][0] = sparse[i][0];
                add[i][1] = sparse[i][1];
                add[i][2] = sparse[i][2] + sparse2[i][2];
            }
            else if (sparse[i][0] < sparse2[i][0] || (sparse[i][0] == sparse2[i][0] && sparse[i][1] < sparse2[i][1]))
            {
                add[i][0] = sparse[i][0];
                add[i][1] = sparse[i][1];
                add[i][2] = sparse[i][2];
            }
            else if (sparse[i][0] > sparse2[i][0] || (sparse[i][0] == sparse2[i][0] && sparse[i][1] > sparse2[i][1]))
            {
                add[i][0] = sparse2[i][0];
                add[i][1] = sparse2[i][1];
                add[i][2] = sparse2[i][2];
            }
        }
        cout << "Addition of the matrices:" << endl;
        for (int i = 0; i < 6; i++)
        {
            cout << add[i][0] << " " << add[i][1] << " " << add[i][2] << endl;
        }
    }
    return 0;
}

