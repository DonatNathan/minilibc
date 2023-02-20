#include <criterion/criterion.h>
#include <dlfcn.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
    
Test (my_strrchr, string)
{
    void *handle;
    char *(*my_strrchr)(const char *, int);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strrchr = dlsym(handle, "strrchr");
    cr_assert_eq(strrchr("Le roi des Pirates", 'P'), my_strrchr("Le roi des Pirates", 'P'));
}

Test (my_strrchr, empty_string)
{
    void *handle;
    char *(*my_strrchr)(const char *, int);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strrchr = dlsym(handle, "strrchr");
    cr_assert_eq(strrchr("", 'P'), my_strrchr("", 'P'));
}

Test (my_strrchr, no_char_in_string)
{
    void *handle;
    char *(*my_strrchr)(const char *, int);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strrchr = dlsym(handle, "strrchr");
    cr_assert_eq(strrchr("Le roi des pirates", 'P'), my_strrchr("Le roi des pirates", 'P'));
}

Test (my_strrchr, first_string)
{
    void *handle;
    char *(*my_strrchr)(const char *, int);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strrchr = dlsym(handle, "strrchr");
    cr_assert_eq(strrchr("Le roi des pirates", 'L'), my_strrchr("Le roi des pirates", 'L'));
}

Test (my_strrchr, last_string)
{
    void *handle;
    char *(*my_strrchr)(const char *, int);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strrchr = dlsym(handle, "strrchr");
    cr_assert_eq(strrchr("Le roi de pirates", 's'), my_strrchr("Le roi de pirates", 's'));
}

Test (my_strrchr, empty_char)
{
    void *handle;
    char *(*my_strrchr)(const char *, int);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strrchr = dlsym(handle, "strrchr");
    cr_assert_eq(strrchr("Le roi de pirates", 0), my_strrchr("Le roi de pirates", 0));
}
