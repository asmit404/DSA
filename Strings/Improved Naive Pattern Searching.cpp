#include <iostream>
#include <string_view>

using namespace std;

void patSearchingImproved(string_view txt, string_view pat)
{
    int m = pat.length();
    int n = txt.length();
    // Loop through the text to find the pattern
    for (int i = 0; i <= (n - m);)
    {
        int j;
        // Check for pattern match
        for (j = 0; j < m; j++)
            if (pat[j] != txt[i + j])
                break;
        // If pattern is found, print the index
        if (j == m)
            cout << i << " ";
        // If no characters matched, move to the next character in text
        if (j == 0)
        {
            i++;
        }
        // If some characters matched, skip the matched characters
        else
        {
            i = (i + j);
        }
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
    patSearchingImproved(txt, pat);
    return 0;
}