#include <iostream>
#include <vector>
using namespace std;

int getSum(const vector<int> &pSum, int l, int r)
{
    // If l is 0, return the prefix sum at index r
    if (l == 0)
    {
        return pSum[r];
    }
    else
    {
        // Otherwise, return the difference between prefix sums at r and l-1
        return pSum[r] - pSum[l - 1];
    }
}

int main()
{
    // Initialize the array
    vector<int> arr = {2, 8, 3, 9, 6, 5, 4};
    int n = arr.size();

    // Initialize and compute the prefix sum array
    vector<int> pSum(n);
    pSum[0] = arr[0]; // First element is the same as the original array
    for (int i = 1; i < n; ++i)
    {
        // Each element in pSum is the sum of all previous elements in arr
        pSum[i] = pSum[i - 1] + arr[i];
    }

    // Output the sum of elements from index 2 to 6
    cout << getSum(pSum, 2, 6) << endl;
    return 0;
}