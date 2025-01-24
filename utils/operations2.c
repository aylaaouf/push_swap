/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylaaouf <aylaaouf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:54:56 by aylaaouf          #+#    #+#             */
/*   Updated: 2025/01/24 02:00:45 by aylaaouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "utils.h"

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
	write(1, "rb\n", 3);
}

void	rr(t_stack_node **stack_a, t_stack_node **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}

void	rra(t_stack_node **stack_a)
{
	t_stack_node	*b_last;
	t_stack_node	*last;

	if (!stack_a || !(*stack_a)->next)
		return ;
	b_last = NULL;
	last = *stack_a;
	while (last->next)
	{
		b_last = last;
		last = last->next;
	}
	if (b_last)
		b_last->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
	write(1, "rra\n", 4);
}

void	rrb(t_stack_node **stack_b)
{
	t_stack_node	*b_last;
	t_stack_node	*last;

	if (!stack_b || !(*stack_b)->next)
		return ;
	b_last = NULL;
	last = *stack_b;
	while (last->next)
	{
		b_last = last;
		last = last->next;
	}
	if (b_last)
		b_last->next = NULL;
	last->next = *stack_b;
	*stack_b = last;
	write(1, "rrb\n", 4);
}

void	rrr(t_stack_node **stack_a, t_stack_node **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	write(1, "rrr\n", 4);
}
