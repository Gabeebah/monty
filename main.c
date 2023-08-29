#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    stack_t *stack = NULL; // Initialize the stack

    char *line = NULL;
    size_t len = 0;
    unsigned int line_number = 0;

    while (getline(&line, &len, file) != -1)
    {
        line_number++;

        // Tokenize the line to get the opcode and argument
        char *data[2];
        data[0] = strtok(line, " \t\n");
        if (!data[0] || data[0][0] == '#')
            continue; // Skip empty lines and comments
        data[1] = strtok(NULL, " \t\n");

        // Find the corresponding opcode function
        // and execute it with the stack and line number
        if (strcmp(data[0], "push") == 0)
        {
            opcode_push(&stack, line_number);
        }
        else if (strcmp(data[0], "pall") == 0)
        {
            opcode_pall(&stack, line_number);
        }
        else
        {
            fprintf(stderr, "L%u: unknown instruction %s\n", line_number, data[0]);
            fclose(file);
            free(line);
            return EXIT_FAILURE;
        }
    }

    // Clean up and close the file
    fclose(file);
    free(line);

    return EXIT_SUCCESS;
}

