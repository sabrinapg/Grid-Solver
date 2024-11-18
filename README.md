C Programming Project: Grid Solver

# Project Overview

This project is a grid solver implemented in C, designed to take a grid of numbers and solve it based on specific constraints. The program takes in user input, processes it, and attempts to solve the grid using a backtracking algorithm while maintaining the validity of the solution. The constraints are checked for each row and column to ensure correctness, making it suitable for puzzles that require logical deduction, such as Sudoku or visibility puzzles.

# Features
- *Input Parsing*: Handles the input from the user and converts it into an internal representation.
- *Grid Creation*: Creates a grid to hold the values while solving the puzzle.
- *Backtracking Solver*: Implements backtracking to try different solutions, ensuring all constraints are satisfied.
- *Validation*: Checks for row and column constraints to verify if the solution is correct.
- *Output*: Outputs the grid once a valid solution is found.

# Project Structure
The project is divided into the following files:

- *grid.h*: Contains definitions and the data structure used for the grid.
- *input.c*: Handles input parsing, converting characters into integers, and passing them to the solver.
- *main.c*: The main entry point of the program that sets up the grid and initiates the solving process.
- *solver.c*: Contains the backtracking algorithm for solving the grid, checking constraints, and verifying the validity of placements.
- *utils.*: Utility functions used throughout the project to handle repetitive tasks.
- *validation.c*: Implements functions to validate the constraints of the grid.

# How to Compile
To compile the project, use the following command in the terminal:

```bash
gcc main.c input.c solver.c utils.c validation.c -o rush01
```

This will create an executable named `rush01`.

# How to Run
After compilation, you can run the program by executing the following command:

```bash
./rush01
```

You will be prompted to enter the grid constraints. The program will then attempt to solve the puzzle and output the result.

## Notes
- The program is written in C and does not follow the Norminette style guide for 42 Programming
- The project does not use pointers or dynamic memory allocation in `main.c`.
- The backtracking algorithm ensures that the solution satisfies the row and column constraints.
