#ifndef STACKDEF_H
# define STACKDEF_H

# include <limits.h> // using CHAR_MAX, CHAR_MIN

# define STACK_VAL_MAX CHAR_MAX
# define STACK_VAL_MIN CHAR_MIN

typedef char			t_stack_val;
typedef unsigned char	t_ustack_val;

typedef struct	s_stack
{
	struct s_stack	*next;
	struct s_stack	*prev;
	t_stack_val		val;
}				t_stack;

#endif
