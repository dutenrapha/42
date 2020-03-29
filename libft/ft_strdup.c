#include "libft.h"

char    *ft_strdup(const char *s1)
{
    char    *point;
    int        i;
    int        len;

    i = 0;
    len = 0;
    while (*(s1 + len) != '\0')
        len++;
    point = malloc(sizeof(char) * (len + 1));
    if (point == 0)
        return (0);
    while (*(s1 + i) != '\0')
    {
        *(point + i) = *(s1 + i);
        i++;
    }
    *(point + i) = '\0';
    return (point);
}
