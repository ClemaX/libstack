#include <stack.h>

void	rra(t_stack **a, t_stack **b)
{
	(void)b;
	if (*a)
		*a = (*a)->prev;
}

void	rrb(t_stack **a, t_stack **b)
{
	(void)a;
	if (*b)
		*b = (*b)->prev;
}

void	rrr(t_stack **a, t_stack **b)
{
	if (*a)
		*a = (*a)->next;
	if (*b)
		*b = (*b)->next;
}
