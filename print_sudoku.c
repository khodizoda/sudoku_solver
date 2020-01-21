#include "sudoku.h"

void    print_sudoku(int arr[N][N])
{
    int r;
    int c;
    char p;

    r = 0;
    while (r < N)
    {
        c = 0;
        while (c < N)
        {
            p = arr[r][c] + '0';
            write(1, &p, 1);
            write(1, "  ", 2);
            c++;
        }
        write(1, "\n", 1);
        r++;
    }
}
