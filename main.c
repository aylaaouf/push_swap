/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylaaouf <aylaaouf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 00:36:16 by aylaaouf          #+#    #+#             */
/*   Updated: 2025/01/22 03:12:30 by aylaaouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils/utils.h"

void free_spliting(char **string)
{
	int i;

	i = 0;
	while (string[i])
	{
		free(string[i]);
		i++;
	}
	free(string);
}

void	into_stack(int ac, char **input, t_stack_node **stack_a)
{
	int		i;
	int		value;
	char	**string;
	char	**tmp;

	i = 1;
	while (i < ac)
	{
		if (ac == 2)
		{
			string = ft_split(input[1], ' ');
			tmp = string;
			while (*string)
			{
				value = ft_atoi(*string);
				push(stack_a, value);
				string++;
			}
			free_spliting(tmp);
		}
		else
		{
			value = ft_atoi(input[i]);
			push(stack_a, value);
		}
		i++;
	}
}

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
