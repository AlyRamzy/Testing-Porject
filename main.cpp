#define DOCTEST_CONFIG_IMPLEMENT

#include "Tool/doctest.h"

int main()
{
    doctest::Context context;

    // context.addFilter("source-file", "/TestScripts/*.cpp"); 
    context.addFilter("source-file-exclude", "/TestScripts/ConvexHull_Test.cpp"); 
    // overrides
    context.setOption("no-breaks", true);             // don't break in the debugger when assertions fail

    // context.applyCommandLine(argc, argv);

    int test_result = context.run(); // run queries, or run tests unless --no-run

    std::cout << test_result << std::endl;

    if(context.shouldExit()) // honor query flags and --exit
        return test_result;
}