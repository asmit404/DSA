#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool isPalindrome(const string &str)
{
    int left = 0, right = str.length() - 1; // Initialize pointers to the start and end of the string

    while (left < right)
    {
        // Skip non-alphanumeric characters from the left
        while (left < right && !isalnum(str[left]))
            left++;

        // Skip non-alphanumeric characters from the right
        while (left < right && !isalnum(str[right]))
            right--;

        // Compare characters case-insensitively
        if (tolower(str[left]) != tolower(str[right]))
        {
            return false; // Return false if characters do not match
        }
        left++;  // Move left pointer to the right
        right--; // Move right pointer to the left
    }
    return true; // Return true if all characters match
}

int main()
{
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    cout << "\"" << str << "\" is " << (isPalindrome(str) ? "" : "not ") << "a palindrome." << endl;
    return 0;
}