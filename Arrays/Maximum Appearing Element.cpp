#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int maximumOccurredElement(int L[], int R[], int n)
{
    // Find the maximum value in R to determine the size of the vector
    int maxi = *max_element(R, R + n);

    // Initialize the vector with size maxi + 2
    vector<int> arr(maxi + 2, 0);

    // Adding +1 at Li index and subtracting 1 at Ri index.
    for (int i = 0; i < n; i++)
    {
        arr[L[i]] += 1;
        arr[R[i] + 1] -= 1;
    }

    // Finding prefix sum and index having maximum prefix sum.
    int msum = arr[0], ind = 0;
    for (int i = 1; i <= maxi; i++)
    {
        arr[i] += arr[i - 1];
        if (msum < arr[i])
        {
            msum = arr[i];
            ind = i;
        }
    }

    return ind;
}

int main()
{
    int L[] = {1, 5, 9, 13, 21};
    int R[] = {15, 8, 12, 20, 30};
    int n = sizeof(L) / sizeof(L[0]);
    cout << maximumOccurredElement(L, R, n) << endl;
    return 0;
}