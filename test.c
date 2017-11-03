#include <unistd.h>
#include <CUnit/CUnit.h>
#include "cunit-minimal.h"

static int testval = 11;

static void test_passing(void)
{
	CU_ASSERT_EQUAL(11, 11);
	usleep(10 * 1000);
}

static void test_failing(void)
{
	CU_ASSERT_EQUAL(11, testval);
}

static void cunit_add_tests(struct CU_Suite *suite)
{
	CU_add_test(suite, "lorem_ipsum_dolor_sit_amet", test_passing);
	CU_add_test(suite, "consectetur_adipiscing_elit", test_passing);
	CU_add_test(suite, "phasellus_ullamcorper_nulla_consequat", test_passing);
	CU_add_test(suite, "euismod_congue", test_passing);
	CU_add_test(suite, "quisque_tincidunt_pellentesque_arcu_odio_augue", test_passing);
	CU_add_test(suite, "dapibus_sit_amet_justo", test_passing);
	CU_add_test(suite, "pretium_rhoncus_neque", test_passing);
	CU_add_test(suite, "vivamus_consectetur_felis_odio", test_passing);
	CU_add_test(suite, "vitae_congue_urna_tincidunt_a", test_passing);
	CU_add_test(suite, "nullam_semper_mollis_libero_laoreet_iaculis", test_passing);
	CU_add_test(suite, "purus_sodales_eget", test_passing);
	CU_add_test(suite, "curabitur_non_tortor_eu_diam_viverra_eleifend", test_passing);
	CU_add_test(suite, "etiam_pulvinar_purus_nunc", test_passing);
	CU_add_test(suite, "a_molestie_ante_semper_tempor", test_failing);
	CU_add_test(suite, "nam_porttitor_ipsum_id_ultricies_finibus", test_passing);
	CU_add_test(suite, "donec_nulla eros", test_passing);
	CU_add_test(suite, "gravida_id_maximus_pellentesque", test_passing);
	CU_add_test(suite, "malesuada_id_risus", test_passing);
	CU_add_test(suite, "ut_finibus_ligula_est_et_blandit_elit_molestie_eget", test_passing);
	CU_add_test(suite, "etiam_suscipit_ipsum_sagittis", test_failing);
	CU_add_test(suite, "quam_scelerisque", test_passing);
	CU_add_test(suite, "at_ornare", test_passing);
	CU_add_test(suite, "tortor_pharetra_cras_non_elit_erat", test_passing);
}

int main(int argc, const char **argv)
{
	struct CU_Suite *suite;
	int code;

	CU_initialize_registry();
	suite = CU_add_suite("suite", NULL, NULL);
	cunit_add_tests(suite);

	if (argc > 1 && argv[1])
		testval = 1;

	code = CU_minimal_run_tests();
	CU_cleanup_registry();

	return code;
}
