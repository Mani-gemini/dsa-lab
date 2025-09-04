#include <iostream>
using namespace std;
void revarr(int *arr, int size)
{
    for (int i = 0; i <= size / 2; i++)
    {
        int temp;
        temp = arr[i];
        arr[i] = arr[size - i-1];
        arr[size - i-1] = temp;
    }
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "     ";
    }
}

void multiplyMatrix(int A[3][3], int B[3][3], int result[3][3])
{

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            result[i][j] = 0;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void mattranspose(int mat[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = i; j < 3; j++)
        {
            int temp;
            temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
    }
    for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
}
int main()
{
    cout << "hello" << endl;
    int part;
    cout << "enter 1 to reverse the array " << endl
         << "enter 2 for matrix multiplication " << endl
         << "enter 3 for transpose of a matrix"<<endl;
    cin >> part;
    if (part == 1)
    {
        int arr[] = {1, 2, 3, 4, 5, 6};
        int size = sizeof(arr) / sizeof(arr[0]);
        revarr(arr, size);
    }
    else if (part == 2)
    {
        int A[3][3] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}};

        int B[3][3] = {
            {9, 8, 7},
            {6, 5, 4},
            {3, 2, 1}};
        int result[3][3];
        multiplyMatrix(A, B, result);
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
    }
    else if (part == 3)
    {
        int matrix[3][3] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}};
        mattranspose(matrix);
    }
    else
    {
        cout << "there are just 3 parts of this ques " << endl;
    }

    return 0;
}
