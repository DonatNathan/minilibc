#include <criterion/criterion.h>
#include <dlfcn.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Test (my_strncmp, trois_p)
{
    void *handle;
    int (*my_strncmp)(const char *, const char *, size_t);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strncmp = dlsym(handle, "strncmp");
    cr_assert_eq(strncmp("Salut toi", "Salut toi", 3), my_strncmp("Salut toi", "Salut toi", 3));
}

Test (my_strncmp, full_string)
{
    void *handle;
    int (*my_strncmp)(const char *, const char *, size_t);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strncmp = dlsym(handle, "strncmp");
    cr_assert_eq(strncmp("Toto", "Toto", 4), my_strncmp("Toto", "Toto", 4));
}

Test (my_strncmp, zero_string)
{
    void *handle;
    int (*my_strncmp)(const char *, const char *, size_t);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strncmp = dlsym(handle, "strncmp");
    // printf("Real : '%d'\nMe : '%d'\n", strncmp("O", "T", 0), my_strncmp("O", "T", 0));
    cr_assert_eq(strncmp("O", "T", 0), my_strncmp("O", "T", 0));
}

Test (my_strncmp, empty_right)
{
    void *handle;
    int (*my_strncmp)(const char *, const char *, size_t);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strncmp = dlsym(handle, "strncmp");
    // printf("Real : '%d'\nMe : '%d'\n", strncmp("O", "", 3), my_strncmp("O", "", 3));
    cr_assert_eq(strncmp("O", "", 3), my_strncmp("O", "", 3));
}

Test (my_strncmp, empty_left)
{
    void *handle;
    int (*my_strncmp)(const char *, const char *, size_t);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strncmp = dlsym(handle, "strncmp");
    // printf("Real : '%d'\nMe : '%d'\n", strncmp("", "T", 1), my_strncmp("", "T", 1));
    cr_assert_eq(strncmp("", "T", 1), my_strncmp("", "T", 1));
}

Test (my_strncmp, two_left)
{
    void *handle;
    int (*my_strncmp)(const char *, const char *, size_t);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strncmp = dlsym(handle, "strncmp");
    // printf("Real : '%d'\nMe : '%d'\n", strncmp("a", "aa", 1), my_strncmp("a", "aa", 1));
    cr_assert_eq(strncmp("a", "aa", 1), my_strncmp("a", "aa", 1));
}

Test (my_strncmp, two_right)
{
    void *handle;
    int (*my_strncmp)(const char *, const char *, size_t);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strncmp = dlsym(handle, "strncmp");
    // printf("Real : '%d'\nMe : '%d'\n", strncmp("", "T", 1), my_strncmp("", "T", 1));
    cr_assert_eq(strncmp("aa", "a", 1), my_strncmp("aa", "a", 1));
}