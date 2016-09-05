#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP_RUNNER(ProductionCode)
{
    RUN_TEST_CASE(ProductionCode, TestMakeBoard);
    RUN_TEST_CASE(ProductionCode, TestInitBoard);
    RUN_TEST_CASE(ProductionCode, TestPlaceBoard);
    RUN_TEST_CASE(ProductionCode, TestWinBoard);
}
