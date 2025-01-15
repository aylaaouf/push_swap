/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylaaouf <aylaaouf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:36:44 by aylaaouf          #+#    #+#             */
/*   Updated: 2025/01/15 12:48:32 by aylaaouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/utils.h"
#include "algo.h"
#include "../push_swap.h"

int		total_size(t_stack_node *stack)
{
	t_stack_node	*current;
	int	i;

	current = stack;
	i = 0;
	while (current)
	{
		i++;
		current = current->next;
	}
	return (i);
}

void	bubble_sort(int *array, int size)
{
	int	i;
	int j;
	int tmp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] > array[j])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	*sorted_array(t_stack_node *stack)
{
	int				*array;
	int				size;
	t_stack_node	*current;
	int	i;

	size = total_size(stack);
	array = (int *)malloc(size * sizeof(int));
	if (!array)
		return (NULL);
	current = stack;
	i = 0;
	while (current)
	{
		array[i++] = current->value;
		current = current->next;
	}
	bubble_sort(array, size);
	return (array);
}

int	find_max(t_stack_node *stack_b)
{
	t_stack_node *current;
	int	max;

	if (!stack_b)
		return (0); 

	current = stack_b;
	max = current->value;
	while (current)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

int	find_position(t_stack_node *stack_b, int max)
{
	t_stack_node	*current;
	int	pos;

	pos = 0;
	current = stack_b;
	while (current)
	{
		if (current->value == max)
			return (pos);
		current = current->next;
		pos++;
	}
	return (-1);
}
