#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>

/* Define the stack data structure */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/* Define the instruction data structure */
typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Function prototypes for opcode functions */
void opcode_push(stack_t **stack, unsigned int line_number);
void opcode_pall(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */

