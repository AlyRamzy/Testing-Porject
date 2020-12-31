
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../CodeFiles/LCS/LCS.h"
#include "../Tool/doctest.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

TEST_SUITE("Correctness")
{

    TEST_CASE("One of the two arrays is empty")
    {
        char X[] = ""; 
        char Y[] = "ABC"; 

        int m = strlen(X); 
        int n = strlen(Y);

        CHECK(lcs(X, Y, m, n)==0);
    }

    TEST_CASE("Both arrays are empty")
    {
        char X[] = ""; 
        char Y[] = ""; 

        int m = strlen(X); 
        int n = strlen(Y);

        CHECK(lcs(X, Y, m, n)==0);
    }

    TEST_CASE("One of the two arrays has one element, no match")
    {
        char X[] = "BCD"; 
        char Y[] = "A"; 

        int m = strlen(X); 
        int n = strlen(Y);

        CHECK(lcs(X, Y, m, n)==0);
    }

    TEST_CASE("Both arrays have one element, no match")
    {
        char X[] = "B"; 
        char Y[] = "A"; 

        int m = strlen(X); 
        int n = strlen(Y);

        CHECK(lcs(X, Y, m, n)==0);
    }

    TEST_CASE("All elements in one of the two arrays match")
    {
        char X[] = "ABC"; 
        char Y[] = "DEAGBRTTCFD"; 

        int m = strlen(X); 
        int n = strlen(Y);

        CHECK(lcs(X, Y, m, n)==3);
    }

    TEST_CASE("All elements of one of the two arrays exixts in the other but not in the same sequence")
    {
        char X[] = "ABC"; 
        char Y[] = "CXBXA"; 

        int m = strlen(X); 
        int n = strlen(Y);

        CHECK(lcs(X, Y, m, n)==1);
    }

    TEST_CASE("Both arrays are identical")
    {
        char X[] = "ABC"; 
        char Y[] = "ABC"; 

        int m = strlen(X); 
        int n = strlen(Y);

        CHECK(lcs(X, Y, m, n)==3);
    }

}

// TEST_SUITE("Performance")
// {

// }
