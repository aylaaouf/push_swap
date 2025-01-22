/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylaaouf <aylaaouf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:56:01 by aylaaouf          #+#    #+#             */
/*   Updated: 2025/01/20 17:30:38 by aylaaouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "utils.h"

void	push_b(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*current;

	current = *stack_a;
	while (current)
	{
		push(stack_b, current->value);
		current = current->next;
	}
	*stack_a = NULL;
}

void	pa(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*head;

	if (!(*stack_b))
		return ;
	head = *stack_b;
	*stack_b = (*stack_b)->next;
	head->next = *stack_a;
	*stack_a = head;
	write(1, "pa\n", 3);
}

void	pb(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*head;

	if (!(*stack_a))
		return ;
	head = *stack_a;
	*stack_a = (*stack_a)->next;
	head->next = *stack_b;
	*stack_b = head;
	write(1, "pb\n", 3);
}
