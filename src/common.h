#ifndef COMMON_H
#define COMMON_H

#include <stddef.h>

char string_repeats(const char *string, size_t n);
size_t remove_trailings(char *string, size_t length, char chr);
size_t remove_nontrailings(char *string, size_t length, char chr);

#endif