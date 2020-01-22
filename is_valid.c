#include "sudoku.h"

bool    is_valid(char **av)
{
    int i;
    int j;

    i = 1;
    while (i <= N)
    {
        if (len_valid(av[i]))
        {
            j = 0;
            while (j < N)
            {
                if (!((av[i][j] == '.') || (av[i][j] >= '1' && av[i][j] <= '9')))
                    return (false);
                j++;
            }
        }
        else
            return (false);
        i++;
    }
    return (true);
}
