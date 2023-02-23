#include <criterion/criterion.h>
#include <dlfcn.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Test (my_strcmp, trois_p)
{
    void *handle;
    int (*my_strcmp)(const char *, const char *);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strcmp = dlsym(handle, "strcmp");
    cr_assert_eq(strcmp("Salut toi", "Salut toi"), my_strcmp("Salut toi", "Salut toi"));
}

Test (my_strcmp, full_string)
{
    void *handle;
    int (*my_strcmp)(const char *, const char *);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strcmp = dlsym(handle, "strcmp");
    cr_assert_eq(strcmp("Toto", "Toto"), my_strcmp("Toto", "Toto"));
}

Test (my_strcmp, zero_string)
{
    void *handle;
    int (*my_strcmp)(const char *, const char *);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strcmp = dlsym(handle, "strcmp");
    // printf("Real : '%d'\nMe : '%d'\n", strcmp("O", "T", 0), my_strcmp("O", "T", 0));
    cr_assert_eq(strcmp("O", "T"), my_strcmp("O", "T"));
}

Test (my_strcmp, empty_right)
{
    void *handle;
    int (*my_strcmp)(const char *, const char *);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strcmp = dlsym(handle, "strcmp");
    // printf("Real : '%d'\nMe : '%d'\n", strcmp("O", "", 3), my_strcmp("O", "", 3));
    cr_assert_eq(strcmp("O", ""), my_strcmp("O", ""));
}

Test (my_strcmp, empty_left)
{
    void *handle;
    int (*my_strcmp)(const char *, const char *);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strcmp = dlsym(handle, "strcmp");
    // printf("Real : '%d'\nMe : '%d'\n", strcmp("", "T", 1), my_strcmp("", "T", 1));
    cr_assert_eq(strcmp("", "T"), my_strcmp("", "T"));
}