/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylaaouf <aylaaouf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 00:35:19 by aylaaouf          #+#    #+#             */
/*   Updated: 2025/01/24 04:05:02 by aylaaouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../utils/utils.h"
#include "algo.h"

void	sort2(t_stack_node **stack_a)
{
	t_stack_node	*current;

	current = *stack_a;
	if (current->value > current->next->value)
		sa(stack_a);
}

void	sort3(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	max;
	int	pos;

	(void)stack_b;
	max = find_max(*stack_a);
	pos = find_position(*stack_a, max);
	if (pos == 0)
		ra(stack_a);
	else if (pos == 1)
		rra(stack_a);
	sort2(stack_a);
}

void	sort4(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	min;
	int	pos;

	min = find_min(stack_a);
	pos = find_position(*stack_a, min);
	push_min(stack_a, stack_b, pos);
	sort3(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sort5(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	min;
	int	pos;

	min = find_min(stack_a);
	pos = find_position(*stack_a, min);
	push_min(stack_a, stack_b, pos);
	sort4(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sort_stack_2(t_stack_node **stack_a, t_stack_node **stack_b)
{
	if (total_size(*stack_a) == 2)
		sort2(stack_a);
	else if (total_size(*stack_a) == 3)
		sort3(stack_a, stack_b);
	else if (total_size(*stack_a) == 4)
		sort4(stack_a, stack_b);
	else if (total_size(*stack_a) == 5)
		sort5(stack_a, stack_b);
}
