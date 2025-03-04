#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"

static const char *program_name;

static void remove_suffix(char *string, char *suffix) {
	char *s = string;
	size_t suffix_length = strlen(suffix);

	s = strstr(string, suffix);
	while (s != NULL) {
		string = s;

		s++;
		s = strstr(s, suffix);
	}

	/* suffix_length + 1 to also compare null bytes */
	if (strncmp(string, suffix, suffix_length + 1) == 0) {
		*string = '\0';
	}
}

static char *get_basename(char *string, size_t length) {
	char *base;

	if (string[0] == '\0') {
		return string;
	}

	if (string_repeats(string, length) == '/') {
		string = "/";
		return string;
	}

	remove_trailings(string, length, '/');

	if ((base = strrchr(string, '/')) == NULL) {
		return string;
	}

	return base + 1;
}

int main(int argc, char **argv) {
	program_name = argv[0];
	char *string, *suffix;

	if (argv[1] && strncmp(argv[1], "--", 3) == 0) {
		argc--;
		argv++;
	}

	if (argc < 2) {
		fprintf(stderr, "%s: too few arguments\n", program_name);
		return EXIT_FAILURE;
	}

	string = argv[1];
	suffix = argv[2]; /* suffix will be NULL when argc is 2 arguments */

	string = get_basename(string, strlen(string));

	if (suffix) {
		remove_suffix(string, suffix);
	}

	printf("%s\n", string);
	return EXIT_SUCCESS;
}