/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylaaouf <aylaaouf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:02:41 by aylaaouf          #+#    #+#             */
/*   Updated: 2025/01/12 22:51:56 by aylaaouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_H
# define ALGO_H


#include "../utils/utils.h"
#include "../push_swap.h"
#include "../utils/utils.h"
typedef struct s_stack_node t_stack_node;
int		total_size(t_stack_node *stack);
void	sorted_array2(int *array, int size);
int	    *sorted_array(t_stack_node *stack);
void	chunks(int *array, int size, int chunk_size);
void	sort_stack(t_stack_node *stack);

#endif