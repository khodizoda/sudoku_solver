#include "sudoku.h"

void    solve_sudoku(char *av[])
{
    int r;
    int i;
    int c;

    r = -1;
    i = 0;
    while (++r < N && ++i <= N)
    {
        c = -1;
        while (++c < N)
        {
            if (av[i][c] == '.')
                BOARD[r][c] = 0;
            else
                BOARD[r][c] = av[i][c] - '0';
        }
    }
    if (solver(BOARD))
        print_sudoku(BOARD);
    else
        write(1, "Error\n", 6);
}
