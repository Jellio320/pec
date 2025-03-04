#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"

static const char *program_name;

static char *get_dirname(char *string, size_t length) {
	if (string_repeats(string, length) == '/') {
		string = "/";
		return string;
	}

	length = remove_trailings(string, length, '/');

	length = remove_nontrailings(string, length, '/');

	remove_trailings(string, length, '/');

	if (string[0] == '\0') {
		string = ".";
	}

	return string;
}

int main(int argc, char **argv) {
	program_name = argv[0];
	char *string;

	if (argv[1] && strncmp(argv[1], "--", 3) == 0) {
		argc--;
		argv++;
	}

	if (argc < 2) {
		fprintf(stderr, "%s: too few arguments\n", program_name);
		return EXIT_FAILURE;
	}

	string = argv[1];

	string = get_dirname(string, strlen(string));

	printf("%s\n", string);
	return EXIT_SUCCESS;
}