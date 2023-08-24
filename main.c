#include "monty.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	size_t len = 0;
	ssize_t read;
	char *line = NULL;
	stack_t *head = NULL;
	GLOBAL_var.top = &head;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty <file>\n");
		exit(EXIT_FAILURE);
	}

	parse(argv[1], &head);
	exit(EXIT_SUCCESS);

}
