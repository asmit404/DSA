#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to fill the Longest Prefix Suffix (LPS) array
void fillLPS(const string &pattern, vector<int> &lpsArray)
{
    int patternLength = pattern.length(), length = 0;
    lpsArray[0] = 0;
    int index = 1;
    while (index < patternLength)
    {
        if (pattern[index] == pattern[length])
        {
            length++;
            lpsArray[index] = length;
            index++;
        }
        else
        {
            if (length == 0)
            {
                lpsArray[index] = 0;
                index++;
            }
            else
            {
                length = lpsArray[length - 1];
            }
        }
    }
}

// Function to perform KMP pattern matching algorithm
void KMP(const string &pattern, const string &text)
{
    int textLength = text.length();
    int patternLength = pattern.length();
    vector<int> lpsArray(patternLength);
    fillLPS(pattern, lpsArray);
    int textIndex = 0, patternIndex = 0;
    while (textIndex < textLength)
    {
        if (pattern[patternIndex] == text[textIndex])
        {
            textIndex++;
            patternIndex++;
        }

        if (patternIndex == patternLength)
        {
            cout << "Found pattern at index " << textIndex - patternIndex << " " << endl;
            patternIndex = lpsArray[patternIndex - 1];
        }
        else if (textIndex < textLength && pattern[patternIndex] != text[textIndex])
        {
            if (patternIndex == 0)
                textIndex++;
            else
                patternIndex = lpsArray[patternIndex - 1];
        }
    }
}

int main()
{
    string text, pattern;
    cout << "Enter the text: ";
    getline(cin, text);
    cout << "Enter the pattern: ";
    getline(cin, pattern);
    KMP(pattern, text);
    return 0;
}