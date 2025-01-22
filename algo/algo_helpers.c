/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylaaouf <aylaaouf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:47:16 by aylaaouf          #+#    #+#             */
/*   Updated: 2025/01/22 15:48:06 by aylaaouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../utils/utils.h"
#include "algo.h"

int	find_min(t_stack_node **stack_a)
{
	t_stack_node	*current;
	int				min;

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