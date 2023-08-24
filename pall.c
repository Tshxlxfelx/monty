#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * pall - Prints all the values on the stack, starting from the top.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number in the Monty byte code file.
 */
void pall(stack_t **stack, unsigned int line_number)
{
    (void)line_number; 

    stack_t *current = *stack;

    while (current)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

