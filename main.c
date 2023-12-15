#include "main.h"
/**
 * main - starts or main entry of program
 * @argc: recive argument count
 * @argv: recive argument vector
 * @envp: revice enviroment variables
 *
 * Return: 0 if function finish propertly
 */
int main(int argc, char *argv[], char *envp[])
{
	int flag = 1;
	char *cmd = NULL;
	(void)argc;

	do {/*infinit loop till exit is input*/
		while (flag == 1)
		{
			if (isatty(STDIN_FILENO))
				printf("$ ");
			cmd = getInput();/*use getline for input*/
			flag = spaceChecker(cmd);
			if (flag == 1)
				free(cmd);
		}
		if (cmd != NULL)
		{
			if (strstr(cmd, "exit") != NULL && strlen(cmd) > 4)
			{
				free(cmd);
				exit(2);
			}
			if (strcasecmp(cmd, "exit") == 0 && strlen(cmd) == 4)
			{
				free(cmd);
				break;
			}
			else
			{
				if (strcmp(cmd, "env") != 0)
					execute(cmd, argv[0], envp);
				else
					print_enviroment(envp);
				free(cmd);
			}
		}
		else
			printf("Fail, NULL input");
		flag = 1;
	} while (1);
	return (0);
}
