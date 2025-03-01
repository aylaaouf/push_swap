# Push Swap

## Description
**Push Swap** is a project that consists of sorting a stack of integers with a limited set of operations using two stacks (`a` and `b`). The goal is to achieve an efficient sorting algorithm with the least number of operations.

## Objectives
- Develop an efficient sorting algorithm for a stack of numbers.
- Implement the sorting using only a predefined set of operations.
- Optimize the number of operations to achieve the best possible performance.
- Handle edge cases such as duplicates, negative numbers, and large inputs.

## Allowed Operations
### Stack Manipulation
- **`sa`** (swap a): Swap the first two elements of stack `a`.
- **`sb`** (swap b): Swap the first two elements of stack `b`.
- **`ss`** (sa + sb): Swap both stacks simultaneously.

### Pushing Elements
- **`pa`** (push a): Move the top element of `b` to `a`.
- **`pb`** (push b): Move the top element of `a` to `b`.

### Rotating Stacks
- **`ra`** (rotate a): Shift all elements of `a` up by one.
- **`rb`** (rotate b): Shift all elements of `b` up by one.
- **`rr`** (ra + rb): Rotate both stacks simultaneously.

### Reverse Rotating
- **`rra`** (reverse rotate a): Shift all elements of `a` down by one.
- **`rrb`** (reverse rotate b): Shift all elements of `b` down by one.
- **`rrr`** (rra + rrb): Reverse rotate both stacks simultaneously.

## Compilation
To compile the project, run:
```sh
make
```
This will generate the `push_swap` executable.

## Usage
To run the program, use:
```sh
./push_swap <list_of_numbers>
```
### Example:
```sh
./push_swap 3 2 5 1 4
```
This will output a sequence of operations to sort the given list.

## Error Handling
- The program must handle invalid inputs (non-numeric characters, duplicates, etc.).
- If an error occurs, the program should print `Error` and exit with a status of `1`.

## Algorithm
- **Small sets (≤5 numbers):** Implement a simple sorting strategy using minimal operations.
- **Larger sets:** Use an optimized algorithm like:
  - **Chunk sorting**: Dividing the stack into smaller chunks.
  - **QuickSort-based approach**: Sorting based on pivot selection.
  - **Radix Sort**: Efficient sorting for large numbers.

## Bonus (Optional)
The bonus part includes:
- Implementing a checker program (`checker`) to verify if a sequence of operations correctly sorts a stack.
- Handling more complex sorting scenarios efficiently.

## Authors
- **[aylaaouf](mailto:aylaaouf@student.1337.ma)**
