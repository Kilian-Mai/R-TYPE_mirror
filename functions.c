#include <stdlib.h>

unsigned int my_strlen(char const *str)
{
    register char const *i = str;

    for (; *i; ++i);
    return (i - str);
}

char *my_strcat(char const *s1, char const *s2)
{
    char *ret = malloc(my_strlen(s1) + my_strlen(s2) + 1);
    char *i = ret;

    if (!ret) return (NULL);
    for (; *s1; ++s1, ++i)
        *i = *s1;
    for (; *s2; ++s2, ++i)
        *i = *s2;
    *i = '\0';
    return (ret);
}