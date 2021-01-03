#define DOCTEST_CONFIG_IMPLEMENTATION_IN_DLL
#include "../CodeFiles/Stack/Stack.h"
#include "../Tool/doctest.h"
#include <iostream>
using namespace std;

TEST_SUITE("Correctness")
{
    TEST_CASE("Push item in stack and pop it off")
    {
        StackNode *stack = NULL;

        push(&stack, 4);
        REQUIRE_EQ(pop(&stack), 4);
    }

    TEST_CASE("Push multiple items and pop them and check if reversed order")
    {
        StackNode *stack = NULL;

        for (int i = 0; i < 7; i++)
        {
            push(&stack, i);
        }

        for (int i = 6; i >= 0; i--)
        {
            REQUIRE_EQ(pop(&stack), i);
        }
    }
    TEST_CASE("Uninitialized stack is empty")
    {

        StackNode *stack = NULL;
        REQUIRE_EQ(isEmpty(stack), true);
    }

    TEST_CASE("Stack with pushed item is not empty")
    {
        StackNode *stack = NULL;

        push(&stack, 4);
        REQUIRE_EQ(isEmpty(stack), false);
    }

    TEST_CASE("Stack with pushed items and then poped is empty")
    {
        StackNode *stack = NULL;

        for (int i = 0; i < 7; i++)
        {
            push(&stack, i);
        }

        for (int i = 6; i >= 0; i--)
        {
            pop(&stack);
        }
        REQUIRE_EQ(isEmpty(stack), true);
    }
    TEST_CASE("Pop from empty stack")
    {
        StackNode *stack = NULL;

        CHECK_NOTHROW(pop(&stack));
    }

    TEST_CASE("The peek of stack is the last item pushed")
    {

        StackNode *stack = NULL;

        for (int i = 0; i < 7; i++)
        {
            push(&stack, i);
        }
        REQUIRE_EQ(peek(stack), 6);
    }
    TEST_CASE("The peek of empty stack")
    {
        StackNode *stack = NULL;

        CHECK_NOTHROW(peek(stack));
        REQUIRE_EQ(peek(stack), INT_MIN);
    }
}

TEST_SUITE("Performance")
{
    TEST_CASE("Time Complexity: O(n) where n is the number of elements to push in the stack." * doctest::timeout(0.5))
    {

        StackNode *stack = NULL;
        for (int i = 0; i < 1e7; i++)
        {
            push(&stack, i);
        }
    }
}
