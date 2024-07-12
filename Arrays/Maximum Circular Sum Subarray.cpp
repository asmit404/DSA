#include <iostream>
#include <cmath>
using namespace std;

// Function to find the maximum sum of a normal (non-circular) subarray
int normalMaxSum(int arr[], int n)
{
    int res = arr[0];
    int maxEnding = arr[0];

    for (int i = 1; i < n; i++)
    {
        // Update maxEnding to be the maximum of the current element or the sum of maxEnding and the current element
        maxEnding = max(maxEnding + arr[i], arr[i]);
        // Update result if maxEnding is greater than the current result
        res = max(maxEnding, res);
    }
    return res; 
}

// Function to find the maximum sum of a circular subarray
int overallMaxSum(int arr[], int n)
{
    // Find the maximum sum of a normal subarray
    int max_normal = normalMaxSum(arr, n);
    if (max_normal < 0)
        return max_normal;

    int arr_sum = 0;
    // Traverse the array to find the sum and invert the elements
    for (int i = 0; i < n; i++)
    {
        arr_sum += arr[i];
        arr[i] = -arr[i];
    }

    // Find the maximum sum of the inverted array (which is the minimum sum of the original array)
    int max_circular = arr_sum + normalMaxSum(arr, n);
    // Return the maximum of the normal and circular subarray sums
    return max(max_circular, max_normal);
}

int main()
{
    int arr[] = {8, -4, 3, -5, 4}, n = 5;
    cout << overallMaxSum(arr, n);
}