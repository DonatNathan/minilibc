#include <criterion/criterion.h>
#include <dlfcn.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Test (my_strchr, string)
{
    void *handle;
    char *(*my_strchr)(const char *, int);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strchr = dlsym(handle, "strchr");
    cr_assert_eq(strchr("Le roi des Pirates", 'P'), my_strchr("Le roi des Pirates", 'P'));
}

Test (my_strchr, empty_string)
{
    void *handle;
    char *(*my_strchr)(const char *, int);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strchr = dlsym(handle, "strchr");
    cr_assert_eq(strchr("", 'P'), my_strchr("", 'P'));
}

Test (my_strchr, no_char_in_string)
{
    void *handle;
    char *(*my_strchr)(const char *, int);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strchr = dlsym(handle, "strchr");
    cr_assert_eq(strchr("Le roi des pirates", 'P'), my_strchr("Le roi des pirates", 'P'));
}

Test (my_strchr, first_string)
{
    void *handle;
    char *(*my_strchr)(const char *, int);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strchr = dlsym(handle, "strchr");
    cr_assert_eq(strchr("Le roi des pirates", 'L'), my_strchr("Le roi des pirates", 'L'));
}

Test (my_strchr, last_string)
{
    void *handle;
    char *(*my_strchr)(const char *, int);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strchr = dlsym(handle, "strchr");
    cr_assert_eq(strchr("Le roi de pirates", 's'), my_strchr("Le roi de pirates", 's'));
}

Test (my_strchr, null_char)
{
    void *handle;
    char *(*my_strchr)(const char *, int);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strchr = dlsym(handle, "strchr");
    cr_assert_eq(strchr("Le roi de pirates", 0), my_strchr("Le roi de pirates", 0));
}

Test (my_strchr, all_empty)
{
    void *handle;
    char *(*my_strchr)(const char *, int);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strchr = dlsym(handle, "strchr");
    cr_assert_eq(strchr("", 0), my_strchr("", 0));
}

Test (my_strchr, full_p)
{
    void *handle;
    char *(*my_strchr)(const char *, int);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strchr = dlsym(handle, "strchr");
    cr_assert_eq(strchr("pppppppppppp", 'p'), my_strchr("pppppppppppp", 'p'));
}

Test (my_strchr, case)
{
    void *handle;
    char *(*my_strchr)(const char *, int);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strchr = dlsym(handle, "strchr");
    cr_assert_eq(strchr("Pppppppppppp", 'p'), my_strchr("Pppppppppppp", 'p'));
}

Test (my_strchr, diff_case)
{
    void *handle;
    char *(*my_strchr)(const char *, int);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strchr = dlsym(handle, "strchr");
    cr_assert_eq(strchr("a", 'p'), my_strchr("a", 'p'));
}