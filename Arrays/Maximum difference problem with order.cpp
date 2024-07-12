#include <iostream>
#include <climits>
using namespace std;

int maxDifference(int arr[], int n)
{
    if (n < 2)
    {
        return -1; // Not enough elements to form a difference
    }

    int min_element = arr[0];
    int max_diff = INT_MIN;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] - min_element > max_diff)
        {
            max_diff = arr[i] - min_element;
        }
        if (arr[i] < min_element)
        {
            min_element = arr[i];
        }
    }

    return max_diff;
}

int main()
{
    int arr[] = {1, 2, 2, 0, 0, 2, 7, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = maxDifference(arr, n);
    if (result != -1)
    {
        cout << "Maximum difference is " << result << endl;
    }
    else
    {
        cout << "Not enough elements to find a difference" << endl;
    }
    return 0;
}