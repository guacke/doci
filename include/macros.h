#ifndef MACROS_H
# define MACROS_H

#include <stdlib.h>
#include <math.h>
#define TOLERANCE 1e-10
#define COMPARE(X, Y)   (fabs((X) - (Y)) < TOLERANCE)

#define safe_malloc(s, t) safe_malloc_helper((s), sizeof(t), #t, __FILE__, __LINE__, __func__)
#define safe_calloc(s, t) safe_calloc_helper((s), sizeof(t), #t, __FILE__, __LINE__, __func__)
#define safe_free(ptr) \
  do { \
    free(ptr); \
    ptr = NULL; \
  } while (0)

void* safe_malloc_helper(int s, size_t t, const char *typ, const char *file, int line, const char *func);

void* safe_calloc_helper(int s, size_t t, const char *typ, const char *file, int line, const char *func);

void safe_free_helper(void *ptr, const char *ptrname, const char *file, int line, const char *func);
#endif
