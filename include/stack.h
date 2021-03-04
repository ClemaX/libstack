#ifndef STACK_H
# define STACK_H

#include <unistd.h> // using write, read, malloc, free, size_t

typedef char	t_stack_val;

typedef	struct	s_stack_elem
{
	t_stack_elem	*next;
	t_stack_val		value;
}				t_stack_elem;

typedef struct	s_stack
{
	t_stack_elem	*top;
	size_t			size;
}				t_stack;

/**
 * @brief Swap a
 *
 */
void	sa(t_stack *a, t_stack *b)
{
	t_stack_elem	*elem_a;
	t_stack_elem	*elem_b;

	if (a->size > 1)
	{
		elem_a = a->top;
		elem_b = a->top->next;

		elem_b->next = elem_a;
		elem_a->next = elem_b;
		a->top = elem_a;
	}
}

#endif
