# Minitalk

A simple client-server communication program using signals.

## Description

`minitalk` is a project from the 42 school curriculum that demonstrates basic client-server communication using only UNIX signals. The client sends a string to the server, which then displays it. The communication is done bit by bit, using `SIGUSR1` and `SIGUSR2` signals.

## How it Works

1.  **Server:**
    - The server starts and prints its Process ID (PID).
    - It sets up signal handlers for `SIGUSR1` and `SIGUSR2`.
    - It waits for signals from a client.
    - When a signal is received, the handler reconstructs the bits of a character.
    - Once 8 bits are received, the character is formed and appended to a string.
    - When a null character is received, the server prints the complete string and resets for the next message.

2.  **Client:**
    - The client takes the server's PID and a string as command-line arguments.
    - It iterates through each character of the string.
    - For each character, it sends its 8 bits to the server using signals:
        - `SIGUSR1` for a `0` bit.
        - `SIGUSR2` for a `1` bit.
    - A small delay is added between signals to ensure they are not lost.

## How to Use

1.  **Clone the repository:**
    ```bash
    git clone <repository_url>
    cd C-Systems-Projects/minitalk
    ```

2.  **Compile the project:**
    Run the `Makefile` to compile both the client and server.
    ```bash
    make
    ```

3.  **Run the server:**
    ```bash
    ./server
    ```
    The server will print its PID.

4.  **Run the client:**
    In a new terminal, run the client with the server's PID and the message to send.
    ```bash
    ./client <server_pid> "Your message here"
    ```

## Bonus Features

The bonus part of the project includes:
-   **Bidirectional Communication:** The server sends an acknowledgment back to the client when the message is received.
-   **Unicode Support:** The client and server can handle Unicode characters.

To compile the bonus version, use:
```bash
make bonus
```
Then run `./client_bonus` and `./server_bonus`.
