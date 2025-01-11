/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylaaouf <aylaaouf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 00:36:16 by aylaaouf          #+#    #+#             */
/*   Updated: 2025/01/11 22:26:50 by aylaaouf         ###   ########.fr       */
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
    printf_stack(*stack_a);
    printf("test\n");
    printf_stack(*stack_b);
    pa(stack_a, stack_b);
    printf_stack(*stack_a);
    printf("test\n");
    printf_stack(*stack_b);
}

int main(int ac, char **av)
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1)
		exit(0);
	valid_input(av, ac);
	build(ac, av, &stack_a, &stack_b);
}
