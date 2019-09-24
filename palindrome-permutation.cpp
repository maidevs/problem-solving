//Solution to check if a string is a permutation of a palindrome

#include <iostream>
#include <unordered_map>

using namespace std;

bool isPalindromePermutation(string s)
{
    unordered_map<char, int> mp;
    
    for(auto &c : s)
    {
        if(c != ' ')
            mp[c]++;
    }
    
    int oddLimit = 1;

    for(auto &k : mp)
    {
        
        int val = mp[k.first];
        if(val > 0 && val % 2 != 0)
        {
            if(oddLimit > 0)
                oddLimit--;
            else
                return false;
        }
    }

    return true;
}

int main()
{
    string ss [] = { "aabs", "aab", "tactcoa", "tact coa", "ab" , "a", "abcab" };
    
    for(auto &s : ss)
        cout << isPalindromePermutation(s) << endl;
    
}
