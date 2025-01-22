/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylaaouf <aylaaouf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 07:16:42 by aylaaouf          #+#    #+#             */
/*   Updated: 2025/01/22 00:56:47 by aylaaouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "utils.h"

int	count_args(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		i++;
	}
	return (i);
}

void	printf_stack(t_stack_node *stack)
{
	t_stack_node	*current;

	current = stack;
	while (current)
	{
		printf("%d -> ", current->value);
		current = current->next;
	}
}

void	push(t_stack_node **stack_a, int value)
{
	t_stack_node	*new_node;
	t_stack_node	*current;

	new_node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!new_node)
		return ;
	new_node->value = value;
	new_node->next = NULL;
	if (!*stack_a)
		*stack_a = new_node;
	else
	{
		current = *stack_a;
		while (current->next)
			current = current->next;
		current->next = new_node;
	}
}

int	is_sorted(t_stack_node *stack)
{
	t_stack_node	*first;
	t_stack_node	*second;

	first = stack;
	while (first->next)
	{
		second = first->next;
		if (first->value > second->value)
			return (0);
		first = first->next;
	}
	return (1);
}
