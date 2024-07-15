#include <iostream>
#include <vector>
using namespace std;

const int CHAR = 256;

bool isPresent(const string &txt, const string &pat)
{
    if (pat.length() > txt.length())
        return false;

    // Initialize the count vector with the first window of text and pattern
    vector<int> count(CHAR, 0);
    for (int i = 0; i < pat.length(); i++)
    {
        count[pat[i]]++; // Increment count for pattern character
        count[txt[i]]--; // Decrement count for text character
    }

    int matches = 0; // Variable to count characters with zero count
    for (int i = 0; i < CHAR; i++)
    {
        if (count[i] == 0)
            matches++; // Increment matches if count is zero
    }

    // Slide the window over the text
    for (int i = pat.length(); i < txt.length(); i++)
    {
        // If all characters have zero count, anagram is found
        if (matches == CHAR)
            return true;

        int in = txt[i];
        int out = txt[i - pat.length()];

        // Update the count for the incoming character
        if (count[in] == 0)
            matches--; // Decrement matches if count was zero
        count[in]--;
        if (count[in] == 0)
            matches++; // Increment matches if count becomes zero

        // Update the count for the outgoing character
        if (count[out] == 0)
            matches--; // Decrement matches if count was zero
        count[out]++;
        if (count[out] == 0)
            matches++; // Increment matches if count becomes zero
    }
    return matches == CHAR;
}

int main()
{
    string txt, pat;
    cout << "Enter the text: ";
    getline(cin, txt);
    cout << "Enter the pattern: ";
    getline(cin, pat);
    cout << (isPresent(txt, pat) ? "Anagram found" : "Anagram not found");
    return 0;
}