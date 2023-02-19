#include <criterion/criterion.h>
#include <dlfcn.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Test (my_memcpy, trois_p)
{
    void *handle;
    void *(*my_memcpy)(void *, const void *, size_t);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_memcpy = dlsym(handle, "memcpy");
    char *string1 = strdup("Le roi des Pirates");
    char *string2 = strdup("Le roi des Pirates");
    char *string3 = strdup("Toto");
    memcpy(string1, string3, 3);
    my_memcpy(string2, string3, 3);
    int result = strcmp(string1, string2);
    cr_assert_eq(0, result);
}

// Why ?
Test (my_memcpy, empty_string)
{
    void *handle;
    void *(*my_memcpy)(void *, const void *, size_t);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_memcpy = dlsym(handle, "memcpy");
    char *string1 = strdup("");
    char *string2 = strdup("");
    char *string3 = strdup("Toto");
    memcpy(string1, string3, 1);
    my_memcpy(string2, string3, 1);
    printf("String 1 first : '%s'\n", string1);
    printf("String 2 first : '%s'\n", string2);
    int result = strcmp(string1, string2);
    cr_assert_eq(0, result);
}

// Why ?
Test (my_memcpy, empty_string2)
{
    void *handle;
    void *(*my_memcpy)(void *, const void *, size_t);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_memcpy = dlsym(handle, "memcpy");
    char *string1 = strdup("Salut");
    char *string2 = strdup("Salut");
    char *string3 = strdup("");
    memcpy(string1, string3, 1);
    my_memcpy(string2, string3, 1);
    printf("String 1 bis : '%s'\n", string1);
    printf("String 2 bis : '%s'\n", string2);
    int result = strcmp(string1, string2);
    cr_assert_eq(0, result);
}

Test (my_memcpy, one_string)
{
    void *handle;
    void *(*my_memcpy)(void *, const void *, size_t);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_memcpy = dlsym(handle, "memcpy");
    char *string1 = strdup("0");
    char *string2 = strdup("0");
    char *string3 = strdup("T");
    memcpy(string1, string3, 1);
    my_memcpy(string2, string3, 1);
    int result = strcmp(string1, string2);
    cr_assert_eq(0, result);
}

Test (my_memcpy, zero_string)
{
    void *handle;
    void *(*my_memcpy)(void *, const void *, size_t);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_memcpy = dlsym(handle, "memcpy");
    char *string1 = strdup("Salut");
    char *string2 = strdup("Salut");
    char *string3 = strdup("Toto");
    memcpy(string1, string3, 0);
    my_memcpy(string2, string3, 0);
    int result = strcmp(string1, string2);
    cr_assert_eq(0, result);
}
