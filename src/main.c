#include <stack.h>

#include <stdio.h>
void	print_val(t_stack_val val)
{
	dprintf(1, "%hhu, ", val);
}

int	main(int ac, char **av)
{
	t_stack	*stack;
	t_stack	*new_elem;
	int		i;

	(void)ac;
	(void)av;
	stack = NULL;
	i = 0;
	while (i < 42 && (new_elem = stack_new(i++)))
		stack_push(&stack, new_elem);
	//stack_iter(stack, &print_val);
	//stack_riter(stack, &print_val);
	return (0);
}
