/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylaaouf <aylaaouf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:54:56 by aylaaouf          #+#    #+#             */
/*   Updated: 2025/01/31 20:41:16 by aylaaouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "utils.h"
#include "../algo/algo.h"

void	rb(t_stack_node **stack_b, int x)
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
	if (x == 1)
		write(1, "rb\n", 3);
}

void	rr(t_stack_node **stack_a, t_stack_node **stack_b, int x)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	if (x == 1)
		write(1, "rr\n", 1);
}

void	rra(t_stack_node **stack_a, int x)
{
	t_stack_node	*b_last;
	t_stack_node	*last;

	if (total_size(*stack_a) < 2)
		return ;
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
	if (x == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_stack_node **stack_b, int x)
{
	t_stack_node	*b_last;
	t_stack_node	*last;

	if (total_size(*stack_b) < 2)
		return ;
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
	if (x == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack_node **stack_a, t_stack_node **stack_b, int x)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	if (x == 1)
		write(1, "rrr\n", 4);
}
