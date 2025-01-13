/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylaaouf <aylaaouf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:04:57 by aylaaouf          #+#    #+#             */
/*   Updated: 2025/01/13 12:44:47 by aylaaouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include "../push_swap.h"

typedef struct s_stack_node
{
    int value;
    struct s_stack_node *next;
	struct s_stack_node	*prev;
}   t_stack_node;


int     count_args(char **av);
void    printf_stack(t_stack_node *stack);
void	push(t_stack_node **stack_a, int value);
void	push_to_push(t_stack_node **stack_a, t_stack_node **stack_b);
int     is_sorted(t_stack_node *stack);

void    swap(t_stack_node **stack);
void	sa(t_stack_node **stack);
void	sb(t_stack_node **stack);
void	ss(t_stack_node **stack_a, t_stack_node **stack_b);
void	ra(t_stack_node **stack_a);

void	rb(t_stack_node **stack_b);
void	rr(t_stack_node **stack_a, t_stack_node **stack_b);
void	rra(t_stack_node **stack_a);
void	rrb(t_stack_node **stack_b);
void	rrr(t_stack_node **stack_a, t_stack_node **stack_b);

void    push_b(t_stack_node **stack_a, t_stack_node **stack_b);
void    pa(t_stack_node **stack_a, t_stack_node **stack_b);
void    pb(t_stack_node **stack_a, t_stack_node **stack_b);

#endif