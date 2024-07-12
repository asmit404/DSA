#include <iostream>
using namespace std;

// Function to find the length of the longest subarray with alternating even and odd numbers
int maxEvenOdd(int arr[], int n)
{
    if (n == 0)
        return 0;
    int maxLength = 0;
    int currLen = 1;

    for (int i = 1; i < n; i++)
    {
        // Check if the current element and the previous element are alternating even and odd
        if (arr[i] % 2 != arr[i - 1] % 2)
            currLen++; // If they are, increment the current length
        else
        {
            // If they are not, update the maximum length if the current length is greater
            maxLength = max(maxLength, currLen);
            currLen = 1; // Reset the current length to 1
        }
    }

    // Update the maximum length for the last subarray
    maxLength = max(maxLength, currLen);

    // If the maximum length is 1, it means no alternating subarray was found, return 0
    if (maxLength == 1)
        return 0;

    return maxLength;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 3, 7, 2, 9, 4};
    int n = sizeof(arr) / sizeof(int);
    cout << "Length of longest subarray of even and odds is: " << maxEvenOdd(arr, n);
    return 0;
}