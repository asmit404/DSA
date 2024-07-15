#include <iostream>
#include <string>
using namespace std;

void patSearching(const string &txt, const string &pat)
{
    int m = pat.length();
    int n = txt.length();
    // Loop to slide pat[] one by one
    for (int i = 0; i <= (n - m); i++)
    {
        int j;
        // For current index i, check for pattern match
        for (j = 0; j < m; j++)
            if (pat[j] != txt[i + j])
                break;
        // If pat[0...m-1] = txt[i, i+1, ...i+m-1]
        if (j == m)
            cout << i << " "; // Pattern found at index i
    }
}

int main()
{
    string txt, pat;
    cout << "Enter the text: ";
    getline(cin, txt);
    cout << "Enter the pattern: ";
    getline(cin, pat);
    cout << "All index numbers where pattern found: ";
    patSearching(txt, pat);
    return 0;
}