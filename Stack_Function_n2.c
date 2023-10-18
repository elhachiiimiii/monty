#include "monty.h"

/**
 * nop - Does nothing.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void nop(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
}

/**
 * swap_nodes - Swaps the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void swap_nodes(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
        more_err(8, line_number, "swap");

    temp = (*stack)->next;
    (*stack)->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = *stack;

    temp->next = *stack;
    (*stack)->prev = temp;
    temp->prev = NULL;
    *stack = temp;
}

/**
 * add_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void add_nodes(stack_t **stack, unsigned int line_number)
{
    int sum;

    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
        more_err(8, line_number, "add");

    (*stack) = (*stack)->next;
    sum = (*stack)->n + (*stack)->prev->n;
    (*stack)->n = sum;
    free((*stack)->prev);
    (*stack)->prev = NULL;
}

/**
 * sub_nodes - Subtracts the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void sub_nodes(stack_t **stack, unsigned int line_number)
{
    int difference;

    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
        more_err(8, line_number, "sub");

    (*stack) = (*stack)->next;
    difference = (*stack)->n - (*stack)->prev->n;
    (*stack)->n = difference;
    free((*stack)->prev);
    (*stack)->prev = NULL;
}

/**
 * div_nodes - Divides the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void div_nodes(stack_t **stack, unsigned int line_number)
{
    int result;

    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
        more_err(8, line_number, "div");

    if ((*stack)->n == 0)
        more_err(9, line_number);

    (*stack) = (*stack)->next;
    result = (*stack)->n / (*stack)->prev->n;
    (*stack)->n = result;
    free((*stack)->prev);
    (*stack)->prev = NULL;
}
