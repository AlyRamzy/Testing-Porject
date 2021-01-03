#define DOCTEST_CONFIG_IMPLEMENTATION_IN_DLL
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

TEST_SUITE("Performance")
{

    TEST_CASE("Time Complexity: O(nm) where n and m is the size of the two similar arrays." * doctest::timeout(0.3))
    {
        char arr1[int(1e3)];
        char arr2[int(1e3)];
        int j;
        for (int i = 0; i < int(1e3); i++)
        {
            j = i%10;
            arr1[i] == char(j);
            arr2[i] == char(j);
        }
        int arr1_size = strlen(arr1);
        int arr2_size = strlen(arr2);
        int n = lcs(arr1, arr2, arr1_size, arr2_size);
    }

    TEST_CASE("Time Complexity: O(nm) where n and m is the size of the tow unsimilar arrays." * doctest::timeout(0.3))
    {
        char arr1[int(1e3)];
        char arr2[int(1e3)];
        int j, k;
        for (int i = 0; i < int(1e3); i++)
        {
            j = rand()%10;
            k = rand()%10;
            arr1[i] == char(j);
            arr2[i] == char(k);
        }
        int arr1_size = strlen(arr1);
        int arr2_size = strlen(arr2);
        int n = lcs(arr1, arr2, arr1_size, arr2_size);
    }
}

