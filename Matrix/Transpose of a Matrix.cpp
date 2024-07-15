#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

// Define the size of the matrix
constexpr int n = 4;

void transpose(array<array<int, n>, n> &mat)
{
    // Loop through the matrix elements
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            // Swap elements to transpose the matrix
            swap(mat[i][j], mat[j][i]);
}

int main()
{
    // Initialize a 4x4 matrix
    array<array<int, n>, n> arr = {{{1, 2, 3, 4},
                                    {5, 6, 7, 8},
                                    {9, 10, 11, 12},
                                    {13, 14, 15, 16}}};
    transpose(arr);

    // Print the transposed matrix
    for (const auto &row : arr)
    {
        for (const auto &elem : row)
        {
            cout << elem << " ";
        }
        cout << endl;
    }

    return 0;
}