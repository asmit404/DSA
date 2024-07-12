#include <iostream>
using namespace std;

void findFrequencies(int arr[], int N)
{
    // Initialize the current element and its frequency
    int currentElement = arr[0];
    int frequency = 1;

    // Traverse the array starting from the second element
    for (int i = 1; i < N; i++)
    {
        if (arr[i] == currentElement)
        {
            // Increment the frequency if the current element is the same
            frequency++;
        }
        else
        {
            // Print the current element and its frequency
            cout << currentElement << " occurs " << frequency << " times" << endl;
            // Update the current element and reset the frequency counter
            currentElement = arr[i];
            frequency = 1;
        }
    }

    // Print the last element and its frequency
    cout << currentElement << " occurs " << frequency << " times" << endl;
}

int main()
{
    int arr[] = {1, 1, 2, 2, 2, 3, 3, 4};
    int N = sizeof(arr) / sizeof(arr[0]);

    findFrequencies(arr, N);

    return 0;
}