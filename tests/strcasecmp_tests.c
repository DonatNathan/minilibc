#include <criterion/criterion.h>
#include <dlfcn.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Test (my_strcasecmp, basic_string)
{
    void *handle;
    int (*my_strcasecmp)(const char *, const char *);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strcasecmp = dlsym(handle, "strcasecmp");
    cr_assert_eq(strcasecmp("Toto", "Toto"), my_strcasecmp("Toto", "Toto"));
}

Test (my_strcasecmp, empty_left)
{
    void *handle;
    int (*my_strcasecmp)(const char *, const char *);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strcasecmp = dlsym(handle, "strcasecmp");
    cr_assert_eq(strcasecmp("", "Toto"), my_strcasecmp("", "Toto"));
}

Test (my_strcasecmp, empty_right)
{
    void *handle;
    int (*my_strcasecmp)(const char *, const char *);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strcasecmp = dlsym(handle, "strcasecmp");
    cr_assert_eq(strcasecmp("Toto", ""), my_strcasecmp("Toto", ""));
}

Test (my_strcasecmp, empty_left_a)
{
    void *handle;
    int (*my_strcasecmp)(const char *, const char *);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strcasecmp = dlsym(handle, "strcasecmp");
    cr_assert_eq(strcasecmp("", "a"), my_strcasecmp("", "a"));
}

Test (my_strcasecmp, empty_right_a)
{
    void *handle;
    int (*my_strcasecmp)(const char *, const char *);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strcasecmp = dlsym(handle, "strcasecmp");
    cr_assert_eq(strcasecmp("a", ""), my_strcasecmp("a", ""));
}

Test (my_strcasecmp, empty)
{
    void *handle;
    int (*my_strcasecmp)(const char *, const char *);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strcasecmp = dlsym(handle, "strcasecmp");
    cr_assert_eq(strcasecmp("", ""), my_strcasecmp("", ""));
}

Test (my_strcasecmp, diff_case)
{
    void *handle;
    int (*my_strcasecmp)(const char *, const char *);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strcasecmp = dlsym(handle, "strcasecmp");
    cr_assert_eq(strcasecmp("ToTo", "Toto"), my_strcasecmp("ToTo", "Toto"));
}

Test (my_strcasecmp, test_32)
{
    void *handle;
    int (*my_strcasecmp)(const char *, const char *);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strcasecmp = dlsym(handle, "strcasecmp");
    // printf("Valid : '%d'\nInvalid : '%d'\n", strcasecmp("caw caw motherfuckers", "caw Caw"), my_strcasecmp("caw caw motherfuckers", "caw Caw"));
    cr_assert_eq(strcasecmp("caw caw motherfuckers", "caw Caw"), my_strcasecmp("caw caw motherfuckers", "caw Caw"));
}
