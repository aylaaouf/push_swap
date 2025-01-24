/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylaaouf <aylaaouf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 05:01:53 by aylaaouf          #+#    #+#             */
/*   Updated: 2025/01/24 09:12:08 by aylaaouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing/parsing.h"
#include "get_next_line/get_next_line.h"

int main(int ac, char **av)
{
    t_stack_node *stack_a;
    t_stack_node *stack_b;
    char *line;
    
    stack_a = NULL;
    line = get_next_line(0);
    valid_input(ac, av);
    into_stack(ac, av, &stack_a);
    while (line)
    {
        if (ft_strncmp(line, "sa", 2) == 0)
            sa(&stack_a, 0);
        else if (ft_strncmp(line, "sb", 2) == 0)
            sb(&stack_b, 0);
        else if (ft_strncmp(line, "ss", 2) == 0)
            ss(&stack_a, &stack_b, 0);
        else if (ft_strncmp(line, "pa", 2) == 0)
            pa(&stack_a, &stack_b, 0);
        else if (ft_strncmp(line, "pb", 2) == 0)
            pb(&stack_a, &stack_b, 0);
        else if (ft_strncmp(line, "ra", 2) == 0)
            ra(&stack_a, 0);
        else if (ft_strncmp(line, "rb", 2) == 0)
            rb(&stack_b, 0);
        else if (ft_strncmp(line, "rr", 2) == 0)
            rr(&stack_a, &stack_b, 0);
        else if (ft_strncmp(line, "rra", 3) == 0)
            rra(&stack_a, 0);
        else if (ft_strncmp(line, "rrb", 3) == 0)
            rrb(&stack_b, 0);
        else if (ft_strncmp(line, "rrr", 3) == 0)
            rrr(&stack_a, &stack_b, 0);
        else
            ft_putstr_fd("Error", 2);
    }
}