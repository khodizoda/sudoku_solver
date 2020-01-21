#include "sudoku.h"

int     main(int ac, char *av[])
{
    if (ac == N + 1)
        solve_sudoku(av);
    else
        write(1, "Error\n", 6);
    return (0);
}
