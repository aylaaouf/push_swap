/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylaaouf <aylaaouf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:38:28 by aylaaouf          #+#    #+#             */
/*   Updated: 2025/01/24 03:04:58 by aylaaouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../utils/utils.h"
#include "algo.h"

void	find_and_push_max(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	max;
	int	pos;

	while ((*stack_b))
	{
		max = find_max(*stack_b);
		pos = find_position(*stack_b, max);
		if (pos <= total_size(*stack_b) / 2)
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

void	chunks_helper(t_stack_node **stack_a, t_stack_node **stack_b, int start,
		int end)
{
	int	*array;

	array = sorted_array(*stack_a);
	while (start < end && (*stack_a))
	{
		if ((*stack_a)->value <= array[start])
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			start++;
			end++;
		}
		else if ((*stack_a)->value <= array[end])
		{
			pb(stack_a, stack_b);
			if ((*stack_b) && (*stack_b)->next
				&& (*stack_b)->value < (*stack_b)->next->value)
				sb(stack_b);
			start++;
			end++;
		}
		else
			ra(stack_a);
	}
	free(array);
}

void	chunks(int stack_size, int chunk_size, t_stack_node **stack_a,
		t_stack_node **stack_b)
{
	int i, (start), (end);
	i = 0;
	start = 0;
	end = chunk_size;
	if (stack_size <= 5)
	{
		sort_stack_2(stack_a, stack_b);
		return ;
	}
	while (i < stack_size && (*stack_a))
	{
		if (end >= stack_size)
			end = stack_size;
		chunks_helper(stack_a, stack_b, start, end);
		i += chunk_size;
	}
}

void	sort_stack(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	stack_size;
	int	chunk_size;

	stack_size = total_size(*stack_a);
	chunk_size = 0;
	if (stack_size >= 100)
		chunk_size = total_size(*stack_a) / 14;
	else
		chunk_size = total_size(*stack_a) / 6;
	chunks(stack_size, chunk_size, stack_a, stack_b);
	while (*stack_b)
		find_and_push_max(stack_a, stack_b);
}
