#include <iostream>
#include <string>
using namespace std;

bool rotationCheck(const string& s1, const string& s2)
{
    if (s1.length() != s2.length())
    {
        return false;
    }
    string temp = s1 + s1;
    return temp.find(s2) != string::npos;
}

int main()
{
    string s1, s2;
    cout << "Enter the first string: ";
    getline(cin, s1);
    cout << "Enter the second string: ";
    getline(cin, s2);
    cout << (rotationCheck(s1, s2) ? "Yes" : "No") << endl;
    return 0;
}