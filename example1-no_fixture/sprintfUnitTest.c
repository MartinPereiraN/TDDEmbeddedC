#include "unity.h"
#include "productionCode1.h"

void setUp (void) {}; /* Is run before every test, put unit init calls here. */
void tearDown (void) {}; /* Is run after every test, put unit clean-up calls here. */

void test_sprintf(void)
{
char output[5] = "";
TEST_ASSERT_EQUAL(3, sprintf(output, "hey"));
TEST_ASSERT_EQUAL_STRING("hey", output);
}

int main(void)
{
UNITY_BEGIN();

RUN_TEST(test_sprintf);

return UNITY_END();
}