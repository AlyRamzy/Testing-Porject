#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../CodeFiles/QuickSort/quick_sort.h"
#include "../Tool/doctest.h"
#include <stdlib.h>

TEST_SUITE("Correctness")
{
	TEST_CASE("Sort array with even number of elements")
	{
		int arr[] = {12, 15, 23, 4, 6, 10, 35, 28};
		int arr_size = sizeof(arr) / sizeof(arr[0]);

		quickSort(arr, 0, arr_size - 1);
		int sortedArr[] = {4, 6, 10, 12, 15, 23, 28, 35};
		for (int i = 0; i < arr_size; i++)
		{
			CHECK(sortedArr[i] == arr[i]);
		}
	}
	TEST_CASE("Sort empty array")
	{
		int arr[] = {};

		CHECK_NOTHROW(quickSort(arr, 0, -1));
	}

	TEST_CASE("Sort null pointer array")
	{
		int *arr = NULL;

		CHECK_NOTHROW(quickSort(arr, 0, -1));
	}

	TEST_CASE("Sort already sorted array")
	{
		int arr[] = {4, 6, 10, 12, 15, 23, 28, 35};
		int arr_size = sizeof(arr) / sizeof(arr[0]);

		quickSort(arr, 0, arr_size - 1);
		int sortedArr[] = {4, 6, 10, 12, 15, 23, 28, 35};
		for (int i = 0; i < arr_size; i++)
		{
			CHECK(sortedArr[i] == arr[i]);
		}
	}
	TEST_CASE("Sort array with odd number of elements")
	{
		int arr[] = {12, 15, 23, 4, 6, 10, 35};
		int arr_size = sizeof(arr) / sizeof(arr[0]);

		quickSort(arr, 0, arr_size - 1);
		int sortedArr[] = {4, 6, 10, 12, 15, 23, 35};
		for (int i = 0; i < arr_size; i++)
		{
			CHECK(sortedArr[i] == arr[i]);
		}
	}

	TEST_CASE("Sort descending sorted array")
	{
		int arr[] = {35, 28, 23, 15, 12, 10, 6, 4};
		int arr_size = sizeof(arr) / sizeof(arr[0]);

		quickSort(arr, 0, arr_size - 1);
		int sortedArr[] = {4, 6, 10, 12, 15, 23, 28, 35};
		for (int i = 0; i < arr_size; i++)
		{
			CHECK(sortedArr[i] == arr[i]);
		}
	}

	TEST_CASE("Sort one element array")
	{
		int arr[] = {12};
		int arr_size = sizeof(arr) / sizeof(arr[0]);

		quickSort(arr, 0, arr_size - 1);
		int sortedArr[] = {12};
		for (int i = 0; i < arr_size; i++)
		{
			CHECK(sortedArr[i] == arr[i]);
		}
	}

	TEST_CASE("Sort two element array")
	{
		int arr[] = {12, 4};
		int arr_size = sizeof(arr) / sizeof(arr[0]);

		quickSort(arr, 0, arr_size - 1);
		int sortedArr[] = {4, 12};
		for (int i = 0; i < arr_size; i++)
		{
			CHECK(sortedArr[i] == arr[i]);
		}
	}

	TEST_CASE("Sort array with negative elements")
	{
		int arr[] = {12, 15, -23, -4, 6, 10, -35, 28};
		int arr_size = sizeof(arr) / sizeof(arr[0]);

		quickSort(arr, 0, arr_size - 1);
		int sortedArr[] = {-35, -23, -4, 6, 10, 12, 15, 28};
		for (int i = 0; i < arr_size; i++)
		{
			CHECK(sortedArr[i] == arr[i]);
		}
	}

	TEST_CASE("Sort array with duplicate elements")
	{
		int arr[] = {12, 12, 23, 4, 6, 6, 10, -35, 28};
		int arr_size = sizeof(arr) / sizeof(arr[0]);

		quickSort(arr, 0, arr_size - 1);
		int sortedArr[] = {-35, 4, 6, 6, 10, 12, 12, 23, 28};
		for (int i = 0; i < arr_size; i++)
		{
			CHECK(sortedArr[i] == arr[i]);
		}
	}

	TEST_CASE("Sort array with Same element")
	{
		int arr[] = {12, 12, 12, 12, 12};
		int arr_size = sizeof(arr) / sizeof(arr[0]);

		quickSort(arr, 0, arr_size - 1);
		int sortedArr[] = {12, 12, 12, 12, 12};
		for (int i = 0; i < arr_size; i++)
		{
			CHECK(sortedArr[i] == arr[i]);
		}
	}
}

TEST_SUITE("Performance")
{

	TEST_CASE("Time Complexity: O(n^2) where n is the size of the sorted array." * doctest::timeout(1.2))
	{
		int arr[int(1e4)];
		for (int i = 0; i < int(1e4); i++)
		{
			arr[i] == i;
		}
		int arr_size = sizeof(arr) / sizeof(arr[0]);
		quickSort(arr, 0, arr_size - 1);
	}

	TEST_CASE("Time Complexity: O(n^2) where n is the size of the reversed sorted array." * doctest::timeout(1.2))
	{
		int arr[int(1e4)];
		for (int i = int(1e4) - 1; i >= 0; i--)
		{
			arr[i] == i;
		}
		int arr_size = sizeof(arr) / sizeof(arr[0]);
		quickSort(arr, 0, arr_size - 1);
	}

	TEST_CASE("Time Complexity: O(nlogn) where n is the size of the unsorted array." * doctest::timeout(0.2))
	{
		int arr[int(1e6)];
		for (int i = 0; i < int(1e6); i++)
		{
			arr[i] == rand();
		}
		int arr_size = sizeof(arr) / sizeof(arr[0]);
		quickSort(arr, 0, arr_size - 1);
	}
}
