#define DOCTEST_CONFIG_IMPLEMENTATION_IN_DLL

#include "../CodeFiles/ConvexHull/convex_hull.h"
#include "../Tool/doctest.h"

TEST_SUITE("Correctness")
{
    TEST_CASE("Empty array")
    {
        Point points[] = {};
        int n = sizeof(points)/sizeof(points[0]); 
        CHECK_NOTHROW(convexHull(points, n));
    }

    TEST_CASE("One element array")
    {
        Point points[] = {{2, 2}};
        int n = sizeof(points)/sizeof(points[0]); 
        CHECK_NOTHROW(convexHull(points, n));
    }

    TEST_CASE("Two element array")
    {
        Point points[] = {{2, 2}, {3, 3}};
        int n = sizeof(points)/sizeof(points[0]); 
        CHECK_NOTHROW(convexHull(points, n));
    }

    TEST_CASE("Three element array")
    {
        Point points[] = {{2, 2}, {1, 3}, {3, 3}};
        int n = sizeof(points)/sizeof(points[0]); 
        vector<Point> hull; 
        hull = convexHull(points, n); 
        vector<Point> convex_hull;

        Point p1 = {1, 3};
        Point p2 = {2, 2};
        Point p3 = {3, 3};

        convex_hull.push_back(p1);
        convex_hull.push_back(p2);
        convex_hull.push_back(p3);

        // CHECK(hull.size() == convex_hull.size());
        for (int i = 0; i < n; i++)
        {
            CHECK(hull[i].x == convex_hull[i].x);
            CHECK(hull[i].y == convex_hull[i].y);
        }

    }

    TEST_CASE("All points on the same line")
    {
        vector<Point> convex_hull;
        Point p1 = {1, 1};
        Point p2 = {2, 2};
        Point p3 = {3, 3};

        convex_hull.push_back(p1);
        convex_hull.push_back(p2);
        convex_hull.push_back(p3);

        SUBCASE("Three points")
        {
            Point points[] = {{1, 1}, {2, 2}, {3, 3}};
            int n = sizeof(points)/sizeof(points[0]); 
            vector<Point> hull; 
            hull = convexHull(points, n); 

            for (int i = 0; i < n; i++)
            {
                CHECK(hull[i].x == convex_hull[i].x);
                CHECK(hull[i].y == convex_hull[i].y);
            }
        }

        Point p4 = {4, 4};
        convex_hull.push_back(p4);
        
        SUBCASE("Four points")
        {
            Point points[] = {{1, 1}, {2, 2}, {3, 3}, {4, 4}};
            int n = sizeof(points)/sizeof(points[0]); 
            vector<Point> hull; 
            hull = convexHull(points, n); 

            for (int i = 0; i < n; i++)
            {
                CHECK(hull[i].x == convex_hull[i].x);
                CHECK(hull[i].y == convex_hull[i].y);
            }
        }
    }

    TEST_CASE("Negative points")
    {
        vector<Point> convex_hull;
        Point p1 = {-3, 0};
        Point p2 = {0, -3};
        Point p3 = {3, 0};
        Point p4 = {0, 3};

        convex_hull.push_back(p1);
        convex_hull.push_back(p2);
        convex_hull.push_back(p3);
        convex_hull.push_back(p4);

        SUBCASE("Four points")
        {
            Point points[] = {{-3, 0}, {0, -3}, {0, 3}, {3, 0}};
            int n = sizeof(points)/sizeof(points[0]); 
            vector<Point> hull; 
            hull = convexHull(points, n); 

            for (int i = 0; i < n; i++)
            {
                CHECK(hull[i].x == convex_hull[i].x);
                CHECK(hull[i].y == convex_hull[i].y);
            }
        }
        Point p5 = {-3, 3};
        convex_hull.push_back(p5);

        SUBCASE("Five points")
        {
            Point points[] = {{-3, 0}, {0, -3}, {0, 3}, {3, 0}, {-3,3}};
            int n = sizeof(points)/sizeof(points[0]); 
            vector<Point> hull; 
            hull = convexHull(points, n); 

            for (int i = 0; i < n; i++)
            {
                CHECK(hull[i].x == convex_hull[i].x);
                CHECK(hull[i].y == convex_hull[i].y);
            }
        }
    }
}
