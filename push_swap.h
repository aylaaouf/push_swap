/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylaaouf <aylaaouf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 20:06:57 by aylaaouf          #+#    #+#             */
/*   Updated: 2025/01/08 07:04:08 by aylaaouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
#include <stdio.h>

typedef struct s_stack_node
{
    int value;
    struct s_stack_node *next;
}   t_stack_node;

void	push(t_stack_node **stack, int value);
int     is_number(char *str);
int     is_duplicates(char **input, int size);
int     check_errors(char **input, int size);
int	    count_args(char **av);
int	    valid_input(char **input, int size);

void	sa(t_stack_node **stack);
void	sb(t_stack_node **stack);
void	ss(t_stack_node **stack_a, t_stack_node **stack_b);

# endif
