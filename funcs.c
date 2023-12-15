#include "main.h"
/**
* getInput - recive the user input
*
* Return: the usr input
*/
char *getInput(void)
{
	char *input = NULL;
	size_t size = 0, len;
	ssize_t errCheck;

	errCheck = getline(&input, &size, stdin);
	if (errCheck == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			perror("getline");
			free(input);
			return (NULL);
		}
		free(input);
		exit(EXIT_SUCCESS);
	}
	len = strlen(input);
	if (len > 0 && input[len - 1] == '\n')
		input[len - 1] = '\0';
	return (input);
}
/**
* execute - execute command base on usr input
* @cmd: recive the command
* @self: main argv[0] for the error msg
* @envp: recive enviroment variables
*
* Return: void, doesnt return
*/
void execute(char *cmd, char *envp[])
{
	int i = 0;
	char *cmd_args[ARGS_SIZE];
	pid_t pid;

	if (strcmp(cmd, "env") == 0)
	{
		print_enviroment(envp);
		return;
	}
	else
	{
		cmd_args[i] = strtok(cmd, " ");
		while (cmd_args[i] != NULL)
		{
			i++;
			if (i >= ARGS_SIZE - 1)
			{
				printf("Command Fail, Too many arguments. Max 258.\n");
				return;
			}
			cmd_args[i] = strtok(NULL, " ");
		}

		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		if (pid == 0)/*child process*/
		{
			if (cmd_args[0] != NULL)
			{
				execvp(cmd_args[0], cmd_args);
				perror("execvp");
				_exit(EXIT_FAILURE);
			}
			_exit(EXIT_FAILURE);
		}
		else
			wait(NULL);
	}
}
/**
* print_enviroment - for env command enviroment
* @envp: recive enviroment variables
*
* Return: void, doesnt return
*/
void print_enviroment(char *envp[])
{
	int i;

	for (i = 0; envp[i] != NULL; i++)
	{
		printf("%s\n", envp[i]);
	}
}
