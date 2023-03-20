#include "libft.h"

static size_t ft_strlen(const char *str)
{
    size_t i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

char *strdup(const char *s1)
{
    char *cpy;
    size_t i;

    cpy = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
    i = 0;
    while (s1[i])
    {
        cpy[i] = s1[i];
        i++;
    }
    cpy[i] = 0;
    return (cpy);
}