/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylaaouf <aylaaouf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:02:41 by aylaaouf          #+#    #+#             */
/*   Updated: 2025/01/13 17:47:24 by aylaaouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_H
# define ALGO_H


#include "../utils/utils.h"
#include "../push_swap.h"
#include "../utils/utils.h"

typedef struct s_stack_node t_stack_node;

int		total_size(t_stack_node *stack);
void	bubble_sort(int *array, int size);
int	    *sorted_array(t_stack_node *stack);
void	chunks(int *array, int size, int chunk_size, t_stack_node **stack_a, t_stack_node **stack_b);
void	sort_stack(t_stack_node **stack_a, t_stack_node **stack_b);


void	find_and_push_max(t_stack_node **stack_a, t_stack_node **stack_b);

#endif