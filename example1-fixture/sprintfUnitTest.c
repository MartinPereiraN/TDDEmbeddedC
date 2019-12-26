#include "unity.h"
#include "unity_fixture.h"
#include "productionCode1.h"
#include <string.h>

/*
gcc -I ../unity/extras/memory/src -I ../unity/extras/fixture/src -I ../unity/src  sprintfUnitTest.c productionCode1.c ../unity/extras/fixture/src/unity_fixture.c ../unity/extras/memory/src/unity_memory.c ../unity/src/unity.c -o sprintfUnitTest.exe 
*/

TEST_GROUP(sprintfTest);

static char output[100];
static const char * expected;

static void expect(const char * s)
{
    expected = s;
}

static void given(int charsWritten)
{
    TEST_ASSERT_EQUAL(strlen(expected), charsWritten);
    TEST_ASSERT_EQUAL_STRING(expected, output);
    TEST_ASSERT_BYTES_EQUAL(0xaa, output[strlen(expected) + 1]);
}

TEST_SETUP(sprintfTest)
{
    memset(output, 0xaa, sizeof output);
    expected = "";
}

TEST_TEAR_DOWN(sprintfTest)
{
//clean up steps are executed after each TEST
}

TEST(sprintfTest, testSimpleText)
{
    expect("hey");
    given(sprintf(output, "hey"));
}

TEST(sprintfTest, testInsertString)
{
    expect("Hello World\n");
    given(sprintf(output, "Hello %s\n", "World"));
}

TEST_GROUP_RUNNER(sprintfTest)
{
    //Each TEST has a corresponding RUN_TEST_CASE
    RUN_TEST_CASE(sprintfTest, testSimpleText);
    RUN_TEST_CASE(sprintfTest, testInsertString);
}

static void runAllTests()
{
    RUN_TEST_GROUP(sprintfTest);
}

int main(int argc, const  char * argv[])
{
    return UnityMain(argc, argv, runAllTests);
}