#ifndef STACK_H
# define STACK_H

#include <stdlib.h> // using malloc, free, size_t
#include <unistd.h> // using write, read

#include <stack_def.h>

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
 * @brief Push an element the bottom of the stack.
 *
 * @param top	The stack's top element.
 * @param elem	The element to push on top of the stack.
 */
void	stack_push_back(t_stack **top, t_stack *elem);

/**
 * @brief Load a stack from a NULL-terminated C-string array.
 *
 * The digits are converted to t_stack_val.
 *
 * @param values	The NULL-terminated C-string array.
 * @return			A pointer to the stack's top element,
 * or NULL in case of error.
 */
t_stack	*stack_load(char const **values);

/**
 * @brief Pop an element from the top of the stack.
 *
 * @param top		The stack's top element.
 * @return			A pointer to the popped element.
 */
t_stack	*stack_pop(t_stack **top);

#endif
