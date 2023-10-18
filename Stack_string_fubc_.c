#include "monty.h"

/**
 * print_char - Prints the ASCII value as a character.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Integer representing the line number of of the opcode.
 */
void print_char(stack_t **stack, unsigned int line_number)
{
    int ascii_value;

    if (stack == NULL || *stack == NULL)
        string_err(11, line_number);

    ascii_value = (*stack)->n;
    if (ascii_value < 0 || ascii_value > 127)
        string_err(10, line_number);

    printf("%c\n", ascii_value);
}

/**
 * print_str - Prints a string.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Integer representing the line number of of the opcode.
 */
void print_str(stack_t **stack, __attribute__((unused))unsigned int ln)
{
    int ascii_value;
    stack_t *current_node;

    if (stack == NULL || *stack == NULL)
    {
        printf("\n");
        return;
    }

    current_node = *stack;
    while (current_node != NULL)
    {
        ascii_value = current_node->n;
        if (ascii_value <= 0 || ascii_value > 127)
            break;
        printf("%c", ascii_value);
        current_node = current_node->next;
    }
    printf("\n");
}

/**
 * rotl - Rotates the first node of the stack to the bottom.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Integer representing the line number of of the opcode.
 */
void rotl(stack_t **stack, __attribute__((unused))unsigned int ln)
{
    stack_t *new_bottom;

    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
        return;

    new_bottom = *stack;
    while (new_bottom->next != NULL)
        new_bottom = new_bottom->next;

    new_bottom->next = *stack;
    (*stack)->prev = new_bottom;
    *stack = (*stack)->next;
    (*stack)->prev->next = NULL;
    (*stack)->prev = NULL;
}

/**
 * rotr - Rotates the last node of the stack to the top.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Integer representing the line number of of the opcode.
 */
void rotr(stack_t **stack, __attribute__((unused))unsigned int ln)
{
    stack_t *last_node;

    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
        return;

    last_node = *stack;

    while (last_node->next != NULL)
        last_node = last_node->next;

    last_node->next = *stack;
    last_node->prev->next = NULL;
    last_node->prev = NULL;
    (*stack)->prev = last_node;
    (*stack) = last_node;
}
