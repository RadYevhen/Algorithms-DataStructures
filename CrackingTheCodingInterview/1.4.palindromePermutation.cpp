// Palindrome Permutation: Given a string, write a function to check if it is a permutation of a palindrome.
// A palindrome is a word or phrase that is the same forwards and backwards. A permutation
// is a rea rrangement of letters. The palindrome does not need to be limited to just dictionary words.
// EXAMPLE
// Input: Tact Coa
// Output: True (permutations: "taco cat". "atco cta". etc.)

#include <iostream>
#include <string>
#include <cctype>
#include <unordered_map>

using namespace std;

// Approach 1: to be palindrome string should contain exactly one character with odd count
// 1. Count all characters apart from space, turn to lower case and store result in hash table
// 2. How many odd count of characters in the Hash Table
// 3. If such char only one OR zero - return true, otherwise false
bool arePalindromePermutation( string str )
{
    unordered_map<char, int> um;
    int odd = 0;

    // 1. Count all characters apart from space, turn to lower case and store result in hash table - O(N) where N length of str
    for (int i = 0; i < str.length(); ++i)
    {
        if (!isspace(str[i]))
        {
            um[tolower(str[i])]++;       
        }
    }

    // 2. How many odd count of characters in the Hash Table - O(M) where M number of unique characters in the string
    for (auto it : um)
    {
        if (it.second % 2 != 0)
        {
            ++odd;
        }
        if( odd > 1 ) return false;
    }
    
    // 3. If such char only one OR there is no such char and number of characters in the hash table is not odd - return true, otherwise false(checked in the loop)
    return true;
}

int main()
{
    cout << arePalindromePermutation( "Tact Coa" ) << endl; // 1
    cout << arePalindromePermutation( "aAa" ) << endl; // 1
    cout << arePalindromePermutation( "aAaBb" ) << endl; // 1
    cout << arePalindromePermutation( "aA" ) << endl; // 1
    cout << arePalindromePermutation( "aAbb" ) << endl; // 1
    cout << arePalindromePermutation( "aaa bbb" ) << endl; // 0
    cout << arePalindromePermutation( "aaA Bbb" ) << endl; // 0

    return 0;
}