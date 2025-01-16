/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylaaouf <aylaaouf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:02:41 by aylaaouf          #+#    #+#             */
/*   Updated: 2025/01/16 15:44:42 by aylaaouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_H
# define ALGO_H


#include "../utils/utils.h"
#include "../push_swap.h"

typedef struct s_stack_node t_stack_node;

void	sort_stack(t_stack_node **stack_a, t_stack_node **stack_b);
int		total_size(t_stack_node *stack);
void	bubble_sort(int *array, int size);
int	    *sorted_array(t_stack_node *stack);
void	chunks(int *array, int stack_size, int chunk_size, t_stack_node **stack_a, t_stack_node **stack_b);
int	    find_max(t_stack_node *stack_b);
int	    find_position(t_stack_node *stack_b, int max);
void    test_chunk_divisions(t_stack_node **stack_a);

void	find_and_push_max(t_stack_node **stack_a, t_stack_node **stack_b);

#endif