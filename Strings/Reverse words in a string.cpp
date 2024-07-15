#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void revWords(string &str)
{
    // Reverse the entire string
    reverse(str.begin(), str.end());
    int n = str.length();
    int start = 0;

    // Traverse the string to reverse each word
    for (int end = 0; end <= n; end++)
    {
        // If end of word or end of string is reached
        if (end == n || str[end] == ' ')
        {
            // Reverse the current word
            reverse(str.begin() + start, str.begin() + end);
            // Move start to the next word
            start = end + 1;
        }
    }
}

int main()
{
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    cout << "After reversing words in the string:" << endl;
    revWords(str);
    cout << str << endl;
    return 0;
}