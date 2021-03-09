#ifndef STACK_H
# define STACK_H

#include <stdlib.h> // using malloc, free, size_t
#include <unistd.h> // using write, read

typedef char	t_stack_val;

typedef struct	s_stack
{
	struct s_stack	*next;
	struct s_stack	*prev;
	t_stack_val		val;
}				t_stack;

/**
 * @brief Allocate a new stack element on the heap.
 *
 * @param val	The value to assign to the new element.
 * @return		A pointer to the newly allocated element.
 */
t_stack	*stack_new(t_stack_val val);

/**
 * @brief Clear a stack and set its pointer to NULL.
 *
 * @param top	The stack's top element.
 */
void	stack_clear(t_stack **top);

/**
 * @brief Iterate over a stack,
 * calling a given function on each value.
 *
 * @param top	The stack's top element.
 * @param fun	The function to be called on each value.
 */
void	stack_iter(t_stack const*top, void (*fun)(t_stack_val));

/**
 * @brief Iterate over a stack in reverse order,
 * calling a given function on each value.
 *
 * @param top	The stack's top element.
 * @param fun	The function to be called on each value.
 */
void	stack_riter(t_stack const*top, void (*fun)(t_stack_val));

/**
 * @brief Push an element on top of the stack.
 *
 * @param top	The stack's top element.
 * @param elem	The element to push on top of the stack.
 */
void	stack_push(t_stack **top, t_stack *elem);

/**
 * @brief Pop an element from the top of the stack.
 *
 * @param top		The stack's top element.
 * @return			A pointer to the popped element.
 */
t_stack	*stack_pop(t_stack **top);

/**
 * @brief Swap a's topmost elements.
 * @param a	The top element of the a stack.
 * @param b The top element of the b stack.
 */
void	sa(t_stack **a, t_stack **b);

/**
 * @brief Swap b's topmost elements.
 * @param a	The top element of the a stack.
 * @param b The top element of the b stack.
 */
void	sb(t_stack **a, t_stack **b);

/**
 * @brief Swap a's and b's topmost elements.
 * @param a	The top element of the a stack.
 * @param b The top element of the b stack.
 */
void	ss(t_stack **a, t_stack **b);

/**
 * @brief Pop the top element of b and push it on top of a.
 * @param a	The top element of the a stack.
 * @param b The top element of the b stack.
 */
void	pa(t_stack **a, t_stack **b);

/**
 * @brief Pop the top element of a and push it on top of b.
 * @param a	The top element of the a stack.
 * @param b The top element of the b stack.
 */
void	pb(t_stack **a, t_stack **b);

/**
 * @brief Shift up all elements of stack a by 1.
 *
 * The first element becomes the last one.
 * @param a	The top element of the a stack.
 * @param b The top element of the b stack.
 */
void	ra(t_stack **a, t_stack **b);

/**
 * @brief Shift up all elements of stack b by 1.
 *
 * The first element becomes the last one.
 * @param a	The top element of the a stack.
 * @param b The top element of the b stack.
 */
void	rb(t_stack **a, t_stack **b);

/**
 * @brief Shift up all elements of both stacks by 1.
 *
 * The first element becomes the last one.
 * @param a	The top element of the a stack.
 * @param b The top element of the b stack.
 */
void	rr(t_stack **a, t_stack **b);

/**
 * @brief Shift down all elements of stack a by 1.
 *
 * The last element becomes the first one.
 * @param a	The top element of the a stack.
 * @param b The top element of the b stack.
 */
void	rra(t_stack **a, t_stack **b);

/**
 * @brief Shift down all elements of stack b by 1.
 *
 * The last element becomes the first one.
 * @param a	The top element of the a stack.
 * @param b The top element of the b stack.
 */
void	rrb(t_stack **a, t_stack **b);

/**
 * @brief Shift down all elements of both stacks by 1.
 *
 * The last element becomes the first one.
 * @param a	The top element of the a stack.
 * @param b The top element of the b stack.
 */
void	rrr(t_stack **a, t_stack **b);

#endif
