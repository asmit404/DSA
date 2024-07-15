#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int longestDistinct(string str)
{
    int n = str.length();
    int res = 0;
    unordered_map<char, int> lastIndex;
    int start = 0;

    for (int end = 0; end < n; end++)
    {
        if (lastIndex.find(str[end]) != lastIndex.end())
        {
            start = max(start, lastIndex[str[end]] + 1);
        }
        res = max(res, end - start + 1);
        lastIndex[str[end]] = end;
    }
    return res;
}

int main()
{
    string str;
    cout << "Enter the string: ";
    getline(cin, str);
    cout << "The length of the longest distinct characters substring is " << longestDistinct(str);
    return 0;
}