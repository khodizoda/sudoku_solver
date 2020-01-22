#include "sudoku.h"

int     main(int ac, char *av[])
{
    if (ac == N + 1)
    {
        if (is_valid(av))
            solve_sudoku(av);
        else
            write(1, "Error\n", 6);
    }
    else
        write(1, "Error\n", 6);
    return (0);
}
