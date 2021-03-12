#include <stack.h>
#include <stack_op.h>

void	pa(t_stack **a, t_stack **b)
{
	if (b != NULL)
		stack_push(a, stack_pop(b));
}

void	pb(t_stack **a, t_stack **b)
{
	if (a != NULL)
		stack_push(b, stack_pop(a));
}
