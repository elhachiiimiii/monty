#include "monty.h"

/**
 * multiplyNodes - Multiplies the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void multiplyNodes(stack_t **stack, unsigned int lineNumber)
{
    int product;

    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
        more_err(8, lineNumber, "mul");

    (*stack) = (*stack)->next;
    product = (*stack)->n * (*stack)->prev->n;
    (*stack)->n = product;
    free((*stack)->prev);
    (*stack)->prev = NULL;
}

/**
 * moduloNodes - Calculates the modulo of the second top element by the top element of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void moduloNodes(stack_t **stack, unsigned int lineNumber)
{
    int result;

    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
        more_err(8, lineNumber, "mod");

    if ((*stack)->n == 0)
        more_err(9, lineNumber);

    (*stack) = (*stack)->next;
    result = (*stack)->prev->n % (*stack)->n;
    (*stack)->n = result;
    free((*stack)->prev);
    (*stack)->prev = NULL;
}
