#include <iostream>
#include <vector>
using namespace std;

void printLeaders(int arr[], int size)
{
    vector<int> leaders;
    int max_from_right = arr[size - 1];
    leaders.push_back(max_from_right);

    for (int i = size - 2; i >= 0; i--)
    {
        if (arr[i] >= max_from_right)
        {
            max_from_right = arr[i];
            leaders.push_back(max_from_right);
        }
    }

    for (int i = leaders.size() - 1; i >= 0; i--)
    {
        cout << leaders[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {1, 2, 2, 0, 0, 2, 7, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    printLeaders(arr, n);
    return 0;
}