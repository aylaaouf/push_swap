/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylaaouf <aylaaouf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:04:57 by aylaaouf          #+#    #+#             */
/*   Updated: 2025/01/31 20:33:27 by aylaaouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../push_swap.h"

typedef struct s_stack_node
{
	int					value;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

int						count_args(char **av);
void					push(t_stack_node **stack_a, int value);
int						is_sorted(t_stack_node *stack);

void					swap(t_stack_node **stack);
void					sa(t_stack_node **stack, int x);
void					sb(t_stack_node **stack, int x);
void					ss(t_stack_node **stack_a, t_stack_node **stack_b,
							int x);
void					ra(t_stack_node **stack_a, int x);

void					rb(t_stack_node **stack_b, int x);
void					rr(t_stack_node **stack_a, t_stack_node **stack_b,
							int x);
void					rra(t_stack_node **stack_a, int x);
void					rrb(t_stack_node **stack_b, int x);
void					rrr(t_stack_node **stack_a, t_stack_node **stack_b,
							int x);

void					push_b(t_stack_node **stack_a, t_stack_node **stack_b);
void					pa(t_stack_node **stack_a, t_stack_node **stack_b,
							int x);
void					pb(t_stack_node **stack_a, t_stack_node **stack_b,
							int x);
int						total_size(t_stack_node *stack);
#endif