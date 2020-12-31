#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../CodeFiles/BSTtraversal/tree.h"
#include "../Tool/doctest.h"

TEST_SUITE("Correctness")
{

    TEST_CASE("Tree traveral")
    {
        
        SUBCASE(" Traversing empty tree")
        {
            Tree t;
            REQUIRE_EQ(t.isEmpty() ,  true);
            REQUIRE_EQ("", t.traversal(TraversalType::PREORDER));
            REQUIRE_EQ("", t.traversal(TraversalType::INORDER));
            REQUIRE_EQ("", t.traversal(TraversalType::POSTORDER));
            REQUIRE_EQ("", t.traversal(TraversalType::LEVELORDER));
            REQUIRE_EQ("", t.traversal(TraversalType::LEVELORDER_SEP));
        }
        
        SUBCASE(" Traversing one node  tree")
        {
            Tree t;
            t.add(13);
         
            REQUIRE_EQ("13", t.traversal(TraversalType::PREORDER));
            REQUIRE_EQ("13", t.traversal(TraversalType::INORDER));
            REQUIRE_EQ("13", t.traversal(TraversalType::POSTORDER));
            REQUIRE_EQ("13", t.traversal(TraversalType::LEVELORDER));
            REQUIRE_EQ("13", t.traversal(TraversalType::LEVELORDER_SEP));
        }
        SUBCASE(" Traversing multiple  node  tree")
        {
            Tree t;
            t.add(13);
            t.add(3);
            t.add(20);
            t.add(7);
            t.add(15);
            t.add(1);
            t.add(4);
            REQUIRE_EQ("13 3 1 7 4 20 15", t.traversal(TraversalType::PREORDER));
            REQUIRE_EQ("1 3 4 7 13 15 20", t.traversal(TraversalType::INORDER));
            REQUIRE_EQ("1 4 7 3 15 20 13", t.traversal(TraversalType::POSTORDER));
            REQUIRE_EQ("1 3 4 7 13 15 20", t.traversal(TraversalType::DEPTHFIRST));
            REQUIRE_EQ("13 3 20 1 7 15 4", t.traversal(TraversalType::LEVELORDER));
            REQUIRE_EQ("13\n3 20\n1 7 15\n4", t.traversal(TraversalType::LEVELORDER_SEP));
        }
        
        

    }
}
TEST_SUITE("Performance")
{

    TEST_CASE("Time Complexity: O(n log n) where n is the size of the tree nodes." * doctest::timeout(1/25000))
    {
        Tree tree;

        for (int i = 0; i < 1e3; i++) // addition takes O(log n)
        {
            tree.add(i);
        }
       
        tree.traversal(TraversalType::PREORDER); // takes O(n)
       
        
    }
}