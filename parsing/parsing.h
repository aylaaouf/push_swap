/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylaaouf <aylaaouf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:03:46 by aylaaouf          #+#    #+#             */
/*   Updated: 2025/01/12 22:38:33 by aylaaouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

#include "../utils/utils.h"
#include "../push_swap.h"

int is_spase(char **input);
int is_number(char *str);
int	is_duplicates(char **input, int size);
int	check_errors(char **input, int size);
int	valid_input(char **input, int size);

#endif