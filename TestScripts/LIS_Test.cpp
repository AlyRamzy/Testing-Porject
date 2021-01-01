
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../CodeFiles/LIS/LIS.h"
#include "../Tool/doctest.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

TEST_SUITE("Correctness")
{

    TEST_CASE("Array is empty")
    {
        int arr[] = { }; 

        int n = sizeof(arr) / sizeof(arr[0]); 

        CHECK(lis(arr, n)==0);
    }

    TEST_CASE("Array with one element")
    {
        int arr[] = { 10 }; 

        int n = sizeof(arr) / sizeof(arr[0]); 

        CHECK(lis(arr, n)==1);
    }

    TEST_CASE("Array with descending sequence")
    {
        int arr[] = { 10, 9, 8, 7, 6, 5, 4, 3 }; 

        int n = sizeof(arr) / sizeof(arr[0]); 

        CHECK(lis(arr, n)==1);
    }

    TEST_CASE("Array with ascending sequence")
    {
        int arr[] = { 1, 2, 3, 4, 5, 6, 7 }; 

        int n = sizeof(arr) / sizeof(arr[0]); 

        CHECK(lis(arr, n)==7);
    }

    TEST_CASE("Array with descending sequence not connected")
    {
        int arr[] = { 10, 15, 9, 5, 8, 7 }; 

        int n = sizeof(arr) / sizeof(arr[0]); 

        CHECK(lis(arr, n)==2);
    }

    TEST_CASE("Array with ascending sequence not connected")
    {
        int arr[] = { 1, 50, 2, 58, 3, 40, 4, 1, 5, 2, 6, 7 }; 

        int n = sizeof(arr) / sizeof(arr[0]); 

        CHECK(lis(arr, n)==7);
    }

    TEST_CASE("Array with more than one sequence")
    {
        int arr[] = { 10, 5, 11, 12, 8, 9 }; 

        int n = sizeof(arr) / sizeof(arr[0]); 

        CHECK(lis(arr, n)==3);
    }

    TEST_CASE("The first element in the array is not hte first elemant in the sequence")
    {
        int arr[] = { 10, 5, 11, 6, 12, 7, 13, 14, 8, 9, 10 }; 

        int n = sizeof(arr) / sizeof(arr[0]); 

        CHECK(lis(arr, n)==6);
    }


}

// TEST_SUITE("Performance")
// {

// }