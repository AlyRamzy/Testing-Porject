#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../CodeFiles/BFSGraph/BFS.h"
#include "../Tool/doctest.h"
/*
Proplems : doesnt handle -ve values in constructor and add edge and bfs
         : doesnt handle values that do not exist in the graph for add edge and bfs


*/
// Program to print BFS traversal from a given
// source vertex. BFS(int s) traverses vertices 
// reachable from s.


TEST_SUITE("Correctness")
{
    TEST_CASE("TEST CASE 0 :Main success scenario") {
        vector<int> out;
        Graph g(4);
        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 2);
        g.addEdge(2, 0);
        g.addEdge(2, 3);
        g.addEdge(3, 3);

    
        vector<int> Expected_Output ;
        Expected_Output.push_back(2);
        Expected_Output.push_back(0);
        Expected_Output.push_back(3);
        Expected_Output.push_back(1);
        out = g.BFS(2);
        CHECK(Expected_Output==out);
    }
    TEST_CASE("TEST CASE 1 : starting with node not inside the graph"){
        vector<int> out;
        Graph g(4);
        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 2);
        g.addEdge(2, 0);
        g.addEdge(2, 3);
        g.addEdge(3, 3);

        
        out  = g.BFS(4);
        CHECK(out.size()==0);
        
    }

    TEST_CASE("TEST CASE 2 :construct graph with -ve number of nodes"){

        
        
        CHECK_NOTHROW(Graph g(-1));
    }
    
    TEST_CASE("TEST CASE 3 :Construct Graph with -ve number to search for"){

        vector<int> out;
        Graph g(4);
        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 2);
        g.addEdge(2, 0);
        g.addEdge(2, 3);
        g.addEdge(3, 3);

        
        CHECK_NOTHROW(g.BFS(-1));
        CHECK(g.BFS(-1).size()==0);
        
    }


    TEST_CASE("TEST CASE 4 :Checking edges in the graph"){
        Graph g(4);
        SUBCASE("Add edge between two nodes exists in the graph"){
            CHECK(g.addEdge(0,1)==true);
        }
        SUBCASE("Add edge between two nodes doesnt exist in the graph"){
            CHECK(g.addEdge(5,6)==false);
            
        }
        SUBCASE("Add edge between -ve value as src"){
            CHECK(g.addEdge(-1,2)==false);
            
        }
        SUBCASE("Add edge between -ve value as dist"){
            CHECK(g.addEdge(1,-2)==false);
            

        }
        SUBCASE("Add edge between src that doesnt not exist and exists dist"){
            CHECK(g.addEdge(6,2)==false);
            

        }
        SUBCASE("Add edge between dist that doesnt not exist and exists src"){
            CHECK(g.addEdge(2,6)==false);
            

        }
        
        

    }
    

    TEST_CASE("TEST CASE 5 :Checking graph with no edges"){
        Graph g(4);

        vector<int> Expected_Output,Actual_Output;
        Actual_Output = g.BFS(3);
        Expected_Output.push_back(3);
        CHECK(Actual_Output==Expected_Output);
    }

    TEST_CASE("TEST CASE 6 :Checking graph with one node and no edges"){
        Graph g(1);
        vector<int> Expected_Output,Actual_Output;
        Actual_Output = g.BFS(0);
        Expected_Output.push_back(0);
        CHECK(Actual_Output==Expected_Output);

        
    }

    TEST_CASE("TEST CASE 6 :Checking graph with one node and one cylcic edges"){
        Graph g(1);
        g.addEdge(0,0);
        vector<int> Expected_Output,Actual_Output;
        Actual_Output = g.BFS(0);
        Expected_Output.push_back(0);
        CHECK(Actual_Output==Expected_Output);

        
    }
}


TEST_SUITE("Performance")
{
    Graph g (1e7);
    
    
    
    TEST_CASE("Time Complexity: O(V+E) where V is number of vertices in the graph and E is number of edges in the graph." * doctest::timeout(0.5))
    {
        for(int i =0 ; i <1e6; i++){
            g.addEdge(0,i);
        }
        

        vector<int> Actual_Output = g.BFS(0);
        
        
        cout<<"Performance Test Passed"<<endl;
    }




}

