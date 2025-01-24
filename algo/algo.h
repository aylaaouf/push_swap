/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylaaouf <aylaaouf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:02:41 by aylaaouf          #+#    #+#             */
/*   Updated: 2025/01/24 04:06:28 by aylaaouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_H
# define ALGO_H

# include "../push_swap.h"
# include "../utils/utils.h"

typedef struct s_stack_node	t_stack_node;

void						sort_stack(t_stack_node **stack_a,
								t_stack_node **stack_b);
int							total_size(t_stack_node *stack);
void						bubble_sort(int *array, int size);
int							*sorted_array(t_stack_node *stack);
void						chunks(int stack_size, int chunk_size,
								t_stack_node **stack_a, t_stack_node **stack_b);
int							find_max(t_stack_node *stack_b);
int							find_position(t_stack_node *stack_b, int max);
void						find_and_push_max(t_stack_node **stack_a,
								t_stack_node **stack_b);
int							find_min(t_stack_node **stack_a);
void						sort_stack_2(t_stack_node **stack_a,
								t_stack_node **stack_b);
void						push_min(t_stack_node **stack_a,
								t_stack_node **stack_b, int pos);

#endif
