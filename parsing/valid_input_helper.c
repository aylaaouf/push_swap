/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_input_helper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylaaouf <aylaaouf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:51:46 by aylaaouf          #+#    #+#             */
/*   Updated: 2025/02/01 03:13:14 by aylaaouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "parsing.h"

long	ft_atoi_e(const char *str, int *error)
{
	int		i;
	long	result;
	int		sign;

	i = 0;
	result = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
		{
			sign *= -1;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		if ((result * sign) > 2147483647 || (result * sign) < -2147483648)
			return (*error = 1);
		i++;
	}
	return (result * sign);
}

void	free_numbers(char **numbers)
{
	int	i;

	i = 0;
	while (numbers[i])
	{
		free(numbers[i]);
		i++;
	}
	free(numbers);
}

void	helper_func(char *tmp, char **arr)
{
	tmp = ft_strjoin(*arr, " ");
	free(*arr);
	*arr = tmp;
}

int	sign_checker(char **input, char *arr, char **numbers)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (input[i])
	{
		j = 0;
		while (input[i][j])
		{
			if ((input[i][j] == '+' || input[i][j] == '-') &&
				!(input[i][j + 1] >= '0' && input[i][j + 1] <= '9'))
			{
				free(arr);
				ft_putstr_fd("Error\n", 2);
				free_numbers(numbers);
				exit(1);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	valid_input_helper(char **input, char *arr)
{
	char	**numbers;
	int		size;

	numbers = ft_split(arr, ' ');
	size = count_args(numbers);
	if (!check_errors(numbers, size))
	{
		free(arr);
		ft_putstr_fd("Error\n", 2);
		free_numbers(numbers);
		exit(1);
	}
	if (!is_spase(input))
	{
		free(arr);
		ft_putstr_fd("Error\n", 2);
		free_numbers(numbers);
		exit(1);
	}
	sign_checker(input, arr, numbers);
	free_numbers(numbers);
}
