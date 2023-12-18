#include "main.h"
/**
* getInput - recive the user input
*
* Return: the usr input
*/
char *getInput(void)
{/*EOF = END OF FLE*/
	char *input = NULL;
	size_t size = 0, len;
	ssize_t errCheck;

	errCheck = getline(&input, &size, stdin);
	if (errCheck == -1)/*getline return -1 when fail*/
	{
		if (isatty(STDIN_FILENO))/*checks for interative use of shell*/
		{
			perror("getline");
			free(input);
			return (NULL);
		}
		free(input);/*if shell was run non-interactive*/
		exit(EXIT_SUCCESS);/*getline would also return -1, for EOF*/
	}
	len = strlen(input);/*take the lenght of input for future check*/
	if (len > 0 && input[len - 1] == '\n')/*based on len*/
		input[len - 1] = '\0';/*change last \n to \0*/
	return (input);/*remember shell input, end with \n but strings do not*/
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
	{ /*breaks input into arguments & save them on cmd_args array*/
		while (cmd_args[i] != NULL && i < ARGS_SIZE - 1)
		{
			i++;
			cmd_args[i] = strtok(NULL, " ");
		}
	} /*this call will return null if no valid command is found*/
	path_check = validCommand(cmd_args[0]);
	if (path_check != NULL)
	{ /*if a valid command is found we fork*/
		pid = fork();
		if (pid == -1)/*fork fail check*/
			exit(EXIT_FAILURE);
		if (pid == 0)/*child process*/
		{ /*everything that happens in the child happens here*/
			execve(path_check, cmd_args, envp);
			free(path_check);/*this will only run if exec fail*/
			exit(2);/*this will only run if exec fail*/
		}
		else/*main proccess*/
		{
			wait(NULL);/*wait for child to finish*/
			free(path_check);/*validCommand return a malloc value*/
			return;/*if we are here everything when well*/
		}
	}
	else
	{ /*No valid command was found so print error and do not fork*/
		fprintf(stderr, "%s: 1: %s: not found\n", self, cmd);
		free(cmd);
		exit(127);/*conventional error code for, no command found*/
	}
}
/**
* print_enviroment - for env command enviroment
* @envp: recive enviroment variables
*
* Return: void, doesnt return
*/
void print_enviroment(char *envp[])
{ /*prints all enviroment variables*/
	int i;

	for (i = 0; envp[i] != NULL; i++)
	{/*iterates envp for all enviroment variables*/
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
	{ /*here we check if the input is an absolute PATH*/
		if (access(cmd, X_OK) == 0)/*if PATH is correct we return it*/
			return (strdup(cmd));
		else/*if the PATH is invalid we return NULL*/
			return (NULL);
	}
	if (path != NULL)
	{ /*here we compare the input with all existing commands*/
		path_cpy = strdup(path);
		if (path_cpy == NULL)/*memory allocation check*/
			exit(EXIT_FAILURE);
		token = strtok(path_cpy, ":");/*path look like: usr/bin/ls:*/
		while (token != NULL)
		{
			cmd_path = malloc(PATH_MAX);
			if (cmd_path == NULL)/*memory allocation check*/
			{
				return (NULL);
			} /*concat the token and cmd together creating a PATH*/
			snprintf(cmd_path, PATH_MAX, "%s/%s", token, cmd);
			if (access(cmd_path, X_OK) == 0)
			{ /*access return 0 if absolute path exist, means*/
				free(path_cpy);
				return (cmd_path);/*valid command found*/
			}
			free(cmd_path);/*if command invalid free and retry*/
			token = strtok(NULL, ":");/*token move, next position*/
		} /*this will iterate all bin path, all valid commands*/
	}
	free(path_cpy);
	return (NULL);/*no command found, return NULL*/
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
		return (1);/*cmd is null OR empty = "" return 1*/
	for (i = 0; cmd[i] != '\0'; i++)
	{ /*iterate the whole string till a non-whitespace char is found*/
		if (cmd[i] != ' ')
			return (0);
	} /*if all it founds was white spaces return 1*/
	return (1);
}
