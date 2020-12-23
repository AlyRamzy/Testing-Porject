#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../CodeFiles/LCA/LCA.h"
#include "../Tool/doctest.h"
TEST_SUITE("Correctness")
{
    TEST_CASE("TEST CASE 0 :Main success scenario") {
        Node * root = newNode(1);
        root->left = newNode(2);
        root->right = newNode(3);
        root->left->left = newNode(4);
        root->left->right = newNode(5);
        root->right->left = newNode(6);
        root->right->right = newNode(7);
        CHECK(findLCA(root, 4, 5)==2);
        CHECK(findLCA(root, 4, 6)==1);
        CHECK(findLCA(root, 3, 4)==1);
        CHECK(findLCA(root, 2, 4)==2);
    }

    TEST_CASE("TEST CASE 1 :Node value as NULL"){
        Node * root = newNode(1);
        root->left = newNode(2);
        root->right = newNode(3);
        CHECK(findLCA(NULL, 4, 5)==-1);

    }
    TEST_CASE("TEST CASE 2 :First Number Doesnt Exist in the tree"){
        Node * root = newNode(1);
        root->left = newNode(2);
        root->right = newNode(3);
        CHECK(findLCA(root, 5, 3)==-1);

    }

    TEST_CASE("TEST CASE 3 :Second Number Doesnt Exist in the tree"){
        Node * root = newNode(1);
        root->left = newNode(2);
        root->right = newNode(3);
        CHECK(findLCA(root, 3, 5)==-1);

    }
    TEST_CASE("TEST CASE 4 :Both Numbers Doesnt Exist in the tree"){
        Node * root = newNode(1);
        root->left = newNode(2);
        root->right = newNode(3);
        CHECK(findLCA(root, 6, 5)==-1);

    }
    TEST_CASE("TEST CASE 5 :Searching For Value same as its LCA in full tree"){
        Node * root = newNode(1);
        root->left = newNode(1);
        root->right = newNode(1);
        CHECK(findLCA(root, 1, 1)==1);

    }
    TEST_CASE("TEST CASE 6 :Searching For Value same as its LCA in tree with one node"){
        Node * root = newNode(1);
       
        CHECK(findLCA(root, 1, 1)==1);

    }

}
TEST_SUITE("Performance")
{
    
    Node * root = newNode(0);
    Node * temp = root;

    
    
    TEST_CASE("Time Complexity: O(h)  where h is the height of the tree" * doctest::timeout(0.03))  
    {
        for(int i =1;i<1e5;i++){//Construct tree with height 10^5

            root->left=  newNode(i);
            root = root->left;

        }
        root = temp;

        REQUIRE(findLCA(root,1e5-1,0)==0);
        
        
        cout<<"Performance Test Passed"<<endl;
    }




}