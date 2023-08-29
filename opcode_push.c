#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

void opcode_push(stack_t **stack, unsigned int line_number)
{
    /* Ensure there is an argument */
    if (!data || !data[1])
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    /* Convert the argument to an integer */
    int value = atoi(data[1]);

    /* Create a new stack node */
    stack_t *new_node = malloc(sizeof(stack_t));
    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->n = value;
    new_node->prev = NULL;

    /* Push the new node onto the stack */
    if (*stack)
    {
        new_node->next = *stack;
        (*stack)->prev = new_node;
    }
    *stack = new_node;
}

