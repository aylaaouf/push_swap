/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylaaouf <aylaaouf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 00:35:19 by aylaaouf          #+#    #+#             */
/*   Updated: 2025/01/22 03:54:16 by aylaaouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../utils/utils.h"
#include "algo.h"

int     find_min(t_stack_node **stack_a)
{
    t_stack_node *current;
	int min;

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

void    sort2(t_stack_node **stack_a)
{
    t_stack_node *current;

    current = *stack_a;
    if (current->value > current->next->value)
        sa(stack_a);
}

void    sort3(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	min;
	int pos;

	min = find_min(stack_a);
	pos = find_position(*stack_a, min);
	while (pos > 0)
	{
		ra(stack_a);
		pos--;
	}
	pb(stack_a, stack_b);
	sort2(stack_a);
	pa(stack_a, stack_b);
}

void	sort4(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int min;
	int pos;

	min = find_min(stack_a);
	pos = find_position(*stack_a, min);
	while (pos > 0)
	{
		ra(stack_a);
		pos--;
	}
	pb(stack_a, stack_b);
	sort3(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sort5(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int min;
	int pos;

	min = find_min(stack_a);
	pos = find_position(*stack_a, min);
	if (pos <= total_size(*stack_a) / 2)
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
