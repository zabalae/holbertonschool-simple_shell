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

- Usage: `simple_shell`
  
Your Shell should:

- Display a prompt and wait for the user to type a command. A command line always ends with a new line.
- The prompt is displayed again each time a command has been executed.
- The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
- The command lines are made only of one word. No arguments will be passed to programs.
- If an executable cannot be found, print an error message and display the prompt again.
- Handle errors.
- You have to handle the “end of file” condition (`Ctrl+D`)
  
You don’t have to:

- use the `PATH`
- implement built-ins
- handle special characters:  ``` ", ', `, \, *,&, #```
- be able to move the cursor
- handle commands with arguments

#### 3. Simple shell 0.2

Simple shell 0.1 +

- Handle command lines with arguments

#### 4. Simple shell 0.3

Simple shell 0.2 +

- Handle the `PATH`
- `fork` must not be called if the command doesn’t exist

#### 5. Simple shell 0.4

Simple shell 0.3 +

- Implement the `exit` built-in, that exits the shell
- Usage: `exit`
- You don’t have to handle any argument to the built-in `exit`

#### 6. Simple shell 1.0

Simple shell 0.4 +

- Implement the `env` built-in, that prints the current environment

#### 7. What happens when you type `ls -l *.c` in the shell

Write a blog post describing step by step what happens when you type `ls -l *.c` and hit Enter in a shell. Try to explain every step you know of, going in as much details as you can, give examples and draw diagrams when needed. You should merge your previous knowledge of the shell with the specifics of how it works under the hoods (including syscalls).

- Have at least one picture, at the top of the blog post
- Publish your blog post on Medium or LinkedIn
- Share your blog post at least on LinkedIn
- Only one blog post by team
- The blog post must be done and published before the first deadline (it will be part of the manual review)
- Please, remember that these blogs must be written in English to further your technical ability in a variety of settings

#### 8. Test suite

Contribute to a test suite for your shell.

This is a task shared by everyone in the class.

- Every team (who contributed) will get the same score for this task (The repository owner will not get more points)
- You have to be pro-active and agree on one and unique repository to use for the test suite
- Please provide the link to the repository you contributed to
- Your contribution must be relevant (Correcting typos is nice and always appreciated on the open source sphere, but we won’t consider this a contribution at this point, unless it fixes a bug)
Guidelines for your test suite repository:

- The test suite should cover every tasks from `0.` to `20`.
- The test suite should cover every regular cases (many different examples) and possible edge cases
- The entire class should work on the same test suite. Use only one repository (don’t forget the `README.md` file)
- Start adding tests ASAP and not just before the deadline in order to help everyone from day 0
- You should have an `AUTHORS` file, listing all individuals having contributed content to the repository.

#### 9. Simple shell 0.1.1

Simple shell 0.1 +

- Write your own `getline` function
- Use a buffer to read many chars at once and call the least possible the read system call
- You will need to use `static` variables
- You are not allowed to use `getline`
You don’t have to:

- be able to move the cursor

#### 10. Simple shell 0.2.1

Simple shell 0.2 +

- You are not allowed to use `strtok`

#### 11. Simple shell 0.4.1

Simple shell 0.4 +

- handle arguments for the built-in `exit`
- Usage: `exit status`, where `status` is an integer used to exit the shell

#### 12. Simple shell 0.4.2

Simple shell 0.4 +

- Handle `Ctrl+C`: your shell should not quit when the user inputs `^C`

#### 13. setenv, unsetenv

Simple shell 1.0 +

Implement the `setenv` and `unsetenv` builtin commands

`setenv`
- Initialize a new environment variable, or modify an existing one
- Command syntax: `setenv VARIABLE VALUE`
- Should print something on stderr on failure
`unsetenv`
- Remove an environment variable
- Command syntax: `unsetenv VARIABLE`
- Should print something on stderr on failure

#### 14. cd

Simple shell 1.0 +

Implement the builtin command `cd`:

- Changes the current directory of the process.
- Command syntax: `cd [DIRECTORY]`
- If no argument is given to `cd` the command must be interpreted like `cd $HOME`
- You have to handle the command `cd -`
- You have to update the environment variable `PWD` when you change directory

#### 15. ;

Simple shell 1.0 +

- Handle the commands separator `;`

#### 16. && and ||

Simple shell 1.0 +

- Handle the `&&` and `||` shell logical operators

#### 17. alias

Simple shell 1.0 +

- Implement the `alias` builtin command
- Usage: `alias [name[='value'] ...]`
  - `alias`: Prints a list of all aliases, one per line, in the form `name='value'`
  - `alias name [name2 ...]`: Prints the aliases `name`, `name2`, etc 1 per line, in the form `name='value'`
  - `alias name='value' [...]`: Defines an alias for each `name` whose `value` is given. If `name` is already an alias, replaces its value with `value`
 
#### 18. Variables

Simple shell 1.0 +

- Handle variables replacement
- Handle the `$?` variable
- Handle the `$$` variable

#### 19. Comments

Simple shell 1.0 +

- Handle comments (`#`)

#### 20. help

Simple shell 1.0 +

- Implement the `help` built-in
- Usage: `help [BUILTIN]`

#### 21. history

Simple shell 1.0 +

- Implement the history built-in, without any argument
- The `history` built-in displays the history list, one command by line, preceded with line numbers (starting at `0`)
- On `exit`, write the entire history, without line numbers, to a file named `.simple_shell_history` in the directory `$HOME`
- When the shell starts, read the file `.simple_shell_history` in the directory `$HOME` if it exists, and set the first line number to the total number of lines in the file modulo `4096`

#### 22. File as input

Simple shell 1.0 +

- Usage: `simple_shell [filename]`
- Your shell can take a file as a command line argument
- The file contains all the commands that your shell should run before exiting
- The file should contain one command per line
- In this mode, the shell should not print a prompt and should not read from `stdin`

## Authors &copy;

- Elizabeth Mendez
- Ladie Juarbe
- William Herrera
