#include <criterion/criterion.h>
#include <dlfcn.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Test (my_memmove, trois_p)
{
    void *handle;
    void *(*my_memmove)(void *, const void *, size_t);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_memmove = dlsym(handle, "memmove");
    char *string1 = strdup("Le roi des Pirates");
    char *string2 = strdup("Le roi des Pirates");
    char *string3 = strdup("Toto");
    memmove(string1, string3, 3);
    my_memmove(string2, string3, 3);
    int result = strcmp(string1, string2);
    cr_assert_eq(0, result);
}

Test (my_memmove, empty_string)
{
    void *handle;
    void *(*my_memmove)(void *, const void *, size_t);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_memmove = dlsym(handle, "memmove");
    char *string1 = strdup("");
    char *string2 = strdup("");
    char *string3 = strdup("Toto");
    memmove(string1, string3, 5);
    my_memmove(string2, string3, 5);
    int result = strcmp(string1, string2);
    cr_assert_eq(0, result);
}

Test (my_memmove, empty_string2)
{
    void *handle;
    void *(*my_memmove)(void *, const void *, size_t);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_memmove = dlsym(handle, "memmove");
    char *string1 = strdup("Salut");
    char *string2 = strdup("Salut");
    char *string3 = strdup("");
    memmove(string1, string3, 1);
    my_memmove(string2, string3, 1);
    int result = strcmp(string1, string2);
    cr_assert_eq(0, result);
}

Test (my_memmove, one_string)
{
    void *handle;
    void *(*my_memmove)(void *, const void *, size_t);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_memmove = dlsym(handle, "memmove");
    char *string1 = strdup("0");
    char *string2 = strdup("0");
    char *string3 = strdup("T");
    memmove(string1, string3, 1);
    my_memmove(string2, string3, 1);
    int result = strcmp(string1, string2);
    cr_assert_eq(0, result);
}

Test (my_memmove, zero_string)
{
    void *handle;
    void *(*my_memmove)(void *, const void *, size_t);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_memmove = dlsym(handle, "memmove");
    char *string1 = strdup("Salut");
    char *string2 = strdup("Salut");
    char *string3 = strdup("Toto");
    memmove(string1, string3, 0);
    my_memmove(string2, string3, 0);
    int result = strcmp(string1, string2);
    cr_assert_eq(0, result);
}

// Test (my_memmove, biggest)
// {
//     void *handle;
//     void *(*my_memmove)(void *, const void *, size_t);
//     handle = dlopen("./libasm.so", RTLD_LAZY);
//     my_memmove = dlsym(handle, "memmove");
//     char *string1 = strdup("Salut");
//     char *string2 = strdup("Salut");
//     char *string3 = strdup("Toto le roi des imbéciles");
//     memmove(string1, string3, 13);
//     my_memmove(string2, string3, 13);
//     int result = strcmp(string1, string2);
//     cr_assert_eq(0, result);
// }

Test (my_memmove, amazing_size)
{
    void *handle;
    void *(*my_memmove)(void *, const void *, size_t);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_memmove = dlsym(handle, "memmove");
    char *string1 = strdup("Salut");
    char *string2 = strdup("Salut");
    char *string3 = strdup("Toto le roi des imbéciles");
    memmove(string1, string3, 150);
    my_memmove(string2, string3, 150);
    int result = strcmp(string1, string2);
    cr_assert_eq(0, result);
}
