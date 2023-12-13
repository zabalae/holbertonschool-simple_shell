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

	errCheck = getline(&input, &size, stdin);
	if (errCheck == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			perror("getline");
			exit(EXIT_FAILURE);
		}
		exit(EXIT_SUCCESS);
	}
	len = strlen(input);
	if (len > 0 && input[len - 1] == '\n')
		input[len - 1] = '\0';
	return (input);
}
/**
* execute_comm - execute command base on usr input
* @cmd: recive the command
* @self: main argv[0] for the error msg
*
* Return: void, doesnt return
*/
void execute(char *cmd, char *self)
{
	char *cmd_args[3];
	pid_t pid;

	if (strcmp(cmd, "env") == 0)
	{
		print_enviroment();
		return;
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		cmd_args[0] = cmd;
		cmd_args[1] = NULL;

		execve(cmd, cmd_args, NULL);
		/*if command doesnt exist it will continue, therefore, print*/
		printf("%s: 1: %s: not found\n", self, cmd);
		fflush(stdout);
		return;
	}
	else
	{
		int stat;

		wait(&stat);
	}
}
/**
* print_enviroment - for env command/ enviroment
*
* Return: void, doesnt return
*/
void print_environment(void)
{
	char *env;

	env = getenv("USER");
	printf("USER=%s\n", env);
	env = getenv("LANGUAGE");
	printf("LANGUAGE=%s\n", env);
	env = getenv("SESSION");
	printf("SESSION=%s\n", env);
	env = getenv("COMPIZ_CONFIG_PROFILE");
	printf("COMPIZ_CONFIG_PROFILE=%s\n", env);
	env = getenv("SHLVL");
	printf("SHLVL=%s\n", env);
	env = getenv("HOME");
	printf("HOME=%s\n", env);
	env = getenv("C_IS");
	printf("C_IS=%s\n", env);
	env = getenv("DESKTOP_SESSION");
	printf("DESKTOP_SESSION=%s\n", env);
	env = getenv("LOGNAME");
	printf("LOGNAME=%s\n", env);
	env = getenv("TERM");
	printf("TERM=%s\n", env);
	env = getenv("PATH");
	printf("PATH=%s\n", env);
	env = getenv("DISPLAY");
	printf("DISPLAY=%s\n", env);
}
