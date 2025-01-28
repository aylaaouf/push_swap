/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylaaouf <aylaaouf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:03:46 by aylaaouf          #+#    #+#             */
/*   Updated: 2025/01/28 16:59:08 by aylaaouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../push_swap.h"
# include "../utils/utils.h"
# include "limits.h"

int		is_spase(char **input);
int		is_number(char *str);
int		is_duplicates(char **input, int size);
int		check_errors(char **input, int size);
void	valid_input_helper(char **input, char *arr);
int		valid_input(char **input, int size);
void	helper_func(char *tmp, char **arr);
int		big_numbers(char *str, int x, int i);
long	ft_atoi_e(const char *str, int *error);

#endif
