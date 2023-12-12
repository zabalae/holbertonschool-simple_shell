# Simple Shell

## Introduction

### What is Shell

A Unix shell is a command-line interface (CLI) program that interprets user commands and executes them by interacting with the operating system. It acts as an intermediary between the user and the system's kernel, allowing users to enter commands and receive responses.

Shells provide a way for users to interact with the computer by typing text commands, which the shell then translates into system calls. They offer features like scripting capabilities, file manipulation, process control, and more, making them a powerful tool for managing and controlling a Unix-based operating system. Examples of Unix shells include Bash (Bourne Again SHell), Zsh (Z Shell), and Csh (C Shell), each with its own set of functionalities and syntax.

## Project Information

### Requirements

#### General

- Allowed editors: vi, vim, emacs
- All the files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
- All the files should end with a new line
- A README.md file, at the root of the folder of the project is mandatory
- The code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
- The shell should not have any memory leaks
- No more than 5 functions per file
- All the header files should be include guarded
- Use system calls only when you need to 

#### Output

- Unless specified otherwise, the program must have the exact same output as sh (/bin/sh) as well as the exact same error output.
- The only difference is when you print an error, the name of the program must be equivalent to your argv[0] (See below)

Example of error with sh:
```
$ echo "qwerty" | /bin/sh
/bin/sh: 1: qwerty: not found
$ echo "qwerty" | /bin/../bin/sh
/bin/../bin/sh: 1: qwerty: not found
$
```
Same error with your program hsh:
```
$ echo "qwerty" | ./hsh
./hsh: 1: qwerty: not found
$ echo "qwerty" | ./././hsh
./././hsh: 1: qwerty: not found
$
```
#### List of allowed functions and system calls+
|                       |                     |                      |
| --------------------- | ------------------- | -------------------- |
| all functions from string.h | `access` | `chdir` |
| `close` | `closedir` | `execve` |
| `exit` | `_exit` | `fflush` |
| `fork` | `free` | `getcwd` |
| `getline` | `getpid` | `isatty` |
| `kill` | `malloc` | `open` |
| `opendir` | `perror` | `printf` |
| `fprintf` | `vfprintf` | `sprintf` |
| `putchar` | `read` | `readdir` |
| `signal` | `stat` | `lstat` |
| `fstat` | `strtok` | `wait` |
| `waitpid` | `wait3` | `wait4`|
| `write` |  |  |

## Tasks

#### 0. README, man, AUTHORS

- Write a README
- Write a man for your shell.
- You should have an AUTHORS file at the root of your repository, listing all individuals having contributed content to the repository.

#### 1. Betty would be proud

Write a beautiful code that passes the Betty checks

#### 2. Simple shell 0.1

Write a UNIX command line interpreter.

- Usage: simple_shell
  
Your Shell should:

- Display a prompt and wait for the user to type a command. A command line always ends with a new line.
- The prompt is displayed again each time a command has been executed.
- The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
- The command lines are made only of one word. No arguments will be passed to programs.
- If an executable cannot be found, print an error message and display the prompt again.
- Handle errors.
- You have to handle the “end of file” condition (Ctrl+D)
  
You don’t have to:

- use the PATH
- implement built-ins
- handle special characters : ", ', `, \, *, &, #
- be able to move the cursor
- handle commands with arguments

#### 3. Simple shell 0.2

Simple shell 0.1 +

- Handle command lines with arguments

#### 4. Simple shell 0.3

Simple shell 0.2 +

- Handle the PATH
- fork must not be called if the command doesn’t exist

#### 5. Simple shell 0.4

Simple shell 0.3 +

- Implement the exit built-in, that exits the shell
- Usage: exit
- You don’t have to handle any argument to the built-in exit

#### 6. Simple shell 1.0

Simple shell 0.4 +

- Implement the env built-in, that prints the current environment
