#include <iostream>
#include <vector>
using namespace std;

void printGroups(const vector<bool> &arr)
{
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        // Check if the current element is different from the previous element
        if (arr[i] != arr[i - 1])
        {
            // If the current element is different from the first element, start a new group
            if (arr[i] != arr[0])
                cout << "From " << i << " to ";
            // Otherwise, end the current group
            else
                cout << (i - 1) << endl;
        }
    }
    // If the last element is different from the first element, end the last group
    if (arr[n - 1] != arr[0])
        cout << (n - 1) << endl;
}

int main()
{
    vector<bool> arr = {0, 1, 1, 0, 0, 0, 1, 1};
    printGroups(arr);
    return 0;
}