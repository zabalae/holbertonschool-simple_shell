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
	char *input = NULL, *prevInput = NULL;
	(void)argc;

	do {/*infinit loop till exit is input*/
		if (isatty(STDIN_FILENO))
			printf("$ ");

		free(prevInput);
		prevInput = input;

		input = getInput();/*use getline for input*/
		if (input != NULL && strcmp(input, "exit") != 0)
		{
			execute(input, argv[0], envp);
			free(input);
		}

	} while (input != NULL && strcmp(input, "exit") != 0);

	free(prevInput);

	return (0);
}
