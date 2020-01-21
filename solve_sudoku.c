#include "sudoku.h"

void    solve_sudoku(char *av[])
{
    int r;
    int i;
    int c;

    r = 0;
    i = 1;
    while (r < N)
    {
        c = 0;
        while (c < N)
        {
            if (av[i][c] == '.')
                BOARD[r][c] = 0;
            else
                BOARD[r][c] = av[i][c] - '0';
            c++;
        }
        r++;
        i++;
    }
    if (solver(BOARD))
        print_sudoku(BOARD);
    else
        write(1, "Error\n", 6);
}
