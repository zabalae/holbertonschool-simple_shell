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

	while (1)
	{
		printf("$ ");
		input = getInput();

		if (*strcmp(input, "exit") == 0)
		{
			free(input);
			break;
		}

		execute(input, argv[0], envp);
		free(input);

	}

	free(input);/*getline allocate memory, needs free*/
	return (0);
}
