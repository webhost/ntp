/* AUTOGENERATED FILE. DO NOT EDIT. */

//=======Test Runner Used To Run Each Test Below=====
#define RUN_TEST(TestFunc, TestLineNum) \
{ \
  Unity.CurrentTestName = #TestFunc; \
  Unity.CurrentTestLineNumber = TestLineNum; \
  Unity.NumberOfTests++; \
  if (TEST_PROTECT()) \
  { \
      setUp(); \
      TestFunc(); \
  } \
  if (TEST_PROTECT() && !TEST_IS_IGNORED) \
  { \
    tearDown(); \
  } \
  UnityConcludeTest(); \
}

//=======Automagically Detected Files To Include=====
#include "unity.h"
#include <setjmp.h>
#include <stdio.h>
#include "config.h"
#include "ntp_scanner.h"

//=======External Functions This Runner Calls=====
extern void setUp(void);
extern void tearDown(void);
extern void test_keywordIncorrectToken(void);
extern void test_keywordServerToken(void);
extern void test_DropUninitializedStack(void);
extern void test_IncorrectlyInitializeLexStack(void);
extern void test_InitializeLexStack(void);


//=======Test Reset Option=====
void resetTest(void);
void resetTest(void)
{
  tearDown();
  setUp();
}

char *progname;


//=======MAIN=====
int main(int argc, char *argv[])
{
  progname = argv[0];
  UnityBegin("ntp_scanner.c");
  RUN_TEST(test_keywordIncorrectToken, 20);
  RUN_TEST(test_keywordServerToken, 21);
  RUN_TEST(test_DropUninitializedStack, 22);
  RUN_TEST(test_IncorrectlyInitializeLexStack, 23);
  RUN_TEST(test_InitializeLexStack, 24);

  return (UnityEnd());
}
