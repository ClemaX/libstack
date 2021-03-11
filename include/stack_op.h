#ifndef STACK_OP_H
# define STACK_OP_H

# include <stddef.h> // using NULL

# include <stack_def.h>

/**
 * @brief Stack operation function signature.
 */
typedef void	(*t_stack_op)(t_stack **a, t_stack **b);

/**
 * @brief Get a stack operation from it's symbolic name.
 *
 * @param op_symbol		The operation's symbolic name.
 * @return				A pointer to the operation or NULL in case of error.
 */
t_stack_op		stack_op(char const *op_symbol);

/**
 * @brief Swap a's topmost elements.
 * @param a	The top element of the a stack.
 * @param b The top element of the b stack.
 */
void			sa(t_stack **a, t_stack **b);

/**
 * @brief Swap b's topmost elements.
 * @param a	The top element of the a stack.
 * @param b The top element of the b stack.
 */
void			sb(t_stack **a, t_stack **b);

/**
 * @brief Swap a's and b's topmost elements.
 * @param a	The top element of the a stack.
 * @param b The top element of the b stack.
 */
void			ss(t_stack **a, t_stack **b);

/**
 * @brief Pop the top element of b and push it on top of a.
 * @param a	The top element of the a stack.
 * @param b The top element of the b stack.
 */
void			pa(t_stack **a, t_stack **b);

/**
 * @brief Pop the top element of a and push it on top of b.
 * @param a	The top element of the a stack.
 * @param b The top element of the b stack.
 */
void			pb(t_stack **a, t_stack **b);

/**
 * @brief Shift up all elements of stack a by 1.
 *
 * The first element becomes the last one.
 * @param a	The top element of the a stack.
 * @param b The top element of the b stack.
 */
void			ra(t_stack **a, t_stack **b);

/**
 * @brief Shift up all elements of stack b by 1.
 *
 * The first element becomes the last one.
 * @param a	The top element of the a stack.
 * @param b The top element of the b stack.
 */
void			rb(t_stack **a, t_stack **b);

/**
 * @brief Shift up all elements of both stacks by 1.
 *
 * The first element becomes the last one.
 * @param a	The top element of the a stack.
 * @param b The top element of the b stack.
 */
void			rr(t_stack **a, t_stack **b);

/**
 * @brief Shift down all elements of stack a by 1.
 *
 * The last element becomes the first one.
 * @param a	The top element of the a stack.
 * @param b The top element of the b stack.
 */
void			rra(t_stack **a, t_stack **b);

/**
 * @brief Shift down all elements of stack b by 1.
 *
 * The last element becomes the first one.
 * @param a	The top element of the a stack.
 * @param b The top element of the b stack.
 */
void			rrb(t_stack **a, t_stack **b);

/**
 * @brief Shift down all elements of both stacks by 1.
 *
 * The last element becomes the first one.
 * @param a	The top element of the a stack.
 * @param b The top element of the b stack.
 */
void			rrr(t_stack **a, t_stack **b);

#endif
