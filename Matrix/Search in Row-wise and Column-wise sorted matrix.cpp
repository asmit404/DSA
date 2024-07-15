#include <iostream>
#include <array>
#include <utility>

using namespace std;

const int R = 4, C = 4;

// Function to search for an element in a row-wise and column-wise sorted matrix
pair<int, int> search(const array<array<int, C>, R> &mat, int x)
{
    // Start from the top-right corner of the matrix
    int i = 0, j = C - 1;

    // Loop until we are within the bounds of the matrix
    while (i < R && j >= 0)
    {
        // If the element is found, return its position
        if (mat[i][j] == x)
        {
            return {i, j};
        }
        // If the element is greater than x, move left
        else if (mat[i][j] > x)
        {
            j--;
        }
        // If the element is less than x, move down
        else
        {
            i++;
        }
    }

    // If the element is not found, return {-1, -1}
    return {-1, -1};
}

int main()
{
    // Initialize the matrix
    array<array<int, C>, R> arr = {{{10, 20, 30, 40},
                                    {15, 25, 35, 45},
                                    {27, 29, 35, 45},
                                    {32, 33, 39, 50}}};

    // Element to be searched
    int x = 29;

    // Search for the element in the matrix
    pair<int, int> result = search(arr, x);

    // Print the result
    if (result.first != -1)
    {
        cout << "Found at (" << result.first << ", " << result.second << ")";
    }
    else
    {
        cout << "Not Found";
    }

    return 0;
}