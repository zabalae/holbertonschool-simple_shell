#include "main.h"

int main(int argc, char *argv[])
{
	char *input = NULL, *prevInput = NULL;
	(void)argc;

	do {/*infinit loop till exit is input*/
		if (isatty(STDIN_FILENO))
			printf("$ ");
		input = getInput();/*use getline for input*/
		if (strcmp(input, "exit") != 0)
		{
			execute(input, argv[0]);
		}
		free(prevInput);/*deals with leaks*/
		prevInput = input;
	} while (strcmp(input, "exit") != 0);
	free(input);/*getline allocate memory, needs free*/
	return (0);
}
