/*
Solution to find if one string is one edit away from another
There are three operations that can be done in the strings:
 - Insert one char
 - Delete one char
 - Replace one char

 So, there is only need for two checks, replacement and char difference.
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isOneAway(string s1, string s2)
{
    
    if(s1 == s2 || abs((int)(s1.size() - s2.size())) > 1)
    {
        return false;
    }

    int editNum = 0;
    if(s1.size() == s2.size())
    {
        for(int i = 0; i < s1.size(); i++)
        {
            if(s1[i] != s2[i])
            {
                if(editNum > 0)
                    return false;
                else 
                    editNum++;
            }
        }
    }
    else
    {
        string smaller;
        string bigger;

        if(s1.size() > s2.size())
        {
            bigger = s1;
            smaller = s2;
        }
        else
        {
            bigger = s2;
            smaller = s1;
        }

        for(int i = 0; i < smaller.size(); i++)
        {
            if(bigger[i] != smaller[i - editNum])
            {
                if(editNum > 0)
                    return false;
                else
                {
                    if(bigger[i + 1] == smaller[i])
                    {
                        editNum++;
                        i++;
                    }
                    else
                        return false;
                }
            }
        }
    }
        return editNum <= 1;
}

int main()
{                  
    //true true true true true false
    vector<string> s1  = {"pale", "pale", "romo", "a", "pele", "pale"};
    vector<string> s2  = {"psle", "psale", "rrmo", "ar","pale", "bake"};

    for(int i = 0; i < s1.size(); i++)
    {
        cout << isOneAway(s1[i], s2[i]);
    }
   
    return 0;
}