#define DOCTEST_CONFIG_IMPLEMENTATION_IN_DLL

#include "../CodeFiles/BinarySearch/BinarySearch.h"
#include "../Tool/doctest.h"
#include <iostream>
using namespace std;

TEST_SUITE("Correctness")
{
        TEST_CASE("Search in empty array")
        {
                int arr[] = {};

                SUBCASE("check that no throw for exception")
                {
                        CHECK_NOTHROW(binarySearch(arr, 0, -1, 1));
                }
                SUBCASE("check not exist")
                {
                        int result = binarySearch(arr, 0, -1, 1);
                        CHECK(result == -1);
                }
        }

        TEST_CASE("Search in sorted array with odd number of elements for non-exist element")
        {
                int arr[] = {0, 2, 4, 6, 8, 10, 12, 14, 16};

                int n = sizeof(arr) / sizeof(arr[0]);
                int result = binarySearch(arr, 0, n - 1, 9);
                CHECK(result == -1);
        }

        TEST_CASE("Search in sorted array with even number of elements for non-exist element")
        {
                int arr[] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18};

                int n = sizeof(arr) / sizeof(arr[0]);
                int result = binarySearch(arr, 0, n - 1, 9);
                CHECK(result == -1);
        }

        TEST_CASE("Search in sorted array for the first element")
        {
                int arr[] = {0, 2, 4, 6, 8, 10, 12, 14, 16};

                int n = sizeof(arr) / sizeof(arr[0]);
                int result = binarySearch(arr, 0, n - 1, 0);
                CHECK(result == 0);
        }

        TEST_CASE("Search in sorted array for the last element")
        {
                int arr[] = {0, 2, 4, 6, 8, 10, 12, 14, 16};

                int n = sizeof(arr) / sizeof(arr[0]);
                int result = binarySearch(arr, 0, n - 1, 16);
                CHECK(result == n - 1);
        }

        TEST_CASE("Search in sorted array for the middle element")
        {
                int arr[] = {0, 2, 4, 6, 8, 10, 12, 14, 16};

                int n = sizeof(arr) / sizeof(arr[0]);
                int result = binarySearch(arr, 0, n - 1, 8);
                CHECK(result == int(n / 2));
        }

        TEST_CASE("Search in sorted array for all the elements in the array")
        {
                int arr[] = {0, 2, 4, 6, 8, 10, 12, 14, 16};

                int n = sizeof(arr) / sizeof(arr[0]);
                for (int i = 0; i < n; i++)
                {
                        int result = binarySearch(arr, 0, n - 1, arr[i]);
                        CHECK(result == i);
                }
        }
        TEST_CASE("Search in sorted array for non-existing elements ")
        {
                int arr[] = {0, 2, 4, 6, 8, 10, 12, 14, 16};

                int n = sizeof(arr) / sizeof(arr[0]);
                for (int i = 0; i < n; i++)
                {
                        int result = binarySearch(arr, 0, n - 1, arr[i] + 1);
                        CHECK(result == -1);
                }
        }
}

TEST_SUITE("Performance")
{
        TEST_CASE("Time Complexity: O(logn) where n is the size of the sorted array." * doctest::timeout(0.005))
        {
                int arr[int(1e6)];
                for (int i = 0; i < int(1e6); i++)
                {
                        arr[i] == i;
                }
                int arr_size = sizeof(arr) / sizeof(arr[0]);
                binarySearch(arr, 0, arr_size - 1, rand());
                MESSAGE("Binary Search performance test passed");
        }
}
