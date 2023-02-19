#include <criterion/criterion.h>
#include <dlfcn.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Test (my_strlen, basic_string)
{
    void *handle;
    int (*my_strlen)(const char *);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strlen = dlsym(handle, "strlen");
    cr_assert_eq(strlen("Hoy"), my_strlen("Hoy"));
}

Test (my_strlen, empty_string)
{
    void *handle;
    int (*my_strlen)(const char *);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strlen = dlsym(handle, "strlen");
    cr_assert_eq(strlen(""), my_strlen(""));
}

Test (my_strlen, one_string)
{
    void *handle;
    int (*my_strlen)(const char *);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strlen = dlsym(handle, "strlen");
    cr_assert_eq(my_strlen("L"), my_strlen("L"));
}
