#include <test/test.h>
#include <qstruct/qstruct.h>

bool test_qstruct_arraylist_add_get() {
	test_run_log("qstruct_arraylist_add_get");

	qstruct_arraylist_t list;
	int value = 858585;
	int value2 = 696969;
	int return_val;

	bool success = 1;
	success &= qstruct_arraylist_create(&list, sizeof(int), 1) == QSTRUCT_RESULT_OK;
	success &= qstruct_arraylist_add(list, &value) == QSTRUCT_RESULT_OK;
	success &= qstruct_arraylist_add(list, &value2) == QSTRUCT_RESULT_OK;
	success &= qstruct_arraylist_get(list, &return_val, 0) == QSTRUCT_RESULT_OK;
	success &= return_val == value;
	success &= qstruct_arraylist_get(list, &return_val, 1) == QSTRUCT_RESULT_OK;
	success &= return_val == value2;
	success &= qstruct_arraylist_get(list, &return_val, 2) == QSTRUCT_RESULT_INDEX_OUTOF_BOUND;
	success &= qstruct_arraylist_destroy(list) == QSTRUCT_RESULT_OK;
	test_result_log(success);
	return success;
}

bool test_qstruct_arraylist_remove() {
	test_run_log("qstruct_arraylist_remove");

	qstruct_arraylist_t list;
	int value = 858585;
	int value2 = 696969;
	int return_val;

	bool success = 1;
	success &= qstruct_arraylist_create(&list, sizeof(int), 1) == QSTRUCT_RESULT_OK;
	success &= qstruct_arraylist_add(list, &value) == QSTRUCT_RESULT_OK;
	success &= qstruct_arraylist_add(list, &value2) == QSTRUCT_RESULT_OK;
	success &= qstruct_arraylist_get(list, &return_val, 0) == QSTRUCT_RESULT_OK;
	success &= return_val == value;
	success &= qstruct_arraylist_remove(list, 0) == QSTRUCT_RESULT_OK;
	success &= qstruct_arraylist_get(list, &return_val, 0) == QSTRUCT_RESULT_OK;
	success &= return_val == value2;
	success &= qstruct_arraylist_get(list, &return_val, 1) == QSTRUCT_RESULT_INDEX_OUTOF_BOUND;
	success &= qstruct_arraylist_destroy(list) == QSTRUCT_RESULT_OK;
	test_result_log(success);
	return success;
}

bool test_qstruct_arraylist_length() {
	test_run_log("qstruct_arraylist_length");

	qstruct_arraylist_t list;
	int value = 858585;
	int value2 = 696969;
	int return_val;

	bool success = 1;
	success &= qstruct_arraylist_create(&list, sizeof(int), 1) == QSTRUCT_RESULT_OK;
	success &= qstruct_arraylist_length(list) == 0;
	success &= qstruct_arraylist_add(list, &value) == QSTRUCT_RESULT_OK;
	success &= qstruct_arraylist_add(list, &value2) == QSTRUCT_RESULT_OK;
	success &= qstruct_arraylist_length(list) == 2;
	success &= qstruct_arraylist_destroy(list) == QSTRUCT_RESULT_OK;
	test_result_log(success);
	return success;
}

bool test_qstruct_arraylist_clear() {
	test_run_log("qstruct_arraylist_clear");

	qstruct_arraylist_t list;
	int value = 858585;
	int value2 = 696969;
	int return_val;

	bool success = 1;
	success &= qstruct_arraylist_create(&list, sizeof(int), 1) == QSTRUCT_RESULT_OK;
	success &= qstruct_arraylist_add(list, &value) == QSTRUCT_RESULT_OK;
	success &= qstruct_arraylist_add(list, &value2) == QSTRUCT_RESULT_OK;
	success &= qstruct_arraylist_clear(list) == QSTRUCT_RESULT_OK;
	success &= qstruct_arraylist_length(list) == 0;
	success &= qstruct_arraylist_destroy(list) == QSTRUCT_RESULT_OK;
	test_result_log(success);
	return success;
}

bool test_qstruct_arraylist_set() {
	test_run_log("qstruct_arraylist_set");

	qstruct_arraylist_t list;
	int value = 858585;
	int value2 = 696969;
	int return_val;

	bool success = 1;
	success &= qstruct_arraylist_create(&list, sizeof(int), 1) == QSTRUCT_RESULT_OK;
	success &= qstruct_arraylist_add(list, &value) == QSTRUCT_RESULT_OK;
	success &= qstruct_arraylist_set(list, &value2, 0) == QSTRUCT_RESULT_OK;
	success &= qstruct_arraylist_length(list) == 1;
	success &= qstruct_arraylist_get(list, &return_val, 0) == QSTRUCT_RESULT_OK;
	success &= return_val == value2;
	success &= qstruct_arraylist_destroy(list) == QSTRUCT_RESULT_OK;
	test_result_log(success);
	return success;
}

bool test_qstruct_arraylist_insert() {
	test_run_log("qstruct_arraylist_insert");

	qstruct_arraylist_t list;
	int value = 858585;
	int value2 = 696969;
	int return_val;

	bool success = 1;
	success &= qstruct_arraylist_create(&list, sizeof(int), 1) == QSTRUCT_RESULT_OK;
	success &= qstruct_arraylist_add(list, &value) == QSTRUCT_RESULT_OK;
	success &= qstruct_arraylist_insert(list, &value2, 0) == QSTRUCT_RESULT_OK;
	success &= qstruct_arraylist_length(list) == 2;
	success &= qstruct_arraylist_get(list, &return_val, 0) == QSTRUCT_RESULT_OK;
	success &= return_val == value2;
	success &= qstruct_arraylist_get(list, &return_val, 1) == QSTRUCT_RESULT_OK;
	success &= return_val == value;
	success &= qstruct_arraylist_destroy(list) == QSTRUCT_RESULT_OK;
	test_result_log(success);
	return success;
}

bool test_qstruct_arraylist_convert_array() {
	test_run_log("qstruct_arraylist_convert_array");

	qstruct_arraylist_t list;
	int value = 858585;
	int value2 = 696969;
	int *arr;
	size_t arr_size;

	bool success = 1;
	success &= qstruct_arraylist_create(&list, sizeof(int), 1) == QSTRUCT_RESULT_OK;
	success &= qstruct_arraylist_add(list, &value) == QSTRUCT_RESULT_OK;
	success &= qstruct_arraylist_add(list, &value2) == QSTRUCT_RESULT_OK;
	arr = qstruct_arraylist_convert_array(list, &arr_size);
	success &= arr_size == 2;
	success &= arr[0] == value;
	success &= arr[1] == value2;
	test_result_log(success);
	return success;
}

bool test_qstruct_arraylist() {
	bool success = 1;
	success &= test_qstruct_arraylist_add_get();
	success &= test_qstruct_arraylist_remove();
	success &= test_qstruct_arraylist_length();
	success &= test_qstruct_arraylist_clear();
	success &= test_qstruct_arraylist_set();
	success &= test_qstruct_arraylist_insert();
	success &= test_qstruct_arraylist_convert_array();
	return success;
}
