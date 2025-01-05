/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylaaouf <aylaaouf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 20:09:09 by aylaaouf          #+#    #+#             */
/*   Updated: 2025/01/04 06:29:39 by aylaaouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
            		return (0);
		i++;
	}
	return (1);
}

int	is_duplicates(char **arr, int size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (ft_atoi(arr[i]) == ft_atoi(arr[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_valid(char **input, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (!is_number(input[i]))
			return (0);
		i++;
	}
	if (is_duplicates(input, size))
		return (0);
	return (1);
}
