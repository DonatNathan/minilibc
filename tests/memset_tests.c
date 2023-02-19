#include <criterion/criterion.h>
#include <dlfcn.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Test (my_memset, trois_p)
{
    void *handle;
    void *(*my_memset)(void *, int, size_t);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_memset = dlsym(handle, "memset");
    char *string1 = strdup("Le roi des Pirates");
    char *string2 = strdup("Le roi des Pirates");
    memset(string1, 'P', 3);
    my_memset(string2, 'P', 3);
    int result = strcmp(string1, string2);
    cr_assert_eq(0, result);
}

// Why ?
Test (my_memset, empty_string)
{
    void *handle;
    void *(*my_memset)(void *, int, size_t);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_memset = dlsym(handle, "memset");
    char *string1 = strdup("");
    char *string2 = strdup("");
    memset(string1, 'P', 1);
    my_memset(string2, 'P', 1);
    printf("String 1 : '%s'\n", string1);
    printf("String 2 : '%s'\n", string2);
    int result = strcmp(string1, string2);
    cr_assert_eq(0, result);
}

Test (my_memset, one_string)
{
    void *handle;
    void *(*my_memset)(void *, int, size_t);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_memset = dlsym(handle, "memset");
    char *string1 = strdup("0");
    char *string2 = strdup("0");
    memset(string1, 'P', 1);
    my_memset(string2, 'P', 1);
    int result = strcmp(string1, string2);
    cr_assert_eq(0, result);
}

Test (my_memset, zero_string)
{
    void *handle;
    void *(*my_memset)(void *, int, size_t);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_memset = dlsym(handle, "memset");
    char *string1 = strdup("Salut");
    char *string2 = strdup("Salut");
    memset(string1, 'P', 0);
    my_memset(string2, 'P', 0);
    int result = strcmp(string1, string2);
    cr_assert_eq(0, result);
}
