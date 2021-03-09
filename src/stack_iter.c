#include <stack.h>

void	stack_iter(t_stack const*current, void (*fun)(t_stack_val))
{
	t_stack const*const	end = current;

	if (current)
	{
		fun(current->val);
		current = current->next;
		while (current != end)
		{
			fun(current->val);
			current = current->next;
		}
	}
}

void	stack_riter(t_stack const*current, void (*fun)(t_stack_val))
{
	t_stack const*	end;

	if (current)
	{
		end = current;
		current = current->prev;
		while (current != end)
		{
			fun(current->val);
			current = current->prev;
		}
		fun(current->val);
	}
}
