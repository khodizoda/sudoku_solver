#include "sudoku.h"

bool    is_col_safe(int col, int num)
{
    int r;

    r = 0;
    while (r < N)
    {
        if (BOARD[r][col] == num)
            return (false);
        r++;
    }
    return (true);
}
