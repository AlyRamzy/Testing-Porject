#define DOCTEST_CONFIG_IMPLEMENTATION_IN_DLL

#include "../CodeFiles/EulerTour/EulerTour.h"
#include "../Tool/doctest.h"

TEST_SUITE("Correctness")
{
    TEST_CASE("TEST CASE 0 :Main success scenario") {
        
        vector<int> out;
        Tree t(4);
        t.addEdge(0, 1);
        t.addEdge(1, 2);
        t.addEdge(1, 3);
    
        vector<int> Expected_Output ;
        Expected_Output.push_back(0);
        Expected_Output.push_back(1);
        Expected_Output.push_back(2);
        Expected_Output.push_back(1);
        Expected_Output.push_back(3);
        Expected_Output.push_back(1);
        Expected_Output.push_back(0);
        out = t.getEulerTour(0);
        CHECK(Expected_Output==out);
    }
    TEST_CASE("TEST CASE 1 : starting with node not inside the tree"){
        vector<int> out;
        Tree t(4);
        t.addEdge(0, 1);
        t.addEdge(0, 2);
        t.addEdge(1, 2);
        t.addEdge(2, 0);
        t.addEdge(2, 3);
        t.addEdge(3, 3);

        out  = t.getEulerTour(5);
        CHECK(out.size()==0);
    }

    TEST_CASE("TEST CASE 2 :construct tree with -ve number of nodes"){
        CHECK_NOTHROW(Tree t(-1));
    }
    
    TEST_CASE("TEST CASE 3 :Construct tree with -ve number to get euler tour for"){
        Tree t(4);
        t.addEdge(0, 1);
        t.addEdge(0, 2);
        t.addEdge(1, 2);
        t.addEdge(2, 0);
        t.addEdge(2, 3);
        t.addEdge(3, 3);
        
        CHECK_NOTHROW(t.getEulerTour(-1));
        CHECK(t.getEulerTour(-1).size()==0);
    }
    
    TEST_CASE("TEST CASE 4 :Checking edges in the Tree"){
        Tree t(4);
        SUBCASE("Add edge between two nodes exists in the tree"){
            CHECK(t.addEdge(0,1)==true);
        }
        SUBCASE("Add edge between two nodes doesnt exist in the tree"){
            CHECK(t.addEdge(5,6)==false);
        }
        SUBCASE("Add edge between -ve value as src"){
            CHECK(t.addEdge(-1,2)==false);
        }
        SUBCASE("Add edge between -ve value as dist"){
            CHECK(t.addEdge(1,-2)==false);
        }
        SUBCASE("Add edge between src that doesnt not exist and exists dist"){
            CHECK(t.addEdge(6,2)==false);
        }
        SUBCASE("Add edge between dist that doesnt not exist and exists src"){
            CHECK(t.addEdge(2,6)==false);
        }
    }

    TEST_CASE("TEST CASE 5 :Checking tree with no edges"){
        Tree t(4);

        vector<int> Expected_Output,Actual_Output;
        Actual_Output = t.getEulerTour(0);
        Expected_Output.push_back(0);
        CHECK(Actual_Output==Expected_Output);
    }

    TEST_CASE("TEST CASE 6 :Checking tree with one node and no edges"){
        Tree t(1);
        vector<int> Expected_Output,Actual_Output;
        Actual_Output = t.getEulerTour(0);
        Expected_Output.push_back(0);
        CHECK(Actual_Output==Expected_Output);
    }

    TEST_CASE("TEST CASE 6 :Checking tree with one node and one cylcic edges"){
        Tree t(1);
        t.addEdge(0,0);
        vector<int> Expected_Output,Actual_Output;
        Actual_Output = t.getEulerTour(0);
        Expected_Output.push_back(0);
        CHECK(Actual_Output==Expected_Output);
    }
    TEST_CASE("TEST CASE 7 :Checking to get Euler Tour From node at the middle of the tree"){
        vector<int> out;
        Tree t(4);
        t.addEdge(0, 1);
        t.addEdge(1, 2);
        t.addEdge(1, 3);
        
        vector<int> Expected_Output ;
        Expected_Output.push_back(1);
        Expected_Output.push_back(0);
        Expected_Output.push_back(1);
        Expected_Output.push_back(2);
        Expected_Output.push_back(1);
        Expected_Output.push_back(3);
        Expected_Output.push_back(1);
        out = t.getEulerTour(1);
        CHECK(Expected_Output==out);
    }
}

TEST_SUITE("Performance")
{
    Tree t (1e7);
    
    TEST_CASE("Time Complexity: O(N) where N is number of vertices in the tree." * doctest::timeout(0.5))
    {
        for(int i =1 ; i <1e6; i++){
            t.addEdge(0,i);
        }
        vector<int> Actual_Output = t.getEulerTour(0);
        vector<int> Expected_Output;
        for(int i=1;i<1e6;i++){
            Expected_Output.push_back(0);
            Expected_Output.push_back(i);
        }
        Expected_Output.push_back(0);

        REQUIRE(Expected_Output==Actual_Output);
        
        MESSAGE("Euler Tour Performance Test Passed");
    }
}