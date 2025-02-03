/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylaaouf <aylaaouf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 05:01:53 by aylaaouf          #+#    #+#             */
/*   Updated: 2025/02/03 19:09:24 by aylaaouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "get_next_line/get_next_line.h"

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

void	error(char *line, t_stack_node *stack_a, t_stack_node *stack_b)
{
	free(line);
	free_stack(&stack_a);
	free_stack(&stack_b);
	ft_putstr_fd("Error\n", 2);
	get_next_line(-1);
	exit(1);
}

void	operations(char *line, t_stack_node **stack_a, t_stack_node **stack_b)
{
	if (ft_strncmp(line, "sa\n", 3) == 0)
		sa(stack_a, 0);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		sb(stack_b, 0);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		ss(stack_a, stack_b, 0);
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		pa(stack_a, stack_b, 0);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		pb(stack_a, stack_b, 0);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		ra(stack_a, 0);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		rb(stack_b, 0);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		rr(stack_a, stack_b, 0);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		rra(stack_a, 0);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		rrb(stack_b, 0);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		rrr(stack_a, stack_b, 0);
	else
		error(line, *stack_a, *stack_b);
}

void	ft_error(t_stack_node **stack_b)
{
	ft_putstr_fd("KO\n", 1);
	free_stack(stack_b);
}

int	main(int ac, char **av)
{
	char			*line;
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;

	if (ac == 1)
		exit(0);
	stack_a = NULL;
	stack_b = NULL;
	if (valid_input(av, ac))
		exit(1);
	into_stack(ac, av, &stack_a);
	line = get_next_line(0);
	while (line)
	{
		operations(line, &stack_a, &stack_b);
		free(line);
		line = get_next_line(0);
	}
	if (is_sorted(stack_a) && !stack_b)
		ft_putstr_fd("OK\n", 1);
	else
		ft_error(&stack_b);
	free_stack(&stack_a);
	return (0);
}
