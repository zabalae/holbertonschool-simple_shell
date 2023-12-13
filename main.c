#include "main.h"

int main(int argc, char *argv[])
{
	char *input = NULL, *prevInput;
	(void)argc;

	do {/*infinit loop till exit is input*/
		free(prevInput);
		prevInput = input;

		if (isatty(STDIN_FILENO))
			printf("$ ");
		input = getInput();/*use getline for input*/
		if (input != NULL && strcmp(input, "exit") != 0)
		{
			execute(input, argv[0]);
		}
	} while (input == NULL || (input != NULL && strcmp(input, "exit") != 0));

	free(input);/*getline allocate memory, needs free*/
	free(prevInput);

	return (0);
}
