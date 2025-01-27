/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylaaouf <aylaaouf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 05:58:08 by aylaaouf          #+#    #+#             */
/*   Updated: 2025/01/27 19:37:48 by aylaaouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "utils.h"

void	swap(t_stack_node **stack)
{
	t_stack_node	*first;
	t_stack_node	*second;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sa(t_stack_node **stack, int x)
{
	swap(stack);
	if (x == 1)
		write(1, "sa\n", 3);
}

void	sb(t_stack_node **stack, int x)
{
	swap(stack);
	if (x == 1)
		write(1, "sb\n", 3);
}

void	ss(t_stack_node **stack_a, t_stack_node **stack_b, int x)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	if (x == 1)
		write(1, "ss\n", 3);
}

void	ra(t_stack_node **stack_a, int x)
{
	t_stack_node	*first;
	t_stack_node	*last;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	first = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_a)->prev = NULL;
	last = *stack_a;
	while (last->next)
		last = last->next;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	if (x == 1)
		write(1, "ra\n", 3);
}
