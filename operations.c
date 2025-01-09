/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylaaouf <aylaaouf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 05:58:08 by aylaaouf          #+#    #+#             */
/*   Updated: 2025/01/08 07:06:20 by aylaaouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	sa(t_stack_node **stack)
{
	swap(stack);
}

void	sb(t_stack_node **stack)
{
	swap(stack);
}

void	ss(t_stack_node **stack_a, t_stack_node **stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

void	ra(t_stack_node **stack_a)
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
}

void	rb(t_stack_node **stack_b)
{
	t_stack_node	*first;
	t_stack_node	*last;
	
	if (!*stack_b || !(*stack_b)->next)
		return ;

	first = *stack_b;
	*stack_b = (*stack_b)->next;
	(*stack_b)->prev = NULL;

	last = *stack_b;
	while (last->next)
		last = last->next;

	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	rr(t_stack_node **stack_a, t_stack_node **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}
