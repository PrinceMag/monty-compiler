#include "monty.h"

/**
 * parse - function that parses and reads the bytecode files
 * @fileName: file to be opened
 * @UNUSED: unused pointer to head
 *
 * Return: void
 */
void parse(char *fileName, stack_t **head UNUSED)
{
	FILE *src_code;
	ssize_t read;
	char *line = NULL, *op;
	size_t len = 0;
	unsigned int lineNumber = 1;

	src_code = fopen(fileName, "r");
	if (src_code == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", fileName);
		exit(EXIT_FAILURE);
	}

	GLOBAL_var.src_code = src_code;

	atexit(free_dataStructure);

	while ((read = getline(&line, &len, src_code)) != -1) 
	{
		GLOBAL_var.line = line;
		op = strtok(line, DELIMS);
		if (op != NULL)
			exe_operation(op, head, lineNumber);
		lineNumber++;
	}

    fclose(src_code);
    if (line)
        free(line);
}
