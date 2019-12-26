#include "unity.h"
#include "unity_fixture.h"
#include "productionCode1.h"

/*
gcc -I ../unity/extras/memory/src -I ../unity/extras/fixture/src -I ../unity/src  sprintfUnitTest.c productionCode1.c ../unity/extras/fixture/src/unity_fixture.c ../unity/extras/memory/src/unity_memory.c ../unity/src/unity.c -o sprintfUnitTest.exe 
*/

TEST_GROUP(sprintfTest);

TEST_SETUP(sprintfTest)
{
//initialization steps are executed before each TEST
}

TEST_TEAR_DOWN(sprintfTest)
{
//clean up steps are executed after each TEST
}

TEST(sprintfTest, testSimpleText)
{
    char output[5] = "";
    TEST_ASSERT_EQUAL(3, sprintf(output, "hey"));
    TEST_ASSERT_EQUAL_STRING("hey", output);
}

TEST_GROUP_RUNNER(sprintfTest)
{
    //Each TEST has a corresponding RUN_TEST_CASE
    RUN_TEST_CASE(sprintfTest, testSimpleText);
}

static void runAllTests()
{
RUN_TEST_GROUP(sprintfTest);
}

int main(int argc, const  char * argv[])
{
    return UnityMain(argc, argv, runAllTests);
}