#include "monty.h"

/* Global variable for argument */
char *global_arg = NULL;

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

    stack_t *stack = NULL;
    unsigned int line_number = 0;
    char *line = NULL;
    size_t len = 0;

    while (getline(&line, &len, file) != -1)
    {
        ++line_number;

        char *opcode = strtok(line, " \t\n");
        if (opcode)
            global_arg = strtok(NULL, " \t\n");

        instruction_t *instruction = instructions;
        while (instruction->opcode)
        {
            if (strcmp(instruction->opcode, opcode) == 0)
            {
                instruction->f(&stack, line_number);
                break;
            }
            ++instruction;
        }
        global_arg = NULL;
    }

    free(line);
    fclose(file);

    return EXIT_SUCCESS;
}

