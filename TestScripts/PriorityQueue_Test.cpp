#define DOCTEST_CONFIG_IMPLEMENTATION_IN_DLL
#include "../CodeFiles/PriorityQueue/PriorityQueue.h"
#include "../Tool/doctest.h"
TEST_SUITE("Correctness")
{
    TEST_CASE("isEmpty")
    {
        Priority_Queue pq;

        SUBCASE("isEmpty is true when contain no element")
        {
            CHECK(pq.isEmpty() == true);
        }
        pq.insert(1, 1);
        SUBCASE("isEmpty is false when contain only one element")
        {
            CHECK(!pq.isEmpty() == true);
        }
        pq.del();
        SUBCASE("isFull is true again when the only elemnent is deleted")
        {
            CHECK(pq.isEmpty() == true);
        }
    }

    TEST_CASE("Enqueue")
    {
        Priority_Queue pq;
        pq.insert(0, 0);
        SUBCASE("insert the first element")
        {
            CHECK(!pq.isEmpty() == true);
            CHECK(pq.peekFrontInfo() == pq.peekRearInfo());
        }
        int prev_front_priority = pq.peekFrontPriority();
        int prev_front_info = pq.peekFrontInfo();
        pq.insert(1, prev_front_priority + 10);
        SUBCASE("insert an element which is larger than the last inserted one")
        {
            CHECK(pq.peekFrontPriority() == prev_front_priority + 10);
        }
        prev_front_priority = pq.peekFrontPriority();
        prev_front_info = pq.peekFrontInfo();
        pq.insert(2, prev_front_priority - 5);
        SUBCASE("insert an element which is smaller than the last inserted one")
        {
            CHECK(pq.peekFrontPriority() == prev_front_priority);
        }
        for (int i = 3; i < 7; i++)
            pq.insert(i, i * 10);

        int tmpPr = 100000;
        SUBCASE("make sure elements are inserted in an ascending order")
        {
            while (!pq.isEmpty())
            {
                CHECK(pq.peekFrontPriority() < tmpPr);
                tmpPr = pq.peekFrontPriority();
                pq.del();
            }
        }
    }
    TEST_CASE("Dequeue")
    {
        Priority_Queue pq;

        SUBCASE("Test delete element when queue is empty")
        {
            CHECK_NOTHROW(pq.del());
        }
        for (int i = 3; i < 7; i++)
            pq.insert(i, i * 10);

        SUBCASE("Test delete element when queue is  not empty")
        {
            while (!pq.isEmpty())
            {
                CHECK_NOTHROW(pq.del());
            }
            CHECK(pq.isEmpty() == true);
        }
    }

    TEST_CASE("Peek")
    {
        Priority_Queue pq;
        int prev_front_priority = 30;
        int prev_front_info = 3;
        pq.insert(prev_front_info, prev_front_priority);
        SUBCASE("Test peek front information")
        {
            CHECK(pq.peekFrontInfo() == prev_front_info);
        }

        SUBCASE("Test peek front priority")
        {
            CHECK(pq.peekFrontPriority() == prev_front_priority);
        }
    }
}

TEST_SUITE("Performance")
{
    TEST_CASE("Time Complexity for insert: O(n^2) where n is the number of elements to push in the priority queue." * doctest::timeout(100))
    {
        Priority_Queue myq;
        for (int i = 0; i < 1e5; i++)
        {
            myq.insert(i, i);
        }
        MESSAGE("Priority Queue performance test passed");
    }
}


