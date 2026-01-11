# Philosophers

A simulation of the Dining Philosophers problem.

## Description

The Dining Philosophers problem is a classic synchronization problem in computer science. This project, part of the 42 school curriculum, aims to solve it using threads and mutexes.

The problem is as follows:
- Five philosophers are sitting at a round table.
- There is one fork between each pair of philosophers.
- A philosopher can be in one of three states: thinking, eating, or sleeping.
- To eat, a philosopher needs to pick up both the fork on their left and the fork on their right.
- A philosopher can only pick up one fork at a time.
- After eating, a philosopher puts down both forks and starts sleeping.
- After sleeping, they start thinking again.
- The simulation stops if a philosopher dies of starvation.

## Goal

The goal is to write a program that simulates the philosophers' lives without any of them dying. This requires careful management of the forks (shared resources) to avoid deadlocks and race conditions.

## How it Works

- The program takes the following arguments:
    - `number_of_philosophers`
    - `time_to_die` (in milliseconds)
    - `time_to_eat` (in milliseconds)
    - `time_to_sleep` (in milliseconds)
    - `[number_of_times_each_philosopher_must_eat]` (optional)

- Each philosopher is a thread.
- The forks are represented by mutexes.
- To eat, a philosopher must lock the mutexes for both their left and right forks.
- To avoid deadlocks, an even-numbered philosopher picks up the right fork first, while an odd-numbered philosopher picks up the left fork first.
- A separate thread monitors the philosophers' health. If a philosopher hasn't eaten within `time_to_die`, they die, and the simulation ends.
- If the optional argument is provided, the simulation stops once all philosophers have eaten the specified number of times.

## How to Use

1.  **Clone the repository:**
    ```bash
    git clone <repository_url>
    cd C-Systems-Projects/philosophers/philo
    ```

2.  **Compile the project:**
    ```bash
    make
    ```

3.  **Run the simulation:**
    ```bash
    ./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [meals_to_eat]
    ```
    Example:
    ```bash
    ./philo 5 800 200 200
    ```
This will simulate 5 philosophers, with a time to die of 800ms, a time to eat of 200ms, and a time to sleep of 200ms.
