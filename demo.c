/*
 * This is a demo program using an output handler for CUnit that aims
 * to mimic the Nette Tester (PHP unit testing framework).
 *
 * The program creates a demo CUnit test suite. It adds some dummy tests
 * that can be made failing (by setting the global variable `testval`
 * to a value different from 11) and runs the suite to show customized
 * CUnit's output.
 */

#include <unistd.h>
#include <CUnit/CUnit.h>
#include "cunit-colorful.h"

static int testval = 11;

static void test_passing(void)
{
	int i;
	CU_ASSERT_EQUAL(11, 11);
	/*
	 * Do some work to make visible delays between the tests. We
	 * cannot just use `usleep()` function here for CUnit measures
	 * elapsed time with `clock()` function that measures processor
	 * time but not real seconds. For that reason, we need to make
	 * the program really do something...
	 */
	for(i = 0; i < 10000000; i++)
		;
}

static void test_failing(void)
{
	/*
	 * If you want to have this test failing, set variable
	 * `testval` to value different from 11 in your `main()`
	 * function.
	 */
	CU_ASSERT_EQUAL(11, testval);

	usleep(500 * 1000);
}

static int cunit_add_tests(struct CU_Suite *suite)
{
	if (!CU_add_test(suite, "lorem_ipsum_dolor_sit_amet", test_passing) ||
	    !CU_add_test(suite, "consectetur_adipiscing_elit", test_passing) ||
	    !CU_add_test(suite, "phasellus_ullamcorper_nulla_consequat", test_passing) ||
	    !CU_add_test(suite, "euismod_congue", test_passing) ||
	    !CU_add_test(suite, "quisque_tincidunt_pellentesque_arcu_odio_augue", test_passing) ||
	    !CU_add_test(suite, "dapibus_sit_amet_justo", test_passing) ||
	    !CU_add_test(suite, "pretium_rhoncus_neque", test_passing) ||
	    !CU_add_test(suite, "vivamus_consectetur_felis_odio", test_passing) ||
	    !CU_add_test(suite, "vitae_congue_urna_tincidunt_a", test_passing) ||
	    !CU_add_test(suite, "nullam_semper_mollis_libero_laoreet_iaculis", test_passing) ||
	    !CU_add_test(suite, "purus_sodales_eget", test_passing) ||
	    !CU_add_test(suite, "curabitur_non_tortor_eu_diam_viverra_eleifend", test_passing) ||
	    !CU_add_test(suite, "etiam_pulvinar_purus_nunc", test_passing) ||
	    !CU_add_test(suite, "a_molestie_ante_semper_tempor", test_failing) || /* may be made failing */
	    !CU_add_test(suite, "nam_porttitor_ipsum_id_ultricies_finibus", test_passing) ||
	    !CU_add_test(suite, "donec_nulla eros", test_passing) ||
	    !CU_add_test(suite, "gravida_id_maximus_pellentesque", test_passing) ||
	    !CU_add_test(suite, "malesuada_id_risus", test_passing) ||
	    !CU_add_test(suite, "ut_finibus_ligula_est_et_blandit_elit_molestie_eget", test_passing) ||
	    !CU_add_test(suite, "etiam_suscipit_ipsum_sagittis", test_failing) || /* may be made failing */
	    !CU_add_test(suite, "quam_scelerisque", test_passing) ||
	    !CU_add_test(suite, "at_ornare", test_passing) ||
	    !CU_add_test(suite, "tortor_pharetra_cras_non_elit_erat", test_passing))
		CU_cleanup_registry();

	return CU_get_error();
}

int main(int argc, const char **argv)
{
	struct CU_Suite *suite;
	int code;

	if ((code = CU_initialize_registry()) != CUE_SUCCESS)
		return code;

	if ((suite = CU_add_suite("suite", NULL, NULL)) == NULL) {
		code = -1;
		goto out;
	}

	if ((code = cunit_add_tests(suite)) != CUE_SUCCESS)
		goto out;

	if (argc > 1 && argv[1])
		testval = 1;

	/*
	 * If some test has failed, return code will be
	 * a non-zero value.
	 */
	code = CU_colorful_run_tests();

out:
	CU_cleanup_registry();
	return code;
}
