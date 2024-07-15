#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int CHAR = 256;

// Function to compute factorials up to n
void computeFactorials(vector<int> &factorials, int n)
{
    factorials[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        factorials[i] = factorials[i - 1] * i;
    }
}

// Function to calculate the lexicographic rank of a string
int lexRank(string &str)
{
    int n = str.length();
    vector<int> factorials(n + 1);
    computeFactorials(factorials, n);

    int count[CHAR] = {0};
    for (char character : str)
    {
        count[character]++;
    }

    for (int i = 1; i < CHAR; i++)
    {
        count[i] += count[i - 1];
    }

    int rank = 1;
    for (int i = 0; i < n; i++)
    {
        int mul = factorials[n - i - 1];
        rank += count[str[i] - 1] * mul;

        for (int j = str[i]; j < CHAR; j++)
        {
            count[j]--;
        }
    }

    return rank;
}

int main()
{
    string str;
    cout << "Enter the string: ";
    getline(cin, str);
    cout << lexRank(str);
    return 0;
}