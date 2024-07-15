#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int leftMostNonRep(string &str)
{
    unordered_map<char, int> charIndex;
    for (int i = 0; i < str.length(); i++)
    {
        // If the character is not in the map, add it with its index
        if (charIndex.find(str[i]) == charIndex.end())
            charIndex[str[i]] = i;
        // If the character is already in the map, set its value to -1 (indicating repetition)
        else
            charIndex[str[i]] = -1;
    }

    int res = INT_MAX;
    // Traverse the map to find the smallest index of non-repeating character
    for (auto &entry : charIndex)
    {
        // If the character is non-repeating, update the result
        if (entry.second != -1)
            res = min(res, entry.second);
    }

    // If no non-repeating character is found, return -1; otherwise, return the result
    return (res == INT_MAX) ? -1 : res;
}

int main()
{
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    cout << "Index of leftmost non-repeating element:" << endl;
    cout << leftMostNonRep(str) << endl;
    return 0;
}