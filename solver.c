#include "rush01.h"

// Find the next empty cell in the grid
int	next_empty_cell(int *row, int *col, int **grid)
{
	*row = 0;
	*col = 0;

	while (*row < 4)
	{
		*col = 0;
		while (*col < 4)
		{
			if (grid[*row][*col] == 0)  // Empty cell found
				return (1);
			(*col)++;
		}
		(*row)++;
	}
	return (0);  // No empty cell found
}

int	solve_grid(int **grid, int views[16])  // Change to int **grid
{
	int row = 0;
	int col = 0;
	int num;

	if (!next_empty_cell(&row, &col, grid))
		return (1);  // No empty cells, puzzle solved

	num = 1;
	while (num <= 4)
	{
		if (is_valid_placement(grid, row, col, num, views))  // Call with int **grid
		{
			grid[row][col] = num;
			if (solve_grid(grid, views))  // Call with int **grid
				return (1);
			grid[row][col] = 0;  // Backtrack
		}
		num++;
	}
	return (0);
}

