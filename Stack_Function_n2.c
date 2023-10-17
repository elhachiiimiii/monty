#include "monty.h"

/**
 * nop - Does nothing.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void nop(stack_t **stack, unsigned int lineNumber)
{
    (void)stack;
    (void)lineNumber;
}

/**
 * swapNodes - Swaps the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void swapNodes(stack_t **stack, unsigned int lineNumber)
{
    stack_t *tmp;

    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
        more_err(8, lineNumber, "swap");

    tmp = (*stack)->next;
    (*stack)->next = tmp->next;
    if (tmp->next != NULL)
        tmp->next->prev = *stack;

    tmp->next = *stack;
    (*stack)->prev = tmp;
    tmp->prev = NULL;
    *stack = tmp;
}

/**
 * addNodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void addNodes(stack_t **stack, unsigned int lineNumber)
{
    int sum;

    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
        more_err(8, lineNumber, "add");

    (*stack) = (*stack)->next;
    sum = (*stack)->n + (*stack)->prev->n;
    (*stack)->n = sum;
    free((*stack)->prev);
    (*stack)->prev = NULL;
}

/**
 * subNodes - Subtracts the top element from the second top element of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void subNodes(stack_t **stack, unsigned int lineNumber)
{
    int result;

    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
        more_err(8, lineNumber, "sub");

    (*stack) = (*stack)->next;
    result = (*stack)->prev->n - (*stack)->n;
    (*stack)->n = result;
    free((*stack)->prev);
    (*stack)->prev = NULL;
}

/**
 * divNodes - Divides the second top element by the top element of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void divNodes(stack_t **stack, unsigned int lineNumber)
{
    int result;

    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
        more_err(8, lineNumber, "div");

    if ((*stack)->n == 0)
        more_err(9, lineNumber);

    (*stack) = (*stack)->next;
    result = (*stack)->prev->n / (*stack)->n;
    (*stack)->n = result;
    free((*stack)->prev);
    (*stack)->prev = NULL;
}
