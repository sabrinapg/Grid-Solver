#include "rush01.h"
#include <stdlib.h>

// Initialize the grid (set all values to 0)
void	initialize_grid(int **grid)
{
	int row = 0;
	int col;

	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			grid[row][col] = 0;
			col++;
		}
		row++;
	}
}

// Print the grid
void	print_grid(int **grid)
{
	int row = 0;
	int col;

	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			char c = grid[row][col] + '0';
			write(1, &c, 1);
			if (col < 3)
				write(1, " ", 1);
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
}

