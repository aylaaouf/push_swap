/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylaaouf <aylaaouf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 20:06:57 by aylaaouf          #+#    #+#             */
/*   Updated: 2025/01/05 04:47:46 by aylaaouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"

typedef struct s_stack_node
{
    int value;
    struct s_stack_node *next;
}   t_stack_node;

void	push(t_stack_node **stack, int value);
int     is_number(char *str);
int     is_duplicates(char **arr, int size);
int     is_valid(char **input, int size);
int	    count_args(char **av);

# endif
