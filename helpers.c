/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylaaouf <aylaaouf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 07:16:42 by aylaaouf          #+#    #+#             */
/*   Updated: 2025/01/10 16:46:43 by aylaaouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_args(char **av)
{
	int i;

	i = 0;
	while (av[i])
	{
		i++;
	}
	return (i);
}

void	printf_stack(t_stack_node *stack)
{
	t_stack_node *current;

	current = stack;
	while (current)
	{
		printf("%d -> ", current->value);
		current = current->next;
	}
}

void	push(t_stack_node **stack, int value)
{
	t_stack_node	*new_node;
	t_stack_node	*current;

	new_node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!new_node)
		return ;
	new_node->value = value;
	new_node->next = NULL;
	if (!*stack)
		new_node = *stack;
	else
	{
		current = *stack;
		while (current->next)
			current = current->next;
		current->next = new_node;
	}
}
