#include "rush01.h"
#include <stdlib.h>

int	main(int ac, char **av)
{
	int **grid;
	int *views;

	// Allocate memory for a 4x4 grid and the views array
	grid = (int **)malloc(4 * sizeof(int *));
	for (int i = 0; i < 4; i++)
		grid[i] = (int *)malloc(4 * sizeof(int));

	views = (int *)malloc(16 * sizeof(int));

	// Check for correct number of arguments and validate input
	if (ac != 2 || !validate_input(av[1]))
	{
		write(1, "Error\n", 6);
		// Free allocated memory before exiting
		for (int i = 0; i < 4; i++)
			free(grid[i]);
		free(grid);
		free(views);
		return (1);
	}

	// Parse input and initialize grid
	parse_input(av[1], views);
	initialize_grid(grid);

	// Attempt to solve the puzzle
	if (solve_grid(grid, views))
		print_grid(grid);
	else
		write(1, "Error\n", 6);

	// Free allocated memory after solving
	for (int i = 0; i < 4; i++)
		free(grid[i]);
	free(grid);
	free(views);

	return (0);
}

