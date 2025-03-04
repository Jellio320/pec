#include "common.h"

char string_repeats(const char *string, size_t n) {
	char chr = *string;

	while (n-- && *string) {
		if (*string++ != chr) {
			return 0;
		}
	}

	return chr;
}

size_t remove_trailings(char *string, size_t length, char chr) {
	while (length--) {
		if (string[length] == chr) {
			string[length] = '\0';
		} else {
			return ++length;
		}
	}

	return 0;
}

size_t remove_nontrailings(char *string, size_t length, char chr) {
	while (length--) {
		if (string[length] != chr) {
			string[length] = '\0';
		} else {
			return ++length;
		}
	}

	return 0;
}
