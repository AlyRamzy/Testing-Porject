#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../CodeFiles/InsertionSort/insertionSort.h"
#include "../Tool/doctest.h"
TEST_SUITE("Correctness")
{
    TEST_CASE("Sort array  with reversed order")
    {
        int arr[] = { 5,4,3,2,1 };
        int n = sizeof(arr) / sizeof(arr[0]);
        int arr1[] = { 5,4,3,2,1 };
        insertionSort(arr, n);
        int tmpN = n;
        for (int i = 0; i < n; i++)
        {
            CHECK(arr[i] == arr1[tmpN - 1]);
            tmpN--;
        }
    }
    TEST_CASE("Sort one element array")
    {
        int arr[] = { 12 };
        int arr_size = sizeof(arr) / sizeof(arr[0]);

        insertionSort(arr, arr_size);
        int sortedArr[] = { 12 };
        for (int i = 0; i < arr_size; i++)
        {
            CHECK(sortedArr[i] == arr[i]);
        }
    }
    TEST_CASE("Sort null pointer array")
    {
        int* arr = NULL;
        int arr_size = sizeof(arr) / sizeof(arr[0]);
        CHECK_NOTHROW(insertionSort(arr, arr_size));
    }
    TEST_CASE("Sort already sorted array")
    {
        int arr[] = { 4, 6, 10, 12, 15, 23, 28, 35 };
        int arr_size = sizeof(arr) / sizeof(arr[0]);

        insertionSort(arr, arr_size);
        int sortedArr[] = { 4, 6, 10, 12, 15, 23, 28, 35 };
        for (int i = 0; i < arr_size; i++)
        {
            CHECK(sortedArr[i] == arr[i]);
        }
    }
    TEST_CASE("Sort array with negative elements")
    {
        int arr[] = { 12, 15, -23, -4, 6, 10, -35, 28 };
        int arr_size = sizeof(arr) / sizeof(arr[0]);

        insertionSort(arr, arr_size);
        int sortedArr[] = { -35, -23, -4, 6, 10, 12, 15, 28 };
        for (int i = 0; i < arr_size; i++)
        {
            CHECK(sortedArr[i] == arr[i]);
        }
    }
    TEST_CASE("Sort array with duplicate elements")
    {
        int arr[] = { 12, 12, 23, 4, 6, 6, 10, -35, 28 };
        int arr_size = sizeof(arr) / sizeof(arr[0]);

        insertionSort(arr, arr_size);
        int sortedArr[] = { -35, 4, 6, 6, 10, 12, 12, 23, 28 };
        for (int i = 0; i < arr_size; i++)
        {
            CHECK(sortedArr[i] == arr[i]);
        }
    }
    TEST_CASE("Sort array with Same element")
    {
        int arr[] = { 12, 12, 12, 12, 12 };
        int arr_size = sizeof(arr) / sizeof(arr[0]);

        insertionSort(arr, arr_size);
        int sortedArr[] = { 12, 12, 12, 12, 12 };
        for (int i = 0; i < arr_size; i++)
        {
            CHECK(sortedArr[i] == arr[i]);
        }
    }
}

TEST_SUITE("Performance")
{

    TEST_CASE("Time Complexity: O(n) where n is the size of the sorted array." * doctest::timeout(1 / 100000))
    {
        int arr[int(1e3)];
        for (int i = 0; i < int(1e3); i++)
        {
            arr[i] = i;
        }
        int arr_size = sizeof(arr) / sizeof(arr[0]);
        insertionSort(arr, arr_size - 1);
    }

    TEST_CASE("Time Complexity: O(n^2) where n is the size of the reversed sorted array." * doctest::timeout(1 / 10000))
    {
        int arr[int(1e2)];
        for (int i = int(1e2) - 1; i >= 0; i--)
        {
            arr[i] = i;
        }
        int arr_size = sizeof(arr) / sizeof(arr[0]);
        insertionSort(arr, arr_size);
    }

    TEST_CASE("Time Complexity: O(n^2) where n is the size of the unsorted array." * doctest::timeout(1 / 10000))
    {
        int arr[int(1e2)];
        for (int i = 0; i < int(1e2); i++)
        {
            arr[i] = rand();
        }
        int arr_size = sizeof(arr) / sizeof(arr[0]);
        insertionSort(arr, arr_size - 1);
    }
}


