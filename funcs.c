#include "main.h"
/**
* getInput - recive the user input
*
* Return: the usr input
*/
char *getInput(void)
{
	char *input = NULL;
	size_t size = 32, len;
	ssize_t errCheck;

	input = malloc(size *sizeof(char));
	if (input == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	errCheck = getline(&input, &size, stdin);
	if (errCheck == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			perror("getline");
			free(input);
			exit(EXIT_FAILURE);
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
void execute(char *cmd, char *self, char *envp[])
{
	int i = 0;
	char **cmd_args = malloc(258 * sizeof(char *));
	pid_t pid;
	char *cmd_copy;

	if (cmd_args == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	cmd_copy = strdup(cmd);

	cmd_args[i] = strtok(cmd_copy, " ");

	while (cmd_args[i] != NULL)
	{
		i++;
		if (i >= 258)
		{
			printf("Command Fail, Too many arguments. Max 258.\n");
			free(cmd_copy);
			free(cmd_args);
			return;
		}
		cmd_args[i] = strtok(NULL, " ");
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		free(cmd_copy);
		free(cmd_args);
		exit(EXIT_FAILURE);
	}
	if (pid == 0)/*child process*/
	{
		execve(cmd_args[0], cmd_args, envp);
		printf("%s: 1: %s: not found\n", self, cmd);
		fflush(stdout);
		free(cmd);
		free(cmd_args);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
	free(cmd_copy);
	free(cmd_args);
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
