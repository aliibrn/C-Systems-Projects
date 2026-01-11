# My Journey Through C & Systems Programming at 42 (1337)

This repository is a collection of my projects from the 42 school curriculum, documenting my journey and growth as a C programmer. It showcases a range of skills, from fundamental C programming to more complex topics like algorithms, concurrency, and basic graphics programming.

## The 42 Learning Model

The 42 network (1337 campus) is renowned for its unique project-based and peer-to-peer learning methodology. Instead of traditional classes, we learn by doing, tackling a series of challenging projects that force us to learn, adapt, and collaborate. This approach fosters a deep, practical understanding of programming concepts.

## Projects Overview

Here's a summary of the projects included in this repository and the key skills I developed with each one.

### [Libft](./libft/)

-   **Purpose**: To create a personal library of standard C functions from scratch.
-   **Key Learnings**: This is the foundational project for all C programming at 42. It taught me the fundamentals of memory manipulation (`ft_memcpy`, `ft_memset`, `ft_calloc`), string handling (`ft_strlen`, `ft_substr`, `ft_split`), and creating and using a static library.

### [Minitalk](./minitalk/)

-   **Purpose**: To build a client-server communication program using only UNIX signals.
-   **Key Learnings**: This project was a fascinating introduction to basic Inter-Process Communication (IPC). I learned about UNIX signals (`SIGUSR1`, `SIGUSR2`), process IDs (PIDs), and how to transmit data bit by bit between two separate processes.

### [Philosophers](./philosophers/)

-   **Purpose**: To solve the classic "Dining Philosophers" synchronization problem.
-   **Key Learnings**: A deep dive into the world of concurrency. This project required a solid understanding of threads, mutexes, and the critical importance of avoiding race conditions and deadlocks to keep multiple threads running smoothly without starving or crashing.

### [Push_swap](./push_swap/)

-   **Purpose**: To sort a stack of integers using a limited set of operations, with the goal of using the fewest possible moves.
-   **Key Learnings**: This was a pure algorithmic challenge. It pushed me to think about efficiency, data structures (stacks), and develop complex sorting algorithms (like a radix sort-based approach) to solve the problem optimally.

### [So_long](./so_long/)

-   **Purpose**: To create a simple 2D game using the `MiniLibX` graphics library provided by 42.
-   **Key Learnings**: My first foray into graphics programming. I learned how to render sprites, handle user input (keyboard events), manage game state, and parse map files. It was a fun and rewarding way to see code come to life visually.

## Upcoming Projects

This repository is a living document of my progress. I will be adding more projects soon, including:

-   **`get_next_line`**: A function that reads a file line by line, a very useful utility for parsing text-based files.
-   **`ft_printf`**: A complete reimplementation of the standard C `printf` function, which will be a major challenge in handling variadic arguments and complex formatting flags.

Thank you for visiting my repository!