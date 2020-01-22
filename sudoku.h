#ifndef SUDOKU_H
# define SUDOKU_H

#include <unistd.h>

typedef int bool;

# define N 9
# define true 1
# define false 0

int BOARD[N][N];

bool    is_row_safe(int row, int num);
bool    is_col_safe(int col, int num);
bool    is_sq_safe(int row, int col, int num);
bool    is_unsigned_cell(int *row, int *col);
bool    is_safe(int row, int col, int num);
bool    solver(int arr[N][N]);
void    print_sudoku(int arr[N][N]);
void    solve_sudoku(char *av[]);
bool    is_valid(char **av);
bool    len_valid(char *str);

#endif
