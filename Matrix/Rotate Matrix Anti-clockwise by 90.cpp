#include <iostream>
using namespace std;

const int n = 4;

void rotateAC90(int mat[n][n])
{
    // Transpose the matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            // Swap elements mat[i][j] and mat[j][i]
            swap(mat[i][j], mat[j][i]);
        }
    }

    // Reverse each column
    for (int i = 0; i < n; i++)
    {
        for (int j = 0, k = n - 1; j < k; j++, k--)
        {
            // Swap elements mat[j][i] and mat[k][i]
            swap(mat[j][i], mat[k][i]);
        }
    }
}

int main()
{
    // Initialize a 4x4 matrix
    int arr[n][n] = {{1, 2, 3, 4},
                     {5, 6, 7, 8},
                     {9, 10, 11, 12},
                     {13, 14, 15, 16}};
    rotateAC90(arr);

    // Print the rotated matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}