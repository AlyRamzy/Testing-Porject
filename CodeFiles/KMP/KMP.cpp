#include "KMP.h"

/**
 * @brief Returns prefix function of a string
 * 
 * @param str 
 * @return vector<int> Prefix function array
 */
vector<int> KMP::PrefixFunction(string str)
{
    int len = str.length();

    vector<int> LongestPrefix(len);

    for(int i = 1, k = 0; i < len; i++)
    {
        while(k > 0 && str[k] != str[i])
            k = LongestPrefix[k-1];
        
        if(str[k] == str[i])
            LongestPrefix[i] = ++k;
        else
            LongestPrefix[i] = k;
    }
    
    return LongestPrefix;
}

/**
 * @brief Returns an array of positions in which pattern exists in a string
 * 
 * @param str 
 * @param pattern 
 * @return vector<int> Array of positions
 */
vector<int> KMP::ApplyKMP(string str, string pattern)
{
    int StringLength = str.length(), PatternLength = pattern.length();

    if(StringLength == 0 || PatternLength == 0)
        return vector<int>();
        
    vector<int>LongestPrefix = PrefixFunction(pattern);

    vector<int> result;
    for(int i = 0, k = 0; i < StringLength; i++)
    {
        while(k > 0 && str[i] != pattern[k])
            k = LongestPrefix[k-1];
        
        if(pattern[k] == str[i])
            k++;
        
        if(k == PatternLength) //found a match
        {
            result.push_back(i-PatternLength+1);
            k = LongestPrefix[k-1];
        }
    }

    return result;
}
