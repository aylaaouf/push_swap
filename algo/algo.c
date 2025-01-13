/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylaaouf <aylaaouf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 10:21:17 by aylaaouf          #+#    #+#             */
/*   Updated: 2025/01/13 21:17:08 by aylaaouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"
#include "../utils/utils.h"
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

void	chunks(int *array, int size, int chunk_size, t_stack_node **stack_a, t_stack_node **stack_b)
{
	int i;
    int j;
	int	mid_index;

    i = 0;
	mid_index = chunk_size / 2;
    while (i < size)
    {
        j = 0;
        while (j < chunk_size && (i + j) < size)
        {
            if ((*stack_a)->value <= array[i + j + mid_index])
                pb(stack_a, stack_b);
            else
                ra(stack_a);
			j++;
		}
        i += chunk_size;
    }
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
void	find_and_push_max(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	max;
	int	pos;
	int	size;

	max = find_max(*stack_b);
	pos = find_position(*stack_b, max);
	size = total_size(*stack_b);
	if (pos <= size / 2)
	{
		while ((*stack_b)->value != max)
			rb(stack_b);
	}
	else
	{
		while ((*stack_b)->value != max)
			rrb(stack_b);
	}
	pa(stack_a, stack_b);
}

void	sort_stack(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	*array;
	int size;
	int	chunk_size;
	
	array = sorted_array(*stack_a);
	size = total_size(*stack_a);
	if (size > 5)
	{
		chunk_size = size / 4;
		if (size % 4 != 0)
			chunk_size++;
	}
	else
		chunk_size = size;
	chunks(array, size, chunk_size, stack_a, stack_b);
	while (*stack_b)
		find_and_push_max(stack_a, stack_b);
}