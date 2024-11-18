#include "rush01.h"

int	is_valid_placement(int **grid, int row, int col, int num, int views[16])
{
    int i = 0;

    // Check if the number is already in the row or column
    while (i < 4)
    {
        if (grid[row][i] == num || grid[i][col] == num)
            return (0);
        i++;
    }

    // Temporarily place the number in the grid
    grid[row][col] = num;

    // Check if the current placement satisfies the visibility constraints
    if (!check_visibility(grid, views))
    {
        grid[row][col] = 0;  // Remove the number if visibility is not satisfied
        return (0);
    }

    // Restore the grid state and return valid placement
    grid[row][col] = 0;
    return (1);
}

// Count visible boxes from one direction in a row or column
int count_visible_boxes(int *line)
{
	int max_height = 0;
	int visible_count = 0;
	int i = 0;

	while (i < 4)
	{
		if (line[i] > max_height)
		{
			max_height = line[i];
			visible_count++;
		}
		i++;
	}
	return visible_count;
}

// Check if the current grid satisfies the visibility constraints
int	check_visibility(int **grid, int views[16])
{
	int row[4], col[4];
	int i, visible_count;

	// Check row visibility (left to right)
	i = 0;
	while (i < 4)
	{
		row[0] = grid[i][0];
		row[1] = grid[i][1];
		row[2] = grid[i][2];
		row[3] = grid[i][3];
		visible_count = count_visible_boxes(row);
		if (visible_count != views[i])  // Compare with left-to-right view
			return (0);
		i++;
	}

	// Check column visibility (top to bottom)
	i = 0;
	while (i < 4)
	{
		col[0] = grid[0][i];
		col[1] = grid[1][i];
		col[2] = grid[2][i];
		col[3] = grid[3][i];
		visible_count = count_visible_boxes(col);
		if (visible_count != views[8 + i])  // Compare with top-to-bottom view
			return (0);
		i++;
	}

	return (1);  // Visibility constraints satisfied
}

