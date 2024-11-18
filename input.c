#include "rush01.h"

// Validates if the input follows the expected pattern: 16 numbers (1-4) separated by spaces
int validate_input(char *input) {
    int i = 0;

    while (input[i]) {
        if ((i % 2 == 1) && input[i] != ' ')
            return (0);
        if ((i % 2 == 0) && (input[i] < '1' || input[i] > '4'))
            return (0);
        i++;
    }
    return (i == 31);  // 16 digits + 15 spaces
}

// Extracts values from the input and fills the constraints structure
int parse_input(char *input, t_constraints *constraints) {
    int values[16];
    int i = 0;
    int j = 0;

    // Extract the values from the input string
    while (input[j]) {
        if (input[j] >= '1' && input[j] <= '4') {
            values[i++] = input[j] - '0';
            j++;
        } else if (input[j] == ' ') {
            j++;
        } else {
            return (0);
        }
    }
    if (i != 16)
        return (0);

    // Populate the constraints structure
    for (i = 0; i < SIZE; i++) {
        constraints->col_up[i] = values[i];
        constraints->col_down[i] = values[i + SIZE];
        constraints->row_left[i] = values[i + SIZE * 2];
        constraints->row_right[i] = values[i + SIZE * 3];
    }
    return (1);
}
