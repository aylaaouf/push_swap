/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylaaouf <aylaaouf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 20:09:09 by aylaaouf          #+#    #+#             */
/*   Updated: 2025/01/31 19:45:51 by aylaaouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "parsing.h"
#include "limits.h"

int	is_spase(char **input)
{
	int	i;
	int	k;

	i = 1;
	while (input[i])
	{
		k = 0;
		while (input[i][k] == ' ' || input[i][k] == '\t')
			k++;
		if (input[i][k] == '\0')
			return (0);
		i++;
	}
	return (1);
}

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '\0')
		return (0);
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

int	is_duplicates(char **input, int size)
{
	int	i;
	int	j;
	int	error;

	i = 0;
	j = 0;
	while (i < size)
	{
		error = 0;
		ft_atoi_e(input[i], &error);
		if (error)
			return (1);
		j = i + 1;
		while (j < size)
		{
			if (ft_atoi(input[i]) == ft_atoi(input[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_errors(char **input, int size)
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

int	valid_input(char **input, int size)
{
	char	*arr;
	char	*tmp;
	int		i;

	arr = ft_strdup("");
	i = 1;
	while (i < size)
	{
		if (!input[i][0] || ft_atoi(input[i]) > INT_MAX
				|| ft_atoi(input[i]) < INT_MIN)
		{
			free(arr);
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		tmp = ft_strjoin(arr, input[i]);
		free(arr);
		arr = tmp;
		if (i < size - 1)
			helper_func(tmp, &arr);
		i++;
	}
	valid_input_helper(input, arr);
	return (free(arr), 0);
}
