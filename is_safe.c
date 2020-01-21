#include "sudoku.h"

bool    is_safe(int row, int col, int num)
{
    if (BOARD[row][col] == 0 && is_row_safe(row, num)
        && is_col_safe(col, num) && is_sq_safe(row, col, num))
        return (true);
    return (false);
}
