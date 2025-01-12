/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylaaouf <aylaaouf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:54:56 by aylaaouf          #+#    #+#             */
/*   Updated: 2025/01/12 22:30:04 by aylaaouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "../push_swap.h"

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
	t_stack_node	*first;
	t_stack_node	*last;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	first = *stack_a;
	last = *stack_a;

	while (last->next)
		last = last->next;
	*stack_a = last;
	last->prev->next = NULL;
	first->prev = last;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	write(1, "rra\n", 4);
}

void	rrb(t_stack_node **stack_b)
{
	t_stack_node	*first;
	t_stack_node	*last;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	first = *stack_b;
	last = *stack_b;

	while (last->next)
		last = last->next;
	*stack_b = last;
	last->prev->next = NULL;
	first->prev = last;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	write(1, "rrb\n", 4);
}

void	rrr(t_stack_node **stack_a, t_stack_node **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	write(1, "rrr\n", 4);
}