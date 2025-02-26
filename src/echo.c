#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	const char *program_name = argv[0];

	--argc;
	++argv;
	while (argc > 0) {
		if (fputs(argv[0], stdout) == EOF) {
echo_error:
			perror(program_name);
			return EXIT_FAILURE;
		}

		--argc;
		++argv;
        if (argc > 0) {
            if (fputc(' ', stdout) == EOF) {
                goto echo_error;
            }
        }
	}
	fputc('\n', stdout);

	return EXIT_SUCCESS;
}