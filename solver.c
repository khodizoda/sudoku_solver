#include "sudoku.h"

bool    solver(int arr[N][N])
{
    int row;
    int col;
    int num;

    num = 1;
    if (!(is_unsigned_cell(&row, &col)))
        return (true);
    while (num <= N)
    {
        if (is_safe(row, col, num))
        {
            arr[row][col] = num;
            //backtracking
            if (solver(arr))
                return (true);
            arr[row][col] = 0;
        }
        num++;
    }
    return (false);
}
