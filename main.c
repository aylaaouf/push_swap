/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylaaouf <aylaaouf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 00:36:16 by aylaaouf          #+#    #+#             */
/*   Updated: 2025/01/11 18:08:10 by aylaaouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int build(int ac, char **input, t_stack_node **stack)
{
    int i;
    int value;

    i = 1;
    while (i < ac)
    {
        value = ft_atoi(input[i]);
        push(stack, value);
        i++;
    }
	printf_stack(*stack);
    return (1);
}

int main(int ac, char **av)
{
	t_stack_node	*stack_a;
	//t_stack_node	*stack_b;

	stack_a = NULL;
	//stack_b = NULL;
	if (ac == 1)
		exit(0);
	valid_input(av, ac);
	build(ac, av, &stack_a);
}
