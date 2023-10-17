#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

void open_file(char *file_name);
int parse_line(char *buffer, int line_number, int format);
void read_file(FILE *);
int count_chars(FILE *);
void find_func(char *, char *, int, int);

stack_t *create_node(int n);
void free_nodes(void);
void print_stack(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
void add_to_queue(stack_t **stack, unsigned int line_number);
void call_fun(op_func func, char *op, char *val, int ln, int format);
void print_top(stack_t **stack, unsigned int line_number);
void pop_top(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void swap_nodes(stack_t **stack, unsigned int line_number);
void add_nodes(stack_t **stack, unsigned int line_number);
void sub_nodes(stack_t **stack, unsigned int line_number);
void div_nodes(stack_t **stack, unsigned int line_number);
void mul_nodes(stack_t **stack, unsigned int line_number);
void mod_nodes(stack_t **stack, unsigned int line_number);
void print_char(stack_t **stack, unsigned int line_number);
void print_string(stack_t **stack, unsigned int line_number);
void rotate_left(stack_t **stack, unsigned int line_number);
void rotate_right(stack_t **stack, unsigned int line_number);

void handle_error(int error_code, ...);
void handle_more_errors(int error_code, ...);
void handle_string_errors(int error_code, ...);

#endif
