/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylaaouf <aylaaouf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:23:15 by aylaaouf          #+#    #+#             */
/*   Updated: 2025/01/24 13:26:11 by aylaaouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils/utils.h"

void	free_spliting(char **string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		free(string[i]);
		i++;
	}
	free(string);
}

void	into_stack(int ac, char **input, t_stack_node **stack_a)
{
	int i, (value);
	char	**string, (**tmp);
	i = 1;
	while (i < ac)
	{
		if (ac == 2)
		{
			string = ft_split(input[1], ' ');
			tmp = string;
			while (*string)
			{
				value = ft_atoi(*string);
				push(stack_a, value);
				string++;
			}
			free_spliting(tmp);
		}
		else
		{
			value = ft_atoi(input[i]);
			push(stack_a, value);
		}
		i++;
	}
}

