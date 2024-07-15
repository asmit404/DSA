#include <iostream>
#include <array>

using namespace std;

// Define the number of rows and columns
const int R = 4, C = 4;

// Function to print the matrix in a snake pattern
void printSnake(const array<array<int, C>, R> &mat)
{
    // Iterate over each row
    for (int i = 0; i < R; i++)
    {
        // Check if the row index is even
        if (i % 2 == 0)
        {
            // Print elements from left to right
            for (int j = 0; j < C; j++)
                cout << mat[i][j] << " ";
        }
        else
        {
            // Print elements from right to left
            for (int j = C - 1; j >= 0; j--)
                cout << mat[i][j] << " ";
        }
        // Move to the next line after printing each row
        cout << endl;
    }
}

int main()
{
    // Initialize a 4x4 matrix
    array<array<int, C>, R> arr = {{{1, 2, 3, 4},
                                    {5, 6, 7, 8},
                                    {9, 10, 11, 12},
                                    {13, 14, 15, 16}}};

    // Call the function to print the matrix in a snake pattern
    printSnake(arr);
    return 0;
}