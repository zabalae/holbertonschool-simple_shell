#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ARGS 64

/**
 * Executes the given command with arguments in a child process.
 * @param args An array of strings representing the command and its arguments
 */
void execute_command(char *args[])
{
  pid_t pid = fork();

  if (pid == -1)
    {
      perror("fork");
    }
  else if (pid == 0)
    {
      if (execvp(args[0], args) == -1)
	{
	  perror("execvp");
	  exit (EXIT_FAILURE);
	}
    }
  else
    {
      int status;
      waitpid(pid, &status, 0);

      if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
	{
	  fprintf(stderr, "Error: Command not found\n");
	}
    }
}

/**
 * Prints the current environment variables.
 */
void print_environment()
{
  extern char **environ;
  for (char **env = environ; *env != NULL; env++)
    {
      printf("%s\n", *env);
    }
}

/**
 * Main function for the simple shell.
 * Reads user input, tokenizes it, and executes commands.
 */
int main(void)
{
  char input[MAX_INPUT_SIZE];
  char *args[MAX_ARGS];

  while (1)
    {
      printf("simple_shell> ");
      fflush(stdout);

      if (fgets(input, MAX_INPUT_SIZE, stdin) == NULL)
	{
	  if (feof(stdin))
	    {
	      printf("\nExiting shell...\n");
	      break;
	    }
	  else
	    {
	      perror("fgets");
	      exit(EXIT_FAILURE);
	    }
	}
      input[strcspn(input, "\n")] = '\0';

      char *token = strtok(input, " ");
      int i = 0;

      while (token != NULL && i < MAX_ARGS - 1)
	{
	  args[i++] = token;
	  token = strtok(NULL, " ");
	}

      args[i] = NULL;

      if (args[0] != NULL)
	{
	  if (strcmp(args[0], "exit") == 0)
	    {
	      printf("Exiting shell...\n");
	      exit(EXIT_SUCCESS);
	    }
	  else if (strcmp(args[0], "env") == 0)
	    {
	      print_environment();
	    }
	  else
	    {
	      if (access(args[0], X_OK) == 0)
		{
		  execute_command(args);
		}
	      else
		{
		  fprintf(stderr, "Error: Command not found\n");
		}
	    }
	}
    }
  return (0);
}
