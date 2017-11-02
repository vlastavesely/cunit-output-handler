#include <assert.h>
#include "cunit-minimal.h"


static void cunit_minimal_test_start_msg_handler(struct CU_Test *test,
		struct CU_Suite *suite)
{
	/* nothing */
}

static void cunit_minimal_test_complete_msg_handler(struct CU_Test *test,
		struct CU_Suite *suite,
		struct CU_FailureRecord *failures)
{
	assert(suite != NULL);
	assert(test != NULL);

	fprintf(stdout, failures == NULL ? "." : "\x1b[41;1mF\x1b[0m");
	fflush(stdout);
}

static void cunit_minimal_all_tests_complete_msg_handler(struct CU_FailureRecord *failure)
{
	fprintf(stdout, "\n-------------------------------------\n");
}

static CU_ErrorCode cunit_minimal_initialize(void)
{
	CU_set_error(CUE_SUCCESS);

	CU_set_test_start_handler(cunit_minimal_test_start_msg_handler);
	CU_set_test_complete_handler(cunit_minimal_test_complete_msg_handler);
	CU_set_all_test_complete_handler(cunit_minimal_all_tests_complete_msg_handler);

	return CU_get_error();
}

CU_ErrorCode CU_minimal_run_tests(void)
{
	CU_ErrorCode error;

	if (CU_get_registry() == NULL)
		return CUE_NOREGISTRY;
	else if ((error = cunit_minimal_initialize()) == CUE_SUCCESS)
		return CU_run_all_tests();
}
