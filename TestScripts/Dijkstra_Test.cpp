#define DOCTEST_CONFIG_IMPLEMENTATION_IN_DLL

#include "../CodeFiles/Dijkstra/Dijkstra.h"
#include "../Tool/doctest.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

TEST_SUITE("Correctness")
{

    TEST_CASE("Distance from node in graph with 9 vertices")
    {
        int V = 9;
        struct Graph *graph = createGraph(V);
        addEdge(graph, 0, 1, 4);
        addEdge(graph, 0, 7, 8);
        addEdge(graph, 1, 2, 8);
        addEdge(graph, 1, 7, 11);
        addEdge(graph, 2, 3, 7);
        addEdge(graph, 2, 8, 2);
        addEdge(graph, 2, 5, 4);
        addEdge(graph, 3, 4, 9);
        addEdge(graph, 3, 5, 14);
        addEdge(graph, 4, 5, 10);
        addEdge(graph, 5, 6, 2);
        addEdge(graph, 6, 7, 1);
        addEdge(graph, 6, 8, 6);
        addEdge(graph, 7, 8, 7);

        int *dis = dijkstra(graph, 0);
        int minDistances[9] = {0, 4, 12, 19, 21, 11, 9, 8, 14};

        for (int i = 0; i < 9; i++)
        {
            CHECK_EQ(dis[i], minDistances[i]);
        }
    }

    TEST_CASE("Distance from node in graph graph with 4 vertices")
    {
        int V = 4;
        struct Graph *graph = createGraph(V);
        addEdge(graph, 0, 1, 3);
        addEdge(graph, 0, 2, 1);
        addEdge(graph, 0, 3, 5);
        addEdge(graph, 1, 3, 2);
        addEdge(graph, 2, 3, 1);

        int *dis = dijkstra(graph, 0);
        int minDistances[4] = {0, 3, 1, 2};
        for (int i = 0; i < 4; i++)
        {
            CHECK_EQ(dis[i], minDistances[i]);
        }
    }
    
    TEST_CASE("Min Distance from node not connected to  the graph")
    {
        int V = 10;
        struct Graph *graph = createGraph(V);
        addEdge(graph, 0, 1, 4);
        addEdge(graph, 0, 7, 8);
        addEdge(graph, 1, 2, 8);
        addEdge(graph, 1, 7, 11);
        addEdge(graph, 2, 3, 7);
        addEdge(graph, 2, 8, 2);
        addEdge(graph, 2, 5, 4);
        addEdge(graph, 3, 4, 9);
        addEdge(graph, 3, 5, 14);
        addEdge(graph, 4, 5, 10);
        addEdge(graph, 5, 6, 2);
        addEdge(graph, 6, 7, 1);
        addEdge(graph, 6, 8, 6);
        addEdge(graph, 7, 8, 7);

        int *dis = dijkstra(graph, 10);

        for (int i = 0; i < 10; i++)
        {
            CHECK_EQ(dis[i], INT_MAX);
        }
    }
    
    TEST_CASE("Min Distance from node connected to part of the graph")
    {
        int V = 9;
        struct Graph *graph = createGraph(V);
        addEdge(graph, 0, 1, 4);
        addEdge(graph, 0, 2, 5);
        addEdge(graph, 1, 2, 8);
        addEdge(graph, 1, 3, 11);
        addEdge(graph, 2, 3, 7);

        addEdge(graph, 4, 5, 10);
        addEdge(graph, 5, 6, 2);
        addEdge(graph, 6, 7, 1);
        addEdge(graph, 6, 8, 6);
        addEdge(graph, 7, 8, 7);

        int minDistances[9] = {4, 0, 8, 11, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX};
        int *dis = dijkstra(graph, 1);
        for (int i = 0; i < 9; i++)
        {
            CHECK_EQ(dis[i], minDistances[i]);
        }
    }
    TEST_CASE("Min Distance from node in graph that has no edges")
    {
        int V = 10;
        struct Graph *graph = createGraph(V);

        int *dis = dijkstra(graph, 0);

        for (int i = 1; i < 10; i++)
        {
            CHECK_EQ(dis[i], INT_MAX);
        }
    }
}

TEST_SUITE("Performance")
{

    TEST_CASE("Time Complexity: O(ElogV) where n is the size of the sorted array." * doctest::timeout(1))
    {
        int V = int(1e6);

        struct Graph *graph = createGraph(V);
        for (int i = 0; i < int(1e6) - 2; i++)
        {

            addEdge(graph, i, i + 1, rand());
            addEdge(graph, i, i + 2, rand());
        }
        dijkstra(graph, 0);
    }
}
