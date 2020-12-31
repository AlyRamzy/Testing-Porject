
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../CodeFiles/Queue/Queue.h"
#include "../Tool/doctest.h"

TEST_SUITE("Correctness")
{
    TEST_CASE("isFull")
    {
        Queue myq;

        SUBCASE("isFull is false when contain no element")
        {
            CHECK(!myq.isFull() == true);
        }
        myq.enQueue(10);
        SUBCASE("isFull is false when contain only one element")
        {
            CHECK(!myq.isFull() == true);
        }
        for (int i = 1; i < MAX_SIZE; i++)
            myq.enQueue(10);
        SUBCASE("isFull is true when contain max elements")
        {
            CHECK(myq.isFull() == true);
        }
        for (int i = 0; i < MAX_SIZE; i++)
            myq.deQueue();
    }
    TEST_CASE("isEmpty")
    {
        Queue myq;

        SUBCASE("isEmpty is true when contain no element")
        {
            CHECK(myq.isEmpty() == true);
        }
        myq.enQueue(10);
        SUBCASE("isEmpty is false when contain only one element")
        {
            CHECK(!myq.isEmpty() == true);
        }
        myq.deQueue();
        SUBCASE("isFull is true again when the only elemnent is deleted")
        {
            CHECK(myq.isEmpty() == true);
        }

    }
    TEST_CASE("Enqueue")
    {
        Queue myq;
        myq.enQueue(0);
        SUBCASE("insert only one element")
        {

            CHECK(myq.getRear() == myq.getFront());
            CHECK(myq.getFirst() == 0);
        }
        for (int i = 1; i < MAX_SIZE; i++)
            myq.enQueue(i);
        SUBCASE("insert all allowed elements")
        {

            CHECK(myq.getLast() == MAX_SIZE - 1);
        }
        myq.enQueue(MAX_SIZE);
        SUBCASE("insert an element when the queue is full")
        {

            CHECK(myq.getLast() == MAX_SIZE - 1);
        }

    }
    TEST_CASE("Dequeue")
    {
        Queue myq;
        for (int i = 0; i < MAX_SIZE; i++)
            myq.enQueue(i);
        SUBCASE("dequeue one element correctly while the queue is full")
        {

            CHECK(myq.deQueue() == 0);
            CHECK(myq.getFront() == 1);
        }
        int parity = 1;
        for (int i = 0; i < MAX_SIZE; i++)
            parity *= myq.deQueue();

        SUBCASE("dequeue untill the queue is empty")
        {

            CHECK(parity >= 0);
            CHECK(myq.isEmpty());
            CHECK(myq.getRear() == myq.getFront());

        }
        SUBCASE("dequeue while the queue is empty")
        {
            CHECK(myq.deQueue() == -1);
        }


    }
}



TEST_SUITE("Performance")
{
    TEST_CASE("Time Complexity: O(n) where n is the number of elements to push in the queue." * doctest::timeout(1 / 1000))
    {

        Queue myq;
        for (int i = 0; i < 1e5; i++)
        {
            myq.enQueue(i);
        }
    }
}


