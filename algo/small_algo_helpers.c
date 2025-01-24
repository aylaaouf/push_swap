/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_algo_helpers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylaaouf <aylaaouf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 04:03:12 by aylaaouf          #+#    #+#             */
/*   Updated: 2025/01/24 04:05:39 by aylaaouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../utils/utils.h"
#include "algo.h"

void	push_min(t_stack_node **stack_a, t_stack_node **stack_b, int pos)
{
	int i;

	(void)stack_b;
	i = 1;
	while (i > 0)
	{
		if (pos <= (total_size(*stack_a) / 2))
		{
			while (pos > 0)
			{
				ra(stack_a);
				pos--;
			}
		}
		else
		{
			while (pos < total_size(*stack_a))
			{
				rra(stack_a);
				pos++;
			}
		}
		pb(stack_a, stack_b);
		i--;
	}
}