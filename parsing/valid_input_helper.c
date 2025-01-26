/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_input_helper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylaaouf <aylaaouf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:51:46 by aylaaouf          #+#    #+#             */
/*   Updated: 2025/01/26 21:32:17 by aylaaouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "parsing.h"

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
	free_numbers(numbers);
}
