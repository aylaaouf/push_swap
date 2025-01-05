/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylaaouf <aylaaouf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 23:28:40 by aylaaouf          #+#    #+#             */
/*   Updated: 2025/01/05 05:28:24 by aylaaouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack_node **stack, int value)
{
	t_stack_node	*new_node;

	new_node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!new_node)
		return ;
	new_node->value = value;
	new_node->next = *stack;
	*stack = new_node;
}

int	main(int ac, char **av)
{
	t_stack_node	*a;
	//t_stack_node	*b;
	int	i;

	a = NULL;
	//b = NULL;
	i = 0;
	if ((ac == 1) || (ac == 2 && av[1][0] == '\0'))
		return (0);
	if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		ac = count_args(av);
	}
	if (!is_valid(av, ac))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	while (i < ac)
	{
		push(&a, ft_atoi(av[i]));
		i++;
	}
	return (0);
}
