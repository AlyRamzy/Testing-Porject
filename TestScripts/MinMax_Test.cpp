#define DOCTEST_CONFIG_IMPLEMENTATION_IN_DLL
#include "../CodeFiles/MinMax/MinMax.h"
#include "../Tool/doctest.h"
TEST_SUITE("Correctness")
{
    TEST_CASE("TEST CASE 0 :Main success scenario") {
        vector<int> input ;
        input.push_back(3);
        input.push_back(5);
        input.push_back(2);
        input.push_back(9);
        input.push_back(12);
        input.push_back(5);
        input.push_back(23);
        input.push_back(23);

        int Actual_Output = minimax_interface(input);
        CHECK(Actual_Output==12);
    }

    TEST_CASE("TEST CASE 1 :Input number of nodes isnot divisable by 2 "){
        vector<int> input ;
        input.push_back(3);
        input.push_back(15);
        input.push_back(25);
        input.push_back(35);
        input.push_back(54);
         int Actual_Output = minimax_interface(input);
        CHECK(Actual_Output==-1);
    }

    TEST_CASE("TEST CASE 2 :Input has only 2 value"){
        vector<int> input ;
        input.push_back(3);
        input.push_back(5);
         int Actual_Output = minimax_interface(input);
        CHECK(Actual_Output==5);
    }

    TEST_CASE("TEST CASE 3 :Input has only 1 value"){
        vector<int> input ;
        input.push_back(3);
        int Actual_Output = minimax_interface(input);
        CHECK(Actual_Output==-1);
    }

    TEST_CASE("TEST CASE 4 :Empty Input"){
        vector<int> input ;
       
        int Actual_Output = minimax_interface(input);
        CHECK(Actual_Output==-1);
    }
}
   
TEST_SUITE("Performance")
{
   TEST_CASE("Time Complexity: O(b^m)  where b is the branching factor and m is the tree depth." * doctest::timeout(0.003))  
    {
        vector<int> input ;
        for(int i =0 ; i <pow(2,10);i++){
            input.push_back(10);
        }
        int Actual_Output = minimax_interface(input);
        REQUIRE(Actual_Output==10);

        MESSAGE("MinMax Performance Test Passed");
    }
}