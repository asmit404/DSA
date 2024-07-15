#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

bool checkAnagram(const string &s1, const string &s2)
{
    // If lengths of the strings are not equal, they cannot be anagrams
    if (s1.length() != s2.length())
        return false;

    // Create a hash map to count occurrences of each character
    unordered_map<char, int> count;

    // Increment count for characters in s1 and decrement for characters in s2
    for (int i = 0; i < s1.length(); i++)
    {
        count[s1[i]]++;
        count[s2[i]]--;
    }

    // Check if all counts are zero
    for (const auto &entry : count)
    {
        if (entry.second != 0)
            return false;
    }
    return true;
}

int main()
{
    string str1, str2;
    cout << "Enter the first string: ";
    getline(cin, str1);
    cout << "Enter the second string: ";
    getline(cin, str2);
    // Check if the two strings are anagrams and print the result
    if (checkAnagram(str1, str2))
        cout << "The two strings are anagram of each other";
    else
        cout << "The two strings are not anagram of each other";
    return 0;
}