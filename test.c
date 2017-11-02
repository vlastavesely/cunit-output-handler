#include <CUnit/CUnit.h>
#include "cunit-minimal.h"

static void test_1(void)
{
	CU_ASSERT_EQUAL(11, 11);
}

static void test_1_failing(void)
{
	CU_ASSERT_EQUAL(11, 1);
}

static void cunit_add_tests(struct CU_Suite *suite)
{
	CU_add_test(suite, "test_1", test_1);
	CU_add_test(suite, "test_2", test_1);
	CU_add_test(suite, "test_3", test_1);
	CU_add_test(suite, "test_4", test_1);
	CU_add_test(suite, "test_5", test_1);
	CU_add_test(suite, "test_6", test_1);
	CU_add_test(suite, "test_7", test_1_failing);
	CU_add_test(suite, "test_8", test_1);
	CU_add_test(suite, "test_9", test_1);
}

int main(int argc, const char **argv)
{
	struct CU_Suite *suite;
	int code;

	CU_initialize_registry();
	suite = CU_add_suite("suite", NULL, NULL);
	cunit_add_tests(suite);

	code = CU_minimal_run_tests();
	CU_cleanup_registry();

	return code;
}
