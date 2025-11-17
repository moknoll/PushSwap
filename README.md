# Push_swap

Push_swap is a sorting algorithm project from 42 School. The goal is to sort a stack of integers using a limited set of operations.

## Operations

The allowed operations are:
- `sa` (swap a): swap the first two elements at the top of stack a.
- `sb` (swap b): swap the first two elements at the top of stack b.
- `ss` : `sa` and `sb` at the same time.
- `pa` (push a): take the first element at the top of b and put it at the top of a.
- `pb` (push b): take the first element at the top of a and put it at the top of b.
- `ra` (rotate a): shift up all elements of stack a by 1. The first element becomes the last one.
- `rb` (rotate b): shift up all elements of stack b by 1. The first element becomes the last one.
- `rr` : `ra` and `rb` at the same time.
- `rra` (reverse rotate a): shift down all elements of stack a by 1. The last element becomes the first one.
- `rrb` (reverse rotate b): shift down all elements of stack b by 1. The last element becomes the first one.
- `rrr` : `rra` and `rrb` at the same time.

## Compilation

To compile the project, navigate to the `src` directory and run the following command:

```bash
make
```

This will create an executable named `push_swap`.

## Usage

To use the `push_swap` program, pass a list of integers as arguments:

```bash
./push_swap 2 1 3 6 5 8
```

The program will output the sequence of operations to sort the given list.

## Algorithm

The sorting algorithm implemented in this project is based on the "Turk Algorithm". It involves these main steps:

1.  **Push to B**: Push elements from stack A to stack B, leaving a few elements in A.
2.  **Set Targets**: For each element in stack B, find its target position in stack A.
3.  **Calculate Cost**: Calculate the cost of moving each element from B to A. The cost is the number of operations required.
4.  **Find Cheapest**: Find the element with the cheapest cost to move.
5.  **Move to A**: Move the cheapest element from stack B to its target position in stack A.
6.  **Repeat**: Repeat steps 2-5 until stack B is empty.
7.  **Final Sort**: Sort the remaining elements in stack A.

This algorithm aims to find the most efficient way to sort the stack by minimizing the number of operations.
