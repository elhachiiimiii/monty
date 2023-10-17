#include "monty.h"

/**
 * printErrorMessage - Prints appropriate error messages based on the error code.
 * @errorCode: The error codes and their meanings:
 * (1) => No file or more than one file provided to the program.
 * (2) => Unable to open or read the provided file.
 * (3) => Invalid instruction in the file.
 * (4) => Memory allocation failure.
 * (5) => Non-integer parameter passed to the "push" instruction.
 */
void printErrorMessage(int errorCode, ...) {
    va_list args;
    char *file;

    va_start(args, errorCode);
    switch (errorCode) {
        case 1:
            fprintf(stderr, "USAGE: monty file\n");
            break;
        case 2:
            file = va_arg(args, char *);
            fprintf(stderr, "Error: Can't open file %s\n", file);
            break;
        case 3:
            int lineNum = va_arg(args, int);
            char *opCode = va_arg(args, char *);
            fprintf(stderr, "L%d: unknown instruction %s\n", lineNum, opCode);
            break;
        case 4:
            fprintf(stderr, "Error: malloc failed\n");
            break;
        case 5:
            fprintf(stderr, "L%d: usage: push integer\n", va_arg(args, int));
            break;
        default:
            break;
    }
    freeNodes();
    exit(EXIT_FAILURE);
}

/**
 * handleMoreErrors - Handles additional errors.
 * @errorCode: The error codes and their meanings:
 * (6) => Empty stack for pint.
 * (7) => Empty stack for pop.
 * (8) => Stack too short for operation.
 * (9) => Division by zero.
 */
void handleMoreErrors(int errorCode, ...) {
    va_list args;
    char *opCode;
    int lineNum;

    va_start(args, errorCode);
    switch (errorCode) {
        case 6:
            fprintf(stderr, "L%d: can't pint, stack empty\n", va_arg(args, int));
            break;
        case 7:
            fprintf(stderr, "L%d: can't pop an empty stack\n", va_arg(args, int));
            break;
        case 8:
            lineNum = va_arg(args, unsigned int);
            opCode = va_arg(args, char *);
            fprintf(stderr, "L%d: can't %s, stack too short\n", lineNum, opCode);
            break;
        case 9:
            fprintf(stderr, "L%d: division by zero\n", va_arg(args, unsigned int));
            break;
        default:
            break;
    }
    freeNodes();
    exit(EXIT_FAILURE);
}

/**
 * handleStringErrors - Handles string-related errors.
 * @errorCode: The error codes and their meanings:
 * (10) => The value inside a node is outside ASCII bounds.
 * (11) => The stack is empty.
 */
void handleStringErrors(int errorCode, ...) {
    va_list args;
    int lineNum;

    va_start(args, errorCode);
    lineNum = va_arg(args, int);
    switch (errorCode) {
        case 10:
            fprintf(stderr, "L%d: can't pchar, value out of range\n", lineNum);
            break;
        case 11:
            fprintf(stderr, "L%d: can't pchar, stack empty\n", lineNum);
            break;
        default:
            break;
    }
    freeNodes();
    exit(EXIT_FAILURE);
}
