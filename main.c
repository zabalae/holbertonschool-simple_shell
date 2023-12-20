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
	int flag = 1, executes = 0;
	char *cmd = NULL;
	(void)argc;/*set argc to void, not been use*/

	do {/*infinit loop till exit is input*/
		while (flag == 1)
		{
			if (isatty(STDIN_FILENO))/*check for interactive use*/
				printf("$ ");
			cmd = getInput();/*use getline for input*/
			flag = spaceChecker(cmd);/*here we check for spaces*/
			if (flag == 1)/*if flags is 1 means only spaces found*/
				free(cmd);
		}
		if (cmd != NULL)
		{
			if (strcasecmp(cmd, "exit") == 0)/*verify usr input*/
			{
				free(cmd);
				if (executes > 0)/*check if shell has run*/
					exit(2);
				break;
			}
			else
			{/*depending on the input calls desire function*/
				if (strcmp(cmd, "env") != 0)
					execute(cmd, argv[0], envp);
				else
					print_enviroment(envp);
				free(cmd);
			}
		}
		executes++;/*adds every time shell run*/
		flag = 1;/*resets back to 1 to re-check for white spaces*/
	} while (1);
	return (0);
}
