#include <qstruct/qstruct.internal.h>

const static char *qstruct_result_strings[] = {
	"OK",
	"INDEX_OUTOF_BOUND",
	"VALUE_NOT_FOUND",
	"KEY_NOT_FOUND",
	"OUT_OF_MEMORY",
};

const char *qstruct_result_string(qstruct_result_t res) {
	if (res > (sizeof(qstruct_result_strings) / sizeof(qstruct_result_strings[0])))
		return "UNKNOWN";
	return qstruct_result_strings[res];
}

