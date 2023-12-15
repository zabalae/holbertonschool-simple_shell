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
	char *input = NULL;
	(void)argc;

	do {/*infinit loop till exit is input*/
		while (flag == 1)
		{
			if (isatty(STDIN_FILENO))
				printf("$ ");
			input = getInput();/*use getline for input*/
			flag = spaceChecker(input);
			if (flag == 1)
				free(input);
		}
		if (input != NULL)
		{
			if (strcasecmp(input, "exit") != 0)
			{
				if (strcmp(input, "env") != 0)
					execute(input, argv[0], envp);
				else
					print_enviroment(envp);
				free(input);
			}
			else if (strlen(input) == 4)
			{
				free(input);
				break;
			}
			else
			{
				free(input);
				exit(2);
			}
		}
		else
			printf("Fail, NULL input");
		flag = 1;
	} while (1);
	return (0);
}
