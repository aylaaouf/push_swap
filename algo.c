/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylaaouf <aylaaouf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 10:21:17 by aylaaouf          #+#    #+#             */
/*   Updated: 2025/01/12 12:18:28 by aylaaouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	sorted_array2(int *array, int size)
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
	sorted_array2(array, size);
	return (array);
}