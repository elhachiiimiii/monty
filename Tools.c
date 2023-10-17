#include "monty.h"

/**
 * openFile - Opens a file.
 * @fileName: The file name or path.
 * Return: void
 */
void openFile(char *fileName)
{
    FILE *fileDescriptor = fopen(fileName, "r");

    if (fileName == NULL || fileDescriptor == NULL)
        printErrorMessage(2, fileName);

    readFile(fileDescriptor);
    fclose(fileDescriptor);
}

/**
 * readFile - Reads a file.
 * @fd: Pointer to the file descriptor.
 * Return: void
 */
void readFile(FILE *fd)
{
    int lineNumber, format = 0;
    char *buffer = NULL;
    size_t len = 0;

    for (lineNumber = 1; getline(&buffer, &len, fd) != -1; lineNumber++)
    {
        format = parseLine(buffer, lineNumber, format);
    }
    free(buffer);
}

/**
 * parseLine - Separates each line into tokens to determine
 * which function to call.
 * @buffer: Line from the file.
 * @lineNumber: Line number.
 * @format: Storage format. If 0, nodes will be entered as a stack.
 *          If 1, nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */
int parseLine(char *buffer, int lineNumber, int format)
{
    char *opcode, *value;
    const char *delim = "\n ";

    if (buffer == NULL)
        printErrorMessage(4);

    opcode = strtok(buffer, delim);
    if (opcode == NULL)
        return (format);
    value = strtok(NULL, delim);

    if (strcmp(opcode, "stack") == 0)
        return (0);
    if (strcmp(opcode, "queue") == 0)
        return (1);

    findFunction(opcode, value, lineNumber, format);
    return (format);
}

/**
 * findFunction - Finds the appropriate function for the opcode.
 * @opcode: Opcode.
 * @value: Argument of opcode.
 * @format: Storage format. If 0, nodes will be entered as a stack.
 *          If 1, nodes will be entered as a queue.
 * @lineNumber: Line number.
 * Return: void
 */
void findFunction(char *opcode, char *value, int lineNumber, int format)
{
    int i;
    int flag;

    instruction_t funcList[] = {
        {"push", addNodeToStack},
        {"pall", printStack},
        {"pint", printTop},
        {"pop", popTop},
        {"nop", nop},
        {"swap", swapNodes},
        {"add", addNodes},
        {"sub", subNodes},
        {"div", divNodes},
        {"mul", mulNodes},
        {"mod", modNodes},
        {"pchar", printChar},
        {"pstr", printStr},
        {"rotl", rotateLeft},
        {"rotr", rotateRight},
        {NULL, NULL}
    };

    if (opcode[0] == '#')
        return;

    for (flag = 1, i = 0; funcList[i].opcode != NULL; i++)
    {
        if (strcmp(opcode, funcList[i].opcode) == 0)
        {
            callFunction(funcList[i].f, opcode, value, lineNumber, format);
            flag = 0;
        }
    }
    if (flag == 1)
        printErrorMessage(3, lineNumber, opcode);
}

/**
 * callFunction - Calls the required function.
 * @func: Pointer to the function that is about to be called.
 * @op: String representing the opcode.
 * @val: String representing a numeric value.
 * @ln: Line number for the instruction.
 * @format: Format specifier. If 0, nodes will be entered as a stack.
 *          If 1, nodes will be entered as a queue.
 */
void callFunction(op_func func, char *op, char *val, int ln, int format)
{
    stack_t *node;
    int flag;
    int i;

    flag = 1;
    if (strcmp(op, "push") == 0)
    {
        if (val != NULL && val[0] == '-')
        {
            val = val + 1;
            flag = -1;
        }
        if (val == NULL)
            printErrorMessage(5, ln);
        for (i = 0; val[i] != '\0'; i++)
        {
            if (!isdigit(val[i]))
                printErrorMessage(5, ln);
        }
        node = createNode(atoi(val) * flag);
        if (format == 0)
            func(&node, ln);
        if (format == 1)
            addNodeToQueue(&node, ln);
    }
    else
        func(&head, ln);
}
