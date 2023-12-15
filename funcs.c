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
void execute(char *cmd, char *self, char *envp[])
{
	int i = 0;
	char *cmd_args[ARGS_SIZE], *path_check;
	pid_t pid;

	cmd_args[0] = strtok(cmd, " ");
	if (cmd_args[0] != NULL)
	{
		while (cmd_args[i] != NULL && i < ARGS_SIZE - 1)
		{
			i++;
			cmd_args[i] = strtok(NULL, " ");
		}
	}
	path_check = validCommand(cmd_args[0]);
	if (path_check != NULL)
	{
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		if (pid == 0)/*child process*/
		{
			execve(path_check, cmd_args, envp);
			free(path_check);
			_exit(EXIT_FAILURE);
		}
		else
		{
			wait(NULL);
			free(path_check);
		}
	}
	else
	{
		fprintf(stderr, "%s: 1: %s: not found\n", self, cmd);
		free(cmd);
		exit(EXIT_FAILURE);
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
/**
 * validCommand - search whole path comparing commands
 * @cmd: user input to compare
 *
 * Return: the path if its found or NULL if not
 */
char *validCommand(char *cmd)
{
	char *path = getenv("PATH"), *token, *cmd_path, *path_cpy = NULL;

	if (cmd == NULL)
		return (NULL);
	if (strchr(cmd, '/') != NULL)
	{
		if (access(cmd, X_OK) == 0)
			return (strdup(cmd));
		else
			return (NULL);
	}
	if (path != NULL)
	{
		path_cpy = strdup(path);
		if (path_cpy == NULL)
			exit(EXIT_FAILURE);
		token = strtok(path_cpy, ":");
		while (token != NULL)
		{
			cmd_path = malloc(PATH_MAX);
			if (cmd_path == NULL)
			{
				return (NULL);
			}
			snprintf(cmd_path, PATH_MAX, "%s/%s", token, cmd);
			if (access(cmd_path, X_OK) == 0)
			{
				free(path_cpy);
				return (cmd_path);
			}
			free(cmd_path);
			token = strtok(NULL, ":");
		}
	}
	free(path_cpy);
	return (NULL);
}
/**
 * spaceChecker - checks for white spaces
 * @cmd: usrInput to check for spaces
 *
 * Return: 1 if only whitespaces, 0 otherwise
 */
int spaceChecker(char *cmd)
{
	int i;

	if (cmd == NULL || cmd[0] == '\0')
		return (1);
	for (i = 0; cmd[i] != '\0'; i++)
	{
		if (cmd[i] != ' ')
			return (0);
	}
	return (1);
}
