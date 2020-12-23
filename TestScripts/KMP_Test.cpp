#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_SUPER_FAST_ASSERTS

#include "../CodeFiles/KMP/KMP.h"
#include "../Tool/doctest.h"

TEST_SUITE("Correctness")
{
    TEST_CASE("General Test")
    {
        KMP Obj;
        string str = "HelloFromTest1", pattern = "From";
        vector<int> EO = {5};

        vector<int>ActualOutput = Obj.ApplyKMP(str, pattern);

        REQUIRE_EQ(EO.size(), ActualOutput.size());

        for(int i = 0; i < EO.size(); i++)
            REQUIRE_EQ(EO[i], ActualOutput[i]);
        
        cout<<"General Test passed"<<endl;
    }
    TEST_CASE("Multiple Occurences Test")
    {
        KMP Obj;
        string str = "FromHelloFromTest2From", pattern = "From";
        vector<int> EO = {0, 9, 18};

        vector<int>ActualOutput = Obj.ApplyKMP(str, pattern);

        REQUIRE_EQ(EO.size(), ActualOutput.size());

        for(int i = 0; i < EO.size(); i++)
            REQUIRE_EQ(EO[i], ActualOutput[i]);
        
        cout<<"Multiple Occurences Test passed"<<endl;
    }
    TEST_CASE("No Occurences Test")
    {
        KMP Obj;
        string str = "HelloFromTest3", pattern = "Query";
        vector<int> EO;

        vector<int>ActualOutput = Obj.ApplyKMP(str, pattern);

        REQUIRE_EQ(EO.size(), ActualOutput.size());

        for(int i = 0; i < EO.size(); i++)
            REQUIRE_EQ(EO[i], ActualOutput[i]);
        
        cout<<"No Occurences Test passed"<<endl;
    }
    TEST_CASE("Empty String Test")
    {
        KMP Obj;
        string str = "HelloFromTest4", pattern = "";
        vector<int> EO;
        SUBCASE("Empty Pattern Test")
        {
            vector<int>ActualOutput = Obj.ApplyKMP(str, pattern);

            CHECK_EQ(EO.size(), ActualOutput.size());

            for(int i = 0; i < EO.size(); i++)
                CHECK_EQ(EO[i], ActualOutput[i]);
        }

        SUBCASE("Empty String Test")
        {
            vector<int>ActualOutput = Obj.ApplyKMP(pattern, str);

            CHECK_EQ(EO.size(), ActualOutput.size());

            for(int i = 0; i < EO.size(); i++)
                CHECK_EQ(EO[i], ActualOutput[i]);
        }
        cout<<"Empty String Test passed"<<endl;
    }
    TEST_CASE("Pattern Longer Than String Test")
    {
        KMP Obj;
        string str = "Query", pattern = "Query5";
        vector<int> EO;

        vector<int>ActualOutput = Obj.ApplyKMP(str, pattern);

        REQUIRE_EQ(EO.size(), ActualOutput.size());

        for(int i = 0; i < EO.size(); i++)
            REQUIRE_EQ(EO[i], ActualOutput[i]);
        
        cout<<"Pattern Longer Than String Test passed"<<endl;
    }
}

TEST_SUITE("Performance")
{
    TEST_CASE("Test O(n + m) KMP implementation" * doctest::timeout(0.2))
    {
        string str = "", pattern = "a";
        vector<int>EO;
        for(int i = 0; i < 1e6;i++)
        {
            str += "a";
            EO.push_back(i);
        }

        KMP Obj;
        vector<int>ActualOutput = Obj.ApplyKMP(str, pattern);

        REQUIRE_EQ(ActualOutput.size(), EO.size());

        for(int i = 0; i < EO.size(); i++)
            REQUIRE_EQ(EO[i], ActualOutput[i]);
        
        cout<<"Performance Test Passed"<<endl;
    }
}
