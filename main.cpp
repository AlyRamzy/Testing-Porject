#define DOCTEST_CONFIG_NO_UNPREFIXED_OPTIONS
#define DOCTEST_CONFIG_IMPLEMENT

#include "Tool/doctest.h"

int main()
{
    doctest::Context context;

    context.addFilter("source-file", "/TestScripts/*.cpp"); 
    // overrides
    context.setOption("no-breaks", true);             // don't break in the debugger when assertions fail

    // context.applyCommandLine(argc, argv);

    int test_result = context.run(); // run queries, or run tests unless --no-run

    if(context.shouldExit()) // honor query flags and --exit
        return test_result;
}