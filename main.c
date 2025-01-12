/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylaaouf <aylaaouf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 00:36:16 by aylaaouf          #+#    #+#             */
/*   Updated: 2025/01/12 12:09:07 by aylaaouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void build(int ac, char **input, t_stack_node **stack_a, t_stack_node **stack_b)
{
    int i;
    int value;

    i = 1;
    while (i < ac)
    {
        value = ft_atoi(input[i]);
        push(stack_a, value);
        i++;
    }
    pb(stack_a, stack_b);
}

int main(int ac, char **av)
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;
    int i;

	stack_a = NULL;
	stack_b = NULL;
    i = 0;
	if (ac == 1)
		exit(0);
	valid_input(av, ac);
	build(ac, av, &stack_a, &stack_b);
    while (i < total_size(stack_b))
    {
        printf("%d\n", sorted_array(stack_b)[i]);
        i++;
    }
}
