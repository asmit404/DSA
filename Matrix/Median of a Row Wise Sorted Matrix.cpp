#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to find the median of a row-wise sorted matrix
int matMed(const vector<vector<int>> &mat, int r, int c)
{
    // Initialize min and max values
    int min = mat[0][0], max = mat[0][c - 1];

    // Find the overall minimum and maximum elements in the matrix
    for (int i = 1; i < r; i++)
    {
        if (mat[i][0] < min)
            min = mat[i][0];

        if (mat[i][c - 1] > max)
            max = mat[i][c - 1];
    }

    // Position of the median in the sorted order
    int medPos = (r * c + 1) / 2;

    // Binary search for the median
    while (min < max)
    {
        int mid = (min + max) / 2;
        int midPos = 0;

        // Count the number of elements less than or equal to mid
        for (int i = 0; i < r; ++i)
            midPos += upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();

        // Adjust the search range based on the count
        if (midPos < medPos)
            min = mid + 1;
        else
            max = mid;
    }
    // return the median value
    return min;
}

int main()
{
    // Initialize a row-wise sorted matrix
    vector<vector<int>> mat = {
        {5, 10, 20, 30, 40},
        {1, 2, 3, 4, 6},
        {11, 13, 15, 17, 19}};
    int r = mat.size();
    int c = mat[0].size();
    cout << "Median is " << matMed(mat, r, c) << endl;
    return 0;
}