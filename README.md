# Simple Shell

## Overview
**Simple Shell** is a basic command-line interpreter written in **C**, built to mimic the Unix shell. It handles user input and interactive and non-interactive modes, executes commands using system calls, and supports features such as piping and I/O redirection. This project demonstrates an understanding of operating systems concepts, system calls, and process management.

## Features
- Execute built-in and external commands.
- Handle input/output redirection.
- Support for command chaining with `&&`, `||`.
- Execute commands in the background with `&`.

## Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/Aalaa-Fahim/simple_shell.git
   ```
2. Compile the shell:
   ```bash
   gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
   ```
3. Run the shell:
   ```bash
   ./hsh
   ```

## Usage
- Run commands like `ls`, `pwd`, or `cat`.
- Redirect output: `ls > file.txt`.
- Use pipes: `ls | grep filename`.

## Built-in Commands
- **cd**: Change directory.
- **exit**: Exit the shell.
- **env**: Print the environment variables.

## Authors
- Aalaa Fahim
- Reham Saeed
