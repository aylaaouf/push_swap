/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylaaouf <aylaaouf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:47:16 by aylaaouf          #+#    #+#             */
/*   Updated: 2025/01/24 03:17:53 by aylaaouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../utils/utils.h"
#include "algo.h"

int	find_min(t_stack_node **stack_a)
{
	int				min;
	t_stack_node	*current;

	current = *stack_a;
	min = current->value;
	while (current)
	{
		if (min > current->value)
		{
			min = current->value;
		}
		current = current->next;
	}
	return (min);
}
