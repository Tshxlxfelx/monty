#include "monty.h"

/**
 * nop - Doesn't do anything.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number in the Monty byte code file.
 */
void nop(stack_t **stack, unsigned int line_number)
{
    (void)stack; // Unused parameter
    (void)line_number; // Unused parameter
    /* This opcode does nothing */
}

