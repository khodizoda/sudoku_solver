#include <unistd.h>

typedef int bool;

# define N 9
# define true 1
# define false 0

int BOARD[N][N];

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

bool    is_safe(int row, int col, int num)
{
    if (BOARD[row][col] == 0 && is_row_safe(row, num)
        && is_col_safe(col, num) && is_sq_safe(row, col, num))
        return (true);
    return (false);
}

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
        write(1, "No solution\n", 12);
}

int     main(int ac, char *av[])
{
    if (ac == N + 1)
        solve_sudoku(av);
    else
        write(1, "Error\n", 6);
    return (0);
}
