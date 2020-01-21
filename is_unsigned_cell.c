#include "sudoku.h"

bool    is_unsigned_cell(int *row, int *col)
{
    int r;
    int c;

    r = 0;
    while (r < N)
    {
        c = 0;
        while (c < N)
        {
            if (BOARD[r][c] == 0)
            {
                *row = r;
                *col = c;
                return (true);
            }
            c++;
        }
        r++;
    }
    return (false);
}
