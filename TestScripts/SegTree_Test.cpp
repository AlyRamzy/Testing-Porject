#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_SUPER_FAST_ASSERTS

#include "../CodeFiles/Segment Tree/SegTree.h"
#include "../Tool/doctest.h"
#include <chrono>
using namespace std::chrono;

TEST_SUITE("Correctness")
{
    TEST_CASE("Segment Tree Build With Valid Array Test")
    {
        vector<int>arr = {1,8,9,10,15,12,-1};
        MinSegTree Obj(arr);

        for(int i = 0; i < arr.size(); i++)
            REQUIRE_EQ(arr[i], Obj.GetMin(i,i));

        cout<<"Segment Tree Build With Valid Array Test Passed"<<endl;
    }
    TEST_CASE("Segment Tree Build With Empty Array Test")
    {
        vector<int>arr;
        MinSegTree Obj(arr);

        REQUIRE_EQ(INT_MAX, Obj.GetMin(0,0));

        cout<<"Segment Tree Build With Empty Array Test Passed"<<endl;
    }
    TEST_CASE("Segment Tree Update with Valid and Boundary Index Test")
    {
        vector<int>arr = {1,8,9,10,15,12,-1};
        MinSegTree Obj(arr);

        SUBCASE("Updating index 0")
        {
            Obj.Update(0, 15);
            REQUIRE_EQ(15, Obj.GetMin(0, 0));
        }
        SUBCASE("Updating index 3")
        {
            Obj.Update(3, 20);
            REQUIRE_EQ(20, Obj.GetMin(3, 3));
        }
        SUBCASE("Updating index 6")
        {
            Obj.Update(6, -10);
            REQUIRE_EQ(-10, Obj.GetMin(6, 6));
        }
        cout<<"Segment Tree Update with Valid and Boundary Index Test Passed"<<endl;
    }
    TEST_CASE("Segment Tree Update with Invalid Index Test")
    {
        vector<int>arr = {1,8,9,10,15,12,-1};
        MinSegTree Obj(arr);

        SUBCASE("Updating index -1")
        {
            Obj.Update(-1,5);

            for(int i = 0; i < arr.size(); i++)
                CHECK_EQ(arr[i], Obj.GetMin(i,i));
        }
        SUBCASE("Updating index 100")
        {
            Obj.Update(100,5);

            for(int i = 0; i < arr.size(); i++)
                CHECK_EQ(arr[i], Obj.GetMin(i,i));
        }
        cout<<"Segment Tree Update with Invalid Index Test Passed"<<endl;
    }
    TEST_CASE("Segment Tree Query with Multiple Valid Ranges Test")
    {
        vector<int>arr = {1,8,9,10,15,12,-1};
        MinSegTree Obj(arr);

        vector<pair<int,int>>ranges = {{0,4}, {1,4}, {2,3}, {0,0}, {5,6}, {0,6}};
        vector<int>answers = {1, 8, 9, 1, -1, -1};

        REQUIRE_EQ(ranges.size(), answers.size());

        for(int i = 0; i < ranges.size(); i++)
            CHECK_EQ(answers[i], Obj.GetMin(ranges[i].first, ranges[i].second));
        
        cout<<"Segment Tree Query with Multiple Valid Ranges Test"<<endl;
    }
    TEST_CASE("Segment Tree Query with Multiple InValid Ranges Test")
    {
        vector<int>arr = {1,8,9,10,15,12,-1};
        MinSegTree Obj(arr);

        vector<pair<int,int>>ranges = {{-1,4}, {1,10}, {-1,10}, {-10,-1}, {10,11}, {5,1}};

        for(int i = 0; i < ranges.size(); i++)
            CHECK_EQ(INT_MAX, Obj.GetMin(ranges[i].first, ranges[i].second));
        
        cout<<"Segment Tree Query with Multiple InValid Ranges Test"<<endl;
    }
}

TEST_SUITE("Performance")
{
    TEST_CASE("Test O(n) Segment Tree Build implementation" * doctest::timeout(0.2))
    {
        vector<int> arr;
        for(int i = 0; i < 1e6; i++)
            arr.push_back(i);
        
        MinSegTree Obj(arr);

        cout<<"Build Test Passed"<<endl;
    }

    TEST_CASE("Test O(Log(n)) Segment Tree Update implementation")
    {
        vector<int> arr;
        for(int i = 0; i < 1e6; i++)
            arr.push_back(i);
        
        MinSegTree Obj(arr);

        microseconds start = duration_cast<microseconds>(system_clock::now().time_since_epoch());
        Obj.Update(5e5,-1);
        microseconds end = duration_cast<microseconds>(system_clock::now().time_since_epoch());

        int t = end.count()-start.count();
        REQUIRE_LE(t, 5000);

        cout<<"Update Test Passed"<<endl;
    }

    TEST_CASE("Test O(Log(n)) Segment Tree Query implementation")
    {
        vector<int> arr;
        for(int i = 0; i < 1e6; i++)
            arr.push_back(i);
        
        MinSegTree Obj(arr);

        microseconds start = duration_cast<microseconds>(system_clock::now().time_since_epoch());
        Obj.GetMin(1e5,3e5);
        microseconds end = duration_cast<microseconds>(system_clock::now().time_since_epoch());

        int t = end.count()-start.count();
        REQUIRE_LE(t, 5000);

        cout<<"Query Test Passed"<<endl;
    }
}