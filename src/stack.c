#include <stack.h>

void	stack_push(t_stack **top, t_stack *elem)
{
	t_stack *const	old_top = *top;

	if (elem)
	{
		*top = elem; // { elem <-> top }

		if (old_top) // { old_top -> old_top ...}
		{
			elem->next = old_top; // { elem -> old_top -> old_top ... } next points to old top
			elem->prev = old_top->prev; // { old_top <- elem -> old_top -> old_top ... } previous points to last elem
			old_top->prev = elem; // { old_top <- elem <- old_top <- elem } old top previous points to elem
			elem->prev->next = elem; //  { old_top -> elem <- old_top <- elem } last node points to elem
		}
	}
}

void	stack_push_back(t_stack **top, t_stack *elem)
{
	if (elem)
	{
		if (*top) // { old_top -> old_top ...}
		{
			elem->next = *top; // { elem -> old_top -> old_top ... }
			elem->prev = (*top)->prev; // { old_top <- elem -> old_top -> old_top ... }
			(*top)->prev = elem; // { old_top <- elem <- old_top <- elem }
			elem->prev->next = elem;
		}
		else
		{
			*top = elem;
			elem->prev = elem; // { elem <- elem ... }
			elem->next = elem; // { elem -> elem ... }
		}
	}
}

t_stack	*stack_pop(t_stack **top)
{
	t_stack	*const	old_top = *top;

	if (old_top && old_top != old_top->next)
	{
		*top = old_top->next;
		(*top)->prev = old_top->prev;
		old_top->prev->next = *top;
		old_top->prev = old_top;
		old_top->next = old_top;
	}
	else
		*top = NULL;
	return (old_top);
}

t_stack	*stack_new(t_stack_val val)
{
	t_stack *const	elem = malloc(sizeof(*elem));

	if (elem)
	{
		elem->next = elem;
		elem->prev = elem;
		elem->val = val;
	}
	return (elem);
}

void	stack_clear(t_stack **top)
{
	t_stack const*const	end = *top;
	t_stack				*next;

	if (*top)
	{
		next = (*top)->next;
		free(*top);
		*top = next;
		while (*top != end)
		{
			next = (*top)->next;
			free(*top);
			*top = next;
		}
		*top = NULL;
	}
}
