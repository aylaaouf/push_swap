/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylaaouf <aylaaouf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 07:16:42 by aylaaouf          #+#    #+#             */
/*   Updated: 2025/01/07 05:31:40 by aylaaouf         ###   ########.fr       */
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
		printf("%d\n", current->value);
		current = current->next;
	}
}

void	push(t_stack_node **stack, int value)
{
	t_stack_node	*new_node;

	new_node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!new_node)
		return ;
	new_node->value = value;
	new_node->next = *stack;
	*stack = new_node;
}
