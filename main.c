/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylaaouf <aylaaouf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 00:36:16 by aylaaouf          #+#    #+#             */
/*   Updated: 2025/01/24 13:26:01 by aylaaouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils/utils.h"

void	algo(t_stack_node **stack_a, t_stack_node **stack_b)
{
	if (!is_sorted(*stack_a))
		sort_stack(stack_a, stack_b);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;

	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
}

int	main(int ac, char **av)
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1)
		exit(0);
	valid_input(av, ac);
	into_stack(ac, av, &stack_a);
	algo(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
}
