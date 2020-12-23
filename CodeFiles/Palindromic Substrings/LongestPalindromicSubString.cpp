#include "LongestPalindromicSubString.h"

/**
 * @brief Given a string it returns the length of the longest palindromic substring in it
 * 
 * @param str 
 * @return int 
 */
int LongestPalindromicSubString :: Solve(string str)
{
    int result = 0;

    for(int i = 0; i < str.length(); i++)
    {
        int l = i, r = i;
        while(l >= 0 && r < str.length() && str[l] == str[r])
        {
            result = max(result, r - l + 1);
            l--;
            r++;
        }
    }

    for(int i = 0; i < str.length() - 1; i++)
    {
        int l = i, r = i + 1;
        while(l >= 0 && r < str.length() && str[l] == str[r])
        {
            result = max(result, r - l + 1);
            l--;
            r++;
        }
    }
    return result;
}