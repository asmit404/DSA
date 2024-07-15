#include <iostream>
using namespace std;

const int R = 4, C = 4;

void boundaryTraversal(int mat[R][C])
{
    // If there is only one row, print all elements in that row
    if (R == 1)
    {
        for (int i = 0; i < C; i++)
            cout << mat[0][i] << " ";
    }
    // If there is only one column, print all elements in that column
    else if (C == 1)
    {
        for (int i = 0; i < R; i++)
            cout << mat[i][0] << " ";
    }
    else
    {
        // Traverse the top row from left to right
        for (int i = 0; i < C; i++)
            cout << mat[0][i] << " ";
        // Traverse the right column from top to bottom
        for (int i = 1; i < R; i++)
            cout << mat[i][C - 1] << " ";
        // Traverse the bottom row from right to left
        for (int i = C - 2; i >= 0; i--)
            cout << mat[R - 1][i] << " ";
        // Traverse the left column from bottom to top
        for (int i = R - 2; i > 0; i--)
            cout << mat[i][0] << " ";
    }
}

int main()
{
    // Initialize a 4x4 matrix
    int arr[R][C] = {{1, 2, 3, 4},
                     {5, 6, 7, 8},
                     {9, 10, 11, 12},
                     {13, 14, 15, 16}};
    boundaryTraversal(arr);
    return 0;
}