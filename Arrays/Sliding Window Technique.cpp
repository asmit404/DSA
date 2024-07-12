#include <iostream>
#include <algorithm>
using namespace std;

int maxSum(int arr[], int n, int k)
{
    if (n < k)
    {
        cout << "Invalid";
        return -1;
    }

    int curr_window_sum = 0;
    // Calculate the sum of the first window of size k
    for (int i = 0; i < k; i++)
        curr_window_sum += arr[i];

    int max_window_sum = curr_window_sum;
    // Slide the window from start to end of the array
    for (int i = k; i < n; i++)
    {
        // Add the next element in the window and remove the first element of the previous window
        curr_window_sum += arr[i] - arr[i - k];
        // Update the maximum sum if the current window's sum is greater
        max_window_sum = max(max_window_sum, curr_window_sum);
    }
    return max_window_sum;
}

int main()
{
    int n = 6, k = 3;
    int arr[] = {16, 12, 9, 19, 11, 8};
    cout << maxSum(arr, n, k);
    return 0;
}