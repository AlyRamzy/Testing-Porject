#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_SUPER_FAST_ASSERTS

#include "../CodeFiles/Palindromic Substrings/LongestPalindromicSubString.h"
#include "../Tool/doctest.h"

TEST_SUITE("Correctness")
{
    TEST_CASE("Odd Length Answer Test")
    {
        LongestPalindromicSubString Obj;
        SUBCASE("Multiple Substrings with Maximum Length")
        {
            string str = "abbbacdddcefffexyz";
            REQUIRE_EQ(Obj.Solve(str), 5);
        }
        SUBCASE("Single SubString with Maximum Length")
        {
            string str = "abbbaxyz";
            REQUIRE_EQ(Obj.Solve(str), 5);
        }
        cout<<"Odd Length Answer Test Passed"<<endl;
    }
    TEST_CASE("Even Length Answer Test")
    {
        LongestPalindromicSubString Obj;
        SUBCASE("Multiple Substrings with Maximum Length")
        {
            string str = "abbacddceffexyz";
            REQUIRE_EQ(Obj.Solve(str), 4);
        }
        SUBCASE("Single SubString with Maximum Length")
        {
            string str = "abbaxyz";
            REQUIRE_EQ(Obj.Solve(str), 4);
        }
        cout<<"Even Length Answer Test Passed"<<endl;
    }
    TEST_CASE("All Characters Distinct Test")
    {
        LongestPalindromicSubString Obj;
        string str = "abcdefghi";
        REQUIRE_EQ(Obj.Solve(str), 1);
        cout<<"All Characters Distinct Test Passed"<<endl;
    }
    TEST_CASE("Empty String Test")
    {
        LongestPalindromicSubString Obj;
        string str = "";
        REQUIRE_EQ(Obj.Solve(str), 0);
        cout<<"Empty String Test Passed"<<endl;
    }
}

TEST_SUITE("Performance")
{
    TEST_CASE("Test O(n^2) implementation" * doctest::timeout(1))
    {
        string str = "";
        for(int i = 0; i < 5e3; i++)
            str += "a";
        LongestPalindromicSubString Obj;
        Obj.Solve(str);
        
        cout<<"Performance Test Passed"<<endl;
    }
}