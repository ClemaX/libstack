#include <stack_op.h>

static int	op_cmp(char const *op_name, char const *str)
{
	while (*op_name && *str && *op_name == *str)
	{
		op_name++;
		str++;
	}
	return ((unsigned char)*op_name - (unsigned char)*str);
}

t_stack_op	stack_op(char const *op_symbol)
{
	static const char		*symbols[] = {
		"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"
	};
	static const unsigned	op_count = sizeof(symbols) / sizeof(*symbols);
	static const t_stack_op	ops[op_count + 1] = {
		&sa, &sb, &ss, &pa, &pb, &ra, &rb, &rr, &rra, &rrb, &rrr, NULL
	};
	unsigned char			i;

	i = 0;
	while (i != op_count && op_cmp(symbols[i], op_symbol))
		i++;
	return (ops[i]);
}
