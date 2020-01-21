#include "sudoku.h"

bool    is_row_safe(int row, int num)
{
    int c;

    c = 0;
    while (c < N)
    {
        if (BOARD[row][c] == num)
            return (false);
        c++;
    }
    return (true);
}
