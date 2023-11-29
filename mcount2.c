#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <stdlib.h>
#include <cxxabi.h>

clock_t start_time;

// Demangle the function name
char* demangle(const char* mangled_name) {
    int status;
    return abi::__cxa_demangle(mangled_name, 0, 0, &status);
}

#define MCOUNT_START() clock_t start_time = clock();
#define MCOUNT_END(func_name, start_time) do { \
            clock_t end_time = clock(); \
            double elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC; \
            char* demangled = demangle(func_name); \
            printf("Function %s took %f seconds to execute.\n", demangled, elapsed_time); \
            free(demangled); \
            fflush(stdout); \
} while (0)

void __attribute__((no_instrument_function)) __cyg_profile_func_enter(void* this_fn, void* call_site) {
    printf("%s\n", __func__);
    MCOUNT_START();
}

void __attribute__((no_instrument_function)) __cyg_profile_func_exit(void* this_fn, void* call_site) {
    printf("%s\n", __func__);
    MCOUNT_END(__builtin_return_address(0), start_time);
}

// Your code goes here

void foo() {
    for (int i = 0; i < 100000000; ++i) {};
}

int main() {
    foo();

    return 0;
}

