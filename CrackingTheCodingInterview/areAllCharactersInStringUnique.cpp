// 1.1 Is Unique: Implement an algorithm to determine if a string has all unique characters. What if you cannot use additional data structures?
// Solution 1 sorting: Sort string and check for two same characters. TC O(NlogN) - because of sorting
// Solution 2 HashTable: Adding elements to hash table. When character already exist - string is not unique. TC O(N)
#include <iostream>
#include <String>
#include <algorithm> // for sort()
#include <unordered_map>

using namespace std;

// Solution 1 sorting: Sort string and check for two same characters. TC O(NlogN) - because of sorting
bool isUniqueSorting(string str)
{
    sort(str.begin(), str.end());

    for(int i = 0; i < str.length() - 1; ++i)
    {
        if( str[i] == str[i+1] ) { return false; }
    }

    return true;
}

// Solution 2 HashTable: Adding elements to hash table. When character already exist - string is not unique. TC O(N)
bool isUniqueHashTable(const string &str)
{
    unordered_map<char, int> um;
    for (int i = 0; i < str.length()-1; ++i)
    {
        // If character already exist
        if(um[str[i]] > 0) { return false; }
        // Otherwise add character
        um[str[i]]++;
    }
    return true;
}

int main()
{
    // Test 1 - No
    if(isUniqueHashTable("unique")) { cout << "Yes" << endl; }
    else { cout << "No" << endl; }

    // Test 2 - No
    if(isUniqueHashTable("hello")) { cout << "Yes" << endl; }
    else { cout << "No" << endl; }

    // Test 3 - Yes
    if(isUniqueHashTable("abcds")) { cout << "Yes" << endl; }
    else { cout << "No" << endl; }

    return 0;
}
