#include <bits/stdc++.h>
using namespace std;

int findCandidate(int a[], int size)
{
    int maj_index = 0, count = 1;
    for (int i = 1; i < size; i++)
    {
        // If the current element is the same as the candidate, increment the count
        if (a[maj_index] == a[i])
            count++;
        else
            count--;
        // If count drops to 0, update the candidate to the current element
        if (count == 0)
        {
            maj_index = i;
            count = 1;
        }
    }
    return a[maj_index];
}

bool isMajority(int a[], int size, int cand)
{
    int count = 0;
    // Count the occurrences of the candidate in the array
    for (int i = 0; i < size; i++)
        if (a[i] == cand)
            count++;
    // If count is more than half the size of the array, return true
    if (count > size / 2)
        return true;
    else
        return false;
}

void printMajority(int a[], int size)
{
    int cand = findCandidate(a, size);
    if (isMajority(a, size, cand))
        cout << " " << cand << " ";
    else
        cout << "No Majority Element";
}

int main()
{
    int a[] = {1, 3, 3, 1, 2};
    int size = (sizeof(a)) / sizeof(a[0]);
    printMajority(a, size);
    return 0;
}