#ifndef RUSH01_H
# define RUSH01_H

# include <unistd.h>
# include <stdlib.h>

void	initialize_grid(int **grid);
int		is_valid_placement(int **grid, int row, int col, int num, int views[16]);
int		solve_grid(int **grid, int views[16]);
void	print_grid(int **grid);
int		validate_input(char *input);
void	parse_input(char *input, int views[16]);

// Add these function prototypes
int     next_empty_cell(int *row, int *col, int **grid);
int     check_visibility(int **grid, int views[16]);

#endif

