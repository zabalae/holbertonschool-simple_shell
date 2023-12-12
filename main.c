#include "main.h"

int main(int argc, char *argv[])
{
	char *input = NULL, *prevInput;
	(void)argc;

	do {/*infinit loop till exit is input*/
		prevInput = input;
		if (isatty(STDIN_FILENO))
			printf("$ ");
		input = getInput();/*use getline for input*/
		if (strcmp(input, "exit") != 0)
		{
			if (input != NULL)
				execute(input, argv[0]);
		}
		free(prevInput);/*deals with leaks*/
	} while (strcmp(input, "exit") != 0);
	free(input);/*getline allocate memory, needs free*/
	return (0);
}
