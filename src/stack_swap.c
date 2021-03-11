#include <stack.h>

/**
 * @brief Swap a
 */
void	sa(t_stack **a, t_stack **b)
{
	t_stack	*elem_a;
	t_stack	*elem_b;

	(void)b;
	if (*a && (*a)->next != *a)
	{
		elem_a = stack_pop(a);
		elem_b = stack_pop(a);
		stack_push(a, elem_a);
		stack_push(a, elem_b);
	}
}

/**
 * @brief Swap b
 */
void	sb(t_stack **a, t_stack **b)
{
	t_stack	*elem_a;
	t_stack	*elem_b;

	(void)a;
	if (*b && (*b)->next != *b)
	{
		elem_a = stack_pop(b);
		elem_b = stack_pop(b);
		stack_push(b, elem_a);
		stack_push(b, elem_b);
	}
}

/**
 * @brief Swap a and b
 */
void	ss(t_stack **a, t_stack **b)
{
	t_stack	*old_top;

	if (*a && (*a)->next != *a)
	{
		old_top = *a;
		*a = (*a)->next;
		(*a)->prev = old_top->prev;
		old_top->prev = *a;
		old_top->next = (*a)->next;
		(*a)->next = old_top;
	}
	if (*b && (*b)->next != *b)
	{
		old_top = *b;
		*b = (*b)->next;
		(*b)->prev = old_top->prev;
		old_top->prev = *b;
		old_top->next = (*b)->next;
		(*b)->next = old_top;
	}
}
