#include "sudoku.h"

bool    is_sq_safe(int row, int col, int num)
{
    int r;
    int c;
    int row_start;
    int col_start;

    row_start = (row / 3) * 3;
    col_start = (col / 3) * 3;
    r = row_start;
    while (r < row_start + 3)
    {
        c = col_start;
        while (c < col_start + 3)
        {
            if (BOARD[r][c] == num)
                return (false);
            c++;
        }
        r++;
    }
    return (true);
}
