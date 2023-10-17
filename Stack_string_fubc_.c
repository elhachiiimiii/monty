#include "monty.h"

/**
 * printChar - Prints the ASCII value.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void printChar(stack_t **stack, unsigned int lineNumber)
{
    int asciiValue;

    if (stack == NULL || *stack == NULL)
        string_err(11, lineNumber);

    asciiValue = (*stack)->n;
    if (asciiValue < 0 || asciiValue > 127)
        string_err(10, lineNumber);

    printf("%c\n", asciiValue);
}

/**
 * printString - Prints a string.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @ln: Integer representing the line number of the opcode.
 */
void printString(stack_t **stack, __attribute__((unused))unsigned int ln)
{
    int asciiValue;
    stack_t *tmpNode;

    if (stack == NULL || *stack == NULL)
    {
        printf("\n");
        return;
    }

    tmpNode = *stack;
    while (tmpNode != NULL)
    {
        asciiValue = tmpNode->n;
        if (asciiValue <= 0 || asciiValue > 127)
            break;
        printf("%c", asciiValue);
        tmpNode = tmpNode->next;
    }
    printf("\n");
}

/**
 * rotateLeft - Rotates the first node of the stack to the bottom.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @ln: Integer representing the line number of the opcode.
 */
void rotateLeft(stack_t **stack, __attribute__((unused))unsigned int ln)
{
    stack_t *tmpNode;

    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
        return;

    tmpNode = *stack;
    while (tmpNode->next != NULL)
        tmpNode = tmpNode->next;

    tmpNode->next = *stack;
    (*stack)->prev = tmpNode;
    *stack = (*stack)->next;
    (*stack)->prev->next = NULL;
    (*stack)->prev = NULL;
}

/**
 * rotateRight - Rotates the last node of the stack to the top.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @ln: Integer representing the line number of the opcode.
 */
void rotateRight(stack_t **stack, __attribute__((unused))unsigned int ln)
{
    stack_t *tmpNode;

    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
        return;

    tmpNode = *stack;

    while (tmpNode->next != NULL)
        tmpNode = tmpNode->next;

    tmpNode->next = *stack;
    tmpNode->prev->next = NULL;
    tmpNode->prev = NULL;
    (*stack)->prev = tmpNode;
    (*stack) = tmpNode;
}
