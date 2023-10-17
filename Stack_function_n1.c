#include "monty.h"

/**
 * addNodeToStack - Adds a node to the stack.
 * @newNode: Pointer to the new node.
 * @ln: Integer representing the line number of the opcode.
 */
void addNodeToStack(stack_t **newNode, __attribute__((unused)) unsigned int ln)
{
    stack_t *tmp;

    if (newNode == NULL || *newNode == NULL)
        exit(EXIT_FAILURE);

    if (head == NULL)
    {
        head = *newNode;
        return;
    }

    tmp = head;
    head = *newNode;
    head->next = tmp;
    tmp->prev = head;
}

/**
 * printStack - Prints all the elements in the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lineNumber: Line number of the opcode.
 */
void printStack(stack_t **stack, unsigned int lineNumber)
{
    stack_t *tmp;

    (void)lineNumber;

    if (stack == NULL)
        exit(EXIT_FAILURE);

    tmp = *stack;
    while (tmp != NULL)
    {
        printf("%d\n", tmp->n);
        tmp = tmp->next;
    }
}

/**
 * popTop - Removes the top node of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void popTop(stack_t **stack, unsigned int lineNumber)
{
    stack_t *tmp;

    if (stack == NULL || *stack == NULL)
        more_err(7, lineNumber);

    tmp = *stack;
    *stack = tmp->next;

    if (*stack != NULL)
        (*stack)->prev = NULL;

    free(tmp);
}

/**
 * printTop - Prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void printTop(stack_t **stack, unsigned int lineNumber)
{
    if (stack == NULL || *stack == NULL)
        more_err(6, lineNumber);

    printf("%d\n", (*stack)->n);
}
