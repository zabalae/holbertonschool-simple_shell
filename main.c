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
	char *input = NULL;
	char *default_path = "/usr/bin:/bin";
	(void)argc;

	do {/*infinit loop till exit is input*/
		if (isatty(STDIN_FILENO))
			printf("$ ");
		input = getInput();/*use getline for input*/
		if (input != NULL)
		{
			if (strcmp(input, "exit") != 0)
			{
				if (strlen(getenv("PATH")) == 0)
				{
					setenv("PATH", default_path, 1);
				}
				execute(input, argv[0], envp);
				free(input);
			}
			else
			{
				free(input);
				break;
			}
		}
		else
			printf("Fail, NULL input");
	} while (1);
	/*free(input);*getline allocate memory, needs free*/
	return (0);
}
