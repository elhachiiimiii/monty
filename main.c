#include "monty.h"

stack_t *stack_head = NULL;

/**
 * main - Entry point of the program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    open_file(argv[1]);
    free_nodes();
    return (0);
}

/**
 * create_node - Creates a new stack node.
 * @value: Value to be stored in the node
 * Return: Pointer to the newly created node
 */
stack_t *create_node(int value)
{
    stack_t *node = malloc(sizeof(stack_t));
    if (node == NULL)
        err(4);

    node->next = NULL;
    node->prev = NULL;
    node->n = value;
    return (node);
}

/**
 * free_nodes - Frees all nodes in the stack.
 */
void free_nodes(void)
{
    stack_t *tmp;

    if (stack_head == NULL)
        return;

    while (stack_head != NULL)
    {
        tmp = stack_head;
        stack_head = stack_head->next;
        free(tmp);
    }
}

/**
 * add_to_queue - Adds a new node to the queue.
 * @new_node: Pointer to the new node to be added
 * @line_number: Line number of the opcode (unused)
 */
void add_to_queue(stack_t **new_node, __attribute__((unused)) unsigned int line_number)
{
    stack_t *temp;

    if (new_node == NULL || *new_node == NULL)
        exit(EXIT_FAILURE);

    if (stack_head == NULL)
    {
        stack_head = *new_node;
        return;
    }

    temp = stack_head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = *new_node;
    (*new_node)->prev = temp;
}
