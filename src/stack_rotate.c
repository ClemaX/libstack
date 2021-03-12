#include <stack_op.h>

void	ra(t_stack **a, t_stack **b)
{
	(void)b;
	if (*a)
		*a = (*a)->next;
}

void	rb(t_stack **a, t_stack **b)
{
	(void)a;
	if (*b)
		*b = (*b)->next;
}

void	rr(t_stack **a, t_stack **b)
{
	if (*a)
		*a = (*a)->next;
	if (*b)
		*b = (*b)->next;
}
