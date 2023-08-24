#include "monty.h"

/**
 * f_push - Pushes an integer onto the stack or queue.
 * @head: Pointer to the head of the stack/queue.
 * @counter: Line number in the script.
 */
void f_push(stack_t **head, unsigned int counter)
{
    if (!bus.arg)
    {
        fprintf(stderr, "L%d: usage: push integer\n", counter);
        exit(EXIT_FAILURE);
    }

    char *arg = bus.arg;
    int value = 0;
    int is_negative = 0;
    unsigned int i = 0;

    if (arg[i] == '-')
    {
        is_negative = 1;
        i++;
    }

    while (arg[i] != '\0')
    {
        if (arg[i] < '0' || arg[i] > '9')
        {
            fprintf(stderr, "L%d: usage: push integer\n", counter);
            exit(EXIT_FAILURE);
        }
        value = value * 10 + (arg[i] - '0');
        i++;
    }

    if (is_negative)
    {
        value = -value;
    }

    if (bus.lifi == 0)
    {
        addnode(head, value);
    }
    else
    {
        addqueue(head, value); 
    }
}

