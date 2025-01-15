/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylaaouf <aylaaouf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:38:28 by aylaaouf          #+#    #+#             */
/*   Updated: 2025/01/15 12:54:40 by aylaaouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"
#include "../utils/utils.h"
#include "../push_swap.h"

void	find_and_push_max(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	max;
	int	pos;

	while ((*stack_b))
	{
		max = find_max(*stack_b);
		pos = find_position(*stack_b, max);
		if (total_size(*stack_b) / 2 >= pos)
		{
			while (pos > 0)
			{
				rb(stack_b);
				pos--;
			}
		}
		else
		{
			while (pos < total_size(*stack_b))
			{
				rrb(stack_b);
				pos++;
			}
		}
		pa(stack_a, stack_b);
	}
}

void	chunks(int *array, int stack_size, int chunk_size, t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	i;
	int	start;
	int	end;

	i = 0;
	while (i < stack_size && (*stack_a))
	{
		start = i;
		end = i + chunk_size;
		if (end > stack_size)
			end = stack_size;
		while (start < end && (*stack_a))
		{
			if ((*stack_a)->value <= array[start])
			{
				pb(stack_a, stack_b);
				rb(stack_b);
				start++;
			}
			else if ((*stack_a)->value <= array[end - 1])
			{
				pb(stack_a, stack_b);
				if ((*stack_b) && (*stack_b)->next && (*stack_b)->value < (*stack_b)->next->value)
					sb(stack_b);
				start++;
			}
			else
			{
				ra(stack_a);
			}
		}
		i += chunk_size;
	}
}

void	sort_stack(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	*array;
	int	stack_size;
	int	chunk_size;

	array = sorted_array(*stack_a);
	stack_size = total_size(*stack_a);
	if (stack_size < 100)
		chunk_size = total_size(*stack_a) / 6;
	else
		chunk_size = total_size(*stack_a) / 14;
	chunks(array, stack_size, chunk_size, stack_a, stack_b);
	while (*stack_b)
		find_and_push_max(stack_a, stack_b);
}
