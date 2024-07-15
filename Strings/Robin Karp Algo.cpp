#include <iostream>
#include <string>

using namespace std;

#define size 256
const int prime = 101;

void RobinKarpSearch(const string &pattern, const string &text)
{
    int patternLength = pattern.length();
    int textLength = text.length();

    // If pattern length is greater than text length, no matches can be found
    if (patternLength > textLength)
    {
        cout << "Pattern length is greater than text length. No matches found." << endl;
        return;
    }

    int h = 1;
    // Calculate the value of h (pow(d, M-1) % q)
    for (int i = 1; i < patternLength; i++)
        h = (h * size) % prime;

    int patternHash = 0, textHash = 0;
    // Calculate the hash value of pattern and first window of text
    for (int i = 0; i < patternLength; i++)
    {
        patternHash = (patternHash * size + pattern[i]) % prime;
        textHash = (textHash * size + text[i]) % prime;
    }

    // Slide the pattern over text one by one
    for (int i = 0; i <= textLength - patternLength; i++)
    {
        // Check the hash values of current window of text and pattern
        if (patternHash == textHash)
        {
            // If the hash values match, then only check for characters one by one
            bool match = true;
            for (int j = 0; j < patternLength; j++)
            {
                if (text[i + j] != pattern[j])
                {
                    match = false;
                    break;
                }
            }
            // If pattern is found, print the index
            if (match)
                cout << i << " ";
        }

        // Calculate hash value for next window of text: Remove leading digit, add trailing digit
        if (i < textLength - patternLength)
        {
            textHash = (size * (textHash - text[i] * h) + text[i + patternLength]) % prime;
            // We might get negative value of textHash, converting it to positive
            if (textHash < 0)
                textHash = textHash + prime;
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
    cout << "All index numbers where pattern found: ";
    RobinKarpSearch(pattern, text);
    return 0;
}