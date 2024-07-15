#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Iterative solution
bool isSubIter(const string &s1, const string &s2)
{
    int j = 0;
    int m = s2.length();

    // Iterate through each character in s1
    for (char c : s1)
    {
        // If characters match, move to the next character in s2
        if (j < m && c == s2[j])
            j++;
    }
    // If all characters in s2 were found in s1 in order, return true
    return j == m;
}

// Recursive solution with DP
bool isSubRec(string s1, string s2, int n, int m)
{
    // Create a 2D vector to store the results of subproblems
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

    // Initialize the first column to true, as an empty string is a subsequence of any string
    for (int i = 0; i <= n; ++i)
        dp[i][0] = true;

    // Fill the dp table
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            // If characters match, take the value from the diagonal cell
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            // If characters don't match, take the value from the cell above
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    // The result is in the bottom-right cell of the table
    return dp[n][m];
}

int main()
{
    int n, m;
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    n = s1.length();
    m = s2.length();
    cout << boolalpha << "Iterative Solution: " << isSubIter(s1, s2) << endl;
    cout << boolalpha << "Recursive Solution: " << isSubRec(s1, s2, n, m) << endl;
    return 0;
}