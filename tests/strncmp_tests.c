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

// Test (my_strncmp, empty_string)
// {
//     void *handle;
//     int (*my_strncmp)(const char *, const char *, size_t);
//     handle = dlopen("./libasm.so", RTLD_LAZY);
//     my_strncmp = dlsym(handle, "strncmp");
//     printf("First BIS : '%d'\n", strncmp("", "T", 1));
//     printf("Seconde BIS : '%d'\n", my_strncmp("", "T", 1));
//     cr_assert_eq(strncmp("", "T", 1), my_strncmp("", "T", 1));
// }

// Test (my_strncmp, empty_string2)
// {
//     void *handle;
//     int (*my_strncmp)(const char *, const char *, size_t);
//     handle = dlopen("./libasm.so", RTLD_LAZY);
//     my_strncmp = dlsym(handle, "strncmp");
//     printf("First : '%d'\n", strncmp("O", "", 1));
//     printf("Seconde : '%d'\n", my_strncmp("O", "", 1));
//     cr_assert_eq(strncmp("O", "", 1), my_strncmp("O", "", 1));
// }

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
    cr_assert_eq(strncmp("O", "T", 0), my_strncmp("O", "T", 0));
}