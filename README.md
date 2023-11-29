
# profile
Examples for profiling code
mcount1.c contains custom pre-entry/exit functions to every function call and when compiled with  generates mcount1 as executable and prints the time spent in each function call
gcc -finstrument-functions -g mcount1.c -o mcount1

in this case main, foo
aks@RA7LRlHkzXNHyA2:~/code/profile$ ./mcount1
__cyg_profile_func_enter
__cyg_profile_func_enter
__cyg_profile_func_exit
Function �����UH��SH�H�H��H�����H�������� took 0.128022 seconds to execute.
__cyg_profile_func_exit
Function ��H�]��� took 0.128037 seconds to execute.

function name demangling has to be done which seems to be failing and __builtin_return_address(0) should return the callee function name but the symbol conversion not happening. TBD.
