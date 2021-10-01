// Write a method to replace all spaces in a string with '%20: You may assume that the string
// has sufficient space at the end to hold the additional characters, and that you are given the "true"
// length of the string.
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string replaceAllSpaces(string str)
{
    string result;
    string insert = "%20";

    for(int i = 0; i < str.length(); ++i)
    {
        if(isspace(str[i]))
        {
            result.push_back(insert[0]);
            result.push_back(insert[1]);
            result.push_back(insert[2]);
        }
        else result.push_back(str[i]);
    }

    return result;
}

int main()
{
    cout << replaceAllSpaces("Mr John Smith") << endl;
    cout << replaceAllSpaces("Hello World ! ! !") << endl;
    cout << replaceAllSpaces("H   e   l   l   o") << endl;

    return 0;
}
