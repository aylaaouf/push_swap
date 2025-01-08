/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylaaouf <aylaaouf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 20:09:09 by aylaaouf          #+#    #+#             */
/*   Updated: 2025/01/07 09:48:40 by aylaaouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_spase(char **input)
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
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < size)
	{
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
	char *arr;
    char **numbers;  
    int i;
    int	k;

    if (size == 1)
        return (0);
    arr = ft_strdup("");
    i = 1;
    k = 0;
    while (i < size)
    {
	if (!input[i][0])    
	{
		write(2, "Erro1\n", 6);
		exit(1);
	}
        arr = ft_strjoin(arr, input[i]);
        if (i < size - 1)
        {
		arr = ft_strjoin(arr, " ");
        }
	k++;
        i++;
    }
    numbers = ft_split(arr, ' ');
    i = count_args(numbers);
    if (!check_errors(numbers, i))
    {
        write(2, "Erro2\n", 6);
        exit(1);
    }
    if (!is_spase(input))
    {
	    write(2, "Erro3\n", 6);
	    exit(1);
    }
    return (0);
}
