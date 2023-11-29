#include <dlfcn.h>
#include <stdio.h>
extern int dladdr(void *addr, Dl_info *info);

void printCallerName() {
    void *currentAddress = __builtin_return_address(0);
    Dl_info info;

    if (dladdr(currentAddress, &info) && info.dli_sname != NULL) {
        printf("Function %s called.\n", info.dli_sname);
    } else {
        printf("Unable to determine function name.\n");
    }
}

