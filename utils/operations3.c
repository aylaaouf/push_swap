/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylaaouf <aylaaouf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:56:01 by aylaaouf          #+#    #+#             */
/*   Updated: 2025/01/12 22:30:08 by aylaaouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "../push_swap.h"

void push_b(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node *current;

	current = *stack_a;
	while (current)
	{
	    push(stack_b, current->value);
	    current = current->next;
	}
	*stack_a = NULL;
}

void pa(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node *current;

	current = *stack_b;
	while (current)
	{
		push(stack_a, current->value);
		current = current->next;
	}
	*stack_b = NULL;
	write(1, "pa\n", 3);
}

void pb(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node *current;

	current = *stack_a;
	while (current)
	{
	    push(stack_b, current->value);
	    current = current->next;
	}
	*stack_a = NULL;
	write(1, "pb\n", 3);
}