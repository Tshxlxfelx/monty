#include "monty.h"
#include <stdlib.h> 

/**
 * push - Pushes an element onto the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number in the Monty byte code file.
 */
void push(stack_t **stack, unsigned int line_number)
{
    char *endptr;
    int n;

    if (!global_arg || !is_numeric(global_arg))
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    n = strtol(global_arg, &endptr, 10); // Convert argument to integer

    if (*endptr != '\0')
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    stack_t *new_node = malloc(sizeof(stack_t));
    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = n;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack)
        (*stack)->prev = new_node;

    *stack = new_node;
}

