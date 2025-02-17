/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylaaouf <aylaaouf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 20:06:57 by aylaaouf          #+#    #+#             */
/*   Updated: 2025/01/24 05:11:18 by aylaaouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "algo/algo.h"
# include "libft/libft.h"
# include "parsing/parsing.h"
# include "utils/utils.h"
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>

// typedef struct s_stack_node
// {
//     int value;
//     struct s_stack_node *next;
// 	struct s_stack_node	*prev;
// }   t_stack_node;
void	into_stack(int ac, char **input, t_stack_node **stack_a);

#endif
