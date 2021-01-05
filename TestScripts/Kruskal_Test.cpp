#define DOCTEST_CONFIG_IMPLEMENTATION_IN_DLL
#define DOCTEST_CONFIG_SUPER_FAST_ASSERTS

#include "../CodeFiles/Kruskal/Kruskal.h"
#include "../Tool/doctest.h"

TEST_SUITE("Correctness")
{
    TEST_CASE("General Case Test")
    {
        int nodes = 5;
        vector<edge>edges;
        edges.push_back({1,2,10});
        edges.push_back({1,3,12});
        edges.push_back({2,3,5});
        edges.push_back({3,4,6});
        edges.push_back({3,5,13});

        Kruskal Obj(nodes, edges);

        REQUIRE_EQ(Obj.FindMSTValue(), 34);
    }

    TEST_CASE("Negative Size of Graph")
    {
        CHECK_NOTHROW(Kruskal(-5,vector<edge>()));
    }

    TEST_CASE("Fully Connected Graph Test")
    {
        int nodes = 5;
        SUBCASE("Equal Weights")
        {
            vector<edge>edges;
            for(int i = 1; i <= nodes; i++)
                for(int j = i + 1; j <= nodes; j++)
                    edges.push_back(edge(i,j,5));
            
            Kruskal Obj(nodes, edges);

            REQUIRE_EQ(Obj.FindMSTValue(), 20);
        }
        SUBCASE("Different Weights")
        {
            vector<edge>edges;
            for(int i = 1; i <= nodes; i++)
                for(int j = i + 1; j <= nodes; j++)
                    edges.push_back(edge(i,j,2*(i+j)));
            
            Kruskal Obj(nodes, edges);

            REQUIRE_EQ(Obj.FindMSTValue(), 36);
        }
    }

    TEST_CASE("Disconnected Graph Test")
    {
        int nodes = 5;
        vector<edge>edges;
        edges.push_back({1,2,10});
        edges.push_back({1,3,10});
        edges.push_back({4,5,10});

        Kruskal Obj(nodes, edges);

        REQUIRE_EQ(Obj.FindMSTValue(), LONG_LONG_MIN);
    }

    TEST_CASE("Tree Test")
    {
        int nodes = 5;
        vector<edge>edges;
        edges.push_back({1,2,1});
        edges.push_back({1,3,2});
        edges.push_back({1,5,4});
        edges.push_back({1,4,6});

        Kruskal Obj(nodes, edges);

        REQUIRE_EQ(Obj.FindMSTValue(), 13);
    }
}

TEST_SUITE("Performance")
{
    TEST_CASE("Performance Test" * doctest::timeout(1.0))
    {
        int nodes = 2e3;
        vector<edge>edges;
        for(int i = 1; i <= nodes; i++)
            for(int j = i + 1; j <= nodes; j++)
                edges.push_back({i,j,10});
        
        Kruskal Obj(nodes, edges);
        MESSAGE("Kruskal Performance Test Passed");
    }
}