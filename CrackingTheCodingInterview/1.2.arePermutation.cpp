// Check if one string is permutation of another
// Case 1: s1 = "abc", s2 = "ddcbaaa" - true because s2 contains "cba"
// Case 2: s1 = "abc", s2 = "ddabcaa" - true because s2 contains "abc"
// Case 3: s1 = "abc", s2 = "ddaaacc" - false because s2 doesn't contain "cba", "abc", "acb"
// Case 4: s1 = "ab", s2 = "ab" - true 
// Case 5: s1 = "abc", s2 = "aaaabbcccc" - false
// Case 6: s1 = "abc", s2 = "aaacabccc" - true 
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <array>

using namespace std;

// Sorting solution - sort s1, sort substring from s2(length of s1) and if s1 = substring from s2 - permutation exists
// TC - O(M*NlogN) where M - length of s2 and N length of s1(and s2 substring). NlogN - for merge sort. Space - O(N) for additional string with length of s1
bool arePermutationSortingBruteForce(string s1, string s2)
{
    if(s1.length() > s2.length()) return false;
    sort(s1.begin(), s1.end()); // O(NlogN) if merge sort used

    // Go through s2 while it's possible to take substring of s1 length
    for (int i = 0; i <= s2.length() - s1.length(); ++i) // O(M) where M length of s2 
    {
        string s2_substr = s2.substr(i, s1.length()); // O(N) where N length of s1
        sort(s2_substr.begin(), s2_substr.end()); // O(NlogN) if merge sort used
        if(s1 == s2_substr) // O(N) where N length of s1/s2_substr
        {
            return true;
        }
    }
    return false;
}

// Brute force solution: O(N*M) where N - length of s1, M - length of s2. Space - two hash tables for s1 and substring in s2
bool arePermutationBruteForce(string s1, string s2)
{
    unordered_map<char, int> um_s1;
    unordered_map<char, int> um_s2;

    // Add all characters and their count to hash table
    for(int i = 0; i < s1.length(); ++i) // O(N) where N length of s1
    {
        um_s1[s1[i]]++;
    }

    for (int i = 0; i < s2.length(); ++i) // O(M) where M length of s2
    {
        // If rest of s2 less then length of s1 - return false
        if(i + s1.length()-1 > s2.length()-1) return false;
        // When char from s2 exist in s1 - add all characters from substring to hash table for s2
        if(um_s1.find(s2[i]) != um_s1.end()) // O(1) in average case, O(K) if collisions exist, where K is number of keys in hash table
        {
            int j = i;
            // Take substring [current; current + s1.length()-1]
            while (j <= i + s1.length()-1) // O(N) where N length of s1 
            {
                um_s2[s2[j]]++;
                ++j;
            }
            // When hash table are equal - permutation was found
            if(um_s1 == um_s2) return true; // O(K) where K is number of keys in um_s1 
            um_s2.clear(); // O(K) where K is number of keys in um_s2
        }
    }
    return false;
}

// Fastest solution: in case we know that characters are small from latin alphabet from 'a' to 'z'(26 characters) we can use their ASCII codes: 'a' - 97, ..., 'z' - 122
// Step 1: Create 2 arrays with 26 elements, fill in both arrays with numbers of characters from s1 and s2: 'aabc' - arr[0]=2, arr[1]=1, arr[2]=1, arr[3]=0... 
// Receive correct index: char from string - 'a'. Example'aabc': 'a'(97) - 'a'(97) = 0, 'b'(98) - 'a'(97) = 1, 'c'(99) - 'a'(97) = 2
// Step 2: keep begin and end of substr from s2 with length of s1 - begin = 0, end = s1.length()-1
// Step 3: While we have enough characters to check substring in s2 - compare arrays, if not equal take next substring with new begin and end 
// but update array for s2 - increase value in index end and decrease value in index of old begin
bool arePermutation(string s1, string s2)
{
    if(s1.length() > s2.length()) return false;
    array<int, 26> s1_arr = {0}; // indicates which and how many characters in s1
    array<int, 26> s2_arr = {0}; // indicates which and how many characters in s2 substring with length of s1
    int begin = 0; // begin of s2 substring
    int end = s1.length()-1; // end of s2 substring

    // Fill in both arrays
    for (int i = 0; i < s1.length(); ++i)
    {
        s1_arr[s1[i] - 'a']++;
        s2_arr[s2[i] - 'a']++;
    }
    
    // While we are able to check next substring
    while(s2.length()-1 >= end)
    {
        // Check that arrays are equal
        if( s1_arr == s2_arr ) return true;
        ++end; // Take new end
        if(end > s2.length()-1) return false;
        s2_arr[s2[end] - 'a']++; // increment new end char from s2 array
        s2_arr[s2[begin] - 'a']--; // decrement old begin char from s2 array 
        ++begin; // take new begin
    }
    return false;
}
int main()
{

    cout << arePermutation("abc", "ddcbaaa") << endl; // 1
    cout << arePermutation("abc", "ddaaacc") << endl; // 0
    cout << arePermutation("abc", "ddcbbaaa") << endl; // 0
    cout << arePermutation("abc", "cba") << endl; // 1
    cout << arePermutation("c", "cba") << endl; // 1
    cout << arePermutation("abc", "cbadbac") << endl; // 1
    cout << arePermutation("ab", "ab") << endl; // 1
    cout << arePermutation("abc", "aaaabbcccc") << endl; // 0
    cout << arePermutation("abc", "aaacabccc") << endl; // 1

    return 0;
}