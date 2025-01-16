/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylaaouf <aylaaouf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 00:36:16 by aylaaouf          #+#    #+#             */
/*   Updated: 2025/01/16 15:49:07 by aylaaouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils/utils.h"

void into_stack(int ac, char **input, t_stack_node **stack_a)
{
    int i;
    int value;
    char **string;

    i = 1;
    while (i < ac)
    {
        if (ac == 2)
        {
            string = ft_split(input[1], ' ');
            while (*string)
            {
                value = ft_atoi(*string);
                push(stack_a, value);
                string++;
            }
        }
        else
        {
            value = ft_atoi(input[i]);
            push(stack_a, value);
        }
        i++;
    }
}

void    algo(t_stack_node **stack_a, t_stack_node **stack_b)
{
    if (!is_sorted(*stack_a))
    {
        sort_stack(stack_a, stack_b);
    }
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
	into_stack(ac, av, &stack_a);
    algo(&stack_a, &stack_b);
    //printf_stack(stack_a);
}