<h1 align=center>💻 Minitalk</h1>
<p align="center">
  <img src="img/minitalk.png?raw=true" alt="Minitalk Project Image"/>
</p>

## About
>The purpose of this project is to code a small data exchange program
>using UNIX signals.

[Subject Minitalk Project 42](Minitalk.pdf)

The Minitalk project allows two terminals to communicate with each other through message passing.

## Features
- **Description**: The client sends messages to the server, and the server prints them to standard output.
- **Feature**: Communication is established using UNIX signals (`SIGUSR1` and `SIGUSR2`), enabling message transfer between two separate programs.
- **How to Use**: Start the server program, then run the client program with the server’s process ID (PID) and the message to send.

## Setup

**Clone the Repository**:

```bash
git clone https://github.com/J0hann3/minitalk.git
cd minitalk
make
```

## Usage

1. Start the server by running:
```bash
./server
```
2. Start a client and send a message to the server:
```bash
./client <server_pid> <message>
```
  - Replace <server_pid> with the PID of the server process.
  - Replace <message> with the string you want to send.
3. The server will print the received message to the console. Multiple clients can connect and send messages to the server simultaneously.

## New Notion

### UNIX Signals
- `sigaction`: Used to catch signals and handle them according to your specifications.
- `kill`: Sends a signal to a specified PID.
- `SIGUSR1` and `SIGUSR2`: These signals represent binary values (0 and 1) to transmit messages.
- Binary Message Encoding: Messages are decomposed into binary form and then sent as individual signals.

### Bitwise operators

- `&` => AND
- `|` => OR
- `^` => XOR
- `<<` => left shift
- `>>` => right shift
- `~` => NOT
