#include "sudoku.h"

bool    len_valid(char *str)
{
    int i;

    i = 0;
    while (*str)
    {
        if ((i == N - 1) && (*(str + 1) == '\0'))
            return (true);
        str++;
        i++;
    }
    return (false);
}
