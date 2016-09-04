#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP_RUNNER(ProductionCode)
{
  RUN_TEST_CASE(ProductionCode, FindFunction_WhichIsBroken_ShouldReturnZeroIfItemIsNotInList_WhichWorksEvenInOurBrokenCode);
  RUN_TEST_CASE(ProductionCode, FunctionWhichReturnsLocalVariable_ShouldReturnTheCurrentCounterValue);
  RUN_TEST_CASE(ProductionCode, FunctionWhichReturnsLocalVariable_ShouldReturnTheCurrentCounterValueAgain);
}
