# Push_swap

A sorting algorithm project from the 42 school curriculum.

## Description

`push_swap` is a project that challenges you to sort a stack of integers using a limited set of operations. You are given two stacks, `a` and `b`, and you must sort stack `a` in ascending order with the smallest number of moves.

## The Rules

- You start with a random list of integers in stack `a`.
- Stack `b` is initially empty.
- The goal is to sort stack `a` in ascending order.
- You can only use the following operations:

### Operations

-   `sa` (swap a): Swap the first 2 elements at the top of stack `a`. Do nothing if there is only one or no elements.
-   `sb` (swap b): Swap the first 2 elements at the top of stack `b`. Do nothing if there is only one or no elements.
-   `ss` : `sa` and `sb` at the same time.
-   `pa` (push a): Take the first element at the top of `b` and put it at the top of `a`. Do nothing if `b` is empty.
-   `pb` (push b): Take the first element at the top of `a` and put it at the top of `b`. Do nothing if `a` is empty.
-   `ra` (rotate a): Shift up all elements of stack `a` by 1. The first element becomes the last one.
-   `rb` (rotate b): Shift up all elements of stack `b` by 1. The first element becomes the last one.
-   `rr` : `ra` and `rb` at the same time.
-   `rra` (reverse rotate a): Shift down all elements of stack `a` by 1. The last element becomes the first one.
-   `rrb` (reverse rotate b): Shift down all elements of stack `b` by 1. The last element becomes the first one.
-   `rrr` : `rra` and `rrb` at the same time.

## The Algorithm

The main challenge of `push_swap` is to find an efficient sorting algorithm that minimizes the number of operations. A common approach is a variation of radix sort:

1.  **Indexing:** First, the input numbers are indexed. This means replacing each number with its rank in the sorted list (e.g., the smallest number gets index 0, the next smallest gets index 1, and so on).

2.  **Radix Sort:** The sorting is done bit by bit, based on the binary representation of the indexes.
    - For each bit position (from least significant to most significant):
        - Iterate through all numbers in stack `a`.
        - If the current bit of a number's index is `0`, push it to stack `b` (`pb`).
        - If the current bit is `1`, rotate stack `a` (`ra`).
    - After checking all numbers in `a` for the current bit, push all numbers from stack `b` back to stack `a` (`pa`).

3.  **Optimization:** The algorithm can be optimized for small numbers of elements (e.g., 3 or 5) with specific sorting logic to reduce the number of moves.

## How to Use

1.  **Clone the repository:**
    ```bash
    git clone <repository_url>
    cd C-Systems-Projects/push_swap
    ```

2.  **Compile the project:**
    ```bash
    make
    ```

3.  **Run `push_swap`:**
    Provide a list of integers as arguments.
    ```bash
    ./push_swap 2 1 3 6 5 8
    ```
    The program will output the sequence of operations to sort the list.

## Bonus: The Checker

The project includes a `checker` program that verifies if the sequence of operations produced by `push_swap` correctly sorts the list.

-   **Run the checker:**
    ```bash
    ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
    ```
    If the stack is sorted, the checker will output `OK`. Otherwise, it will output `KO`.
The checker can also be run in interactive mode, where you can input the operations manually.
```bash
./checker 2 1 3
sa
^D
OK
```
