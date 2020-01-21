NAME = rush_01

GCC = gcc

CFLAGS = -Wall -Wextra -Werror -I./sudoku.h

HEAD = ./sudoku.h

SRCS = ./is_row_safe.c ./is_col_safe.c ./is_sq_safe.c \
		./is_unsigned_cell.c ./is_safe.c ./solver.c \
		./print_sudoku.c ./solve_sudoku.c ./main.c

OBJ = ./is_row_safe.o ./is_col_safe.o ./is_sq_safe.o \
		./is_unsigned_cell.o ./is_safe.o ./solver.o \
		./print_sudoku.o ./solve_sudoku.o ./main.o

$(NAME): $(OBJ)
	$(GCC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ): $(SRCS) $(HEAD)
	$(GCC) -c $(CFLAGS) $(SRCS)

all: $(NAME)

clean:
	@/bin/rm -f $(OBJ)

fclean:
	@/bin/rm -rf $(NAME)

re: fclean all