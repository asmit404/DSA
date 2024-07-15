#include <iostream>
#include <string>
#include <climits>
using namespace std;

const int CHAR = 256; // Total number of ASCII characters

int leftMostRep(string &str)
{
    // Array to store the first index of each character initialized to -1
    int fIndex[CHAR];
    for (int i = 0; i < CHAR; i++)
        fIndex[i] = -1;

    int res = INT_MAX;
    for (int i = 0; i < str.length(); i++)
    {
        int fi = fIndex[str[i]]; // Get the first index of the current character
        if (fi == -1)
            fIndex[str[i]] = i; // If character is seen for the first time, store its index
        else
            res = min(res, fi); // If character is repeating, update the result with the minimum index
    }
    // If no repeating character is found, return -1
    return (res == INT_MAX) ? -1 : res;
}

int main()
{
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    cout << "Index of leftmost repeating character:" << endl;
    cout << leftMostRep(str) << endl;
    return 0;
}