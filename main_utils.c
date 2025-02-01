/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylaaouf <aylaaouf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:23:15 by aylaaouf          #+#    #+#             */
/*   Updated: 2025/02/01 16:25:26 by aylaaouf         ###   ########.fr       */
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

void	single_input(t_stack_node **stack_a, char *numbers)
{
	int		value;
	char	**string;
	char	**tmp;

	string = ft_split(numbers, ' ');
	tmp = string;
	while (*string)
	{
		value = ft_atoi(*string);
		push(stack_a, value);
		string++;
	}
	free_spliting(tmp);
}

void	into_stack(int ac, char **input, t_stack_node **stack_a)
{
	int		i;
	char	*numbers;
	char	*tmp;
	char	*new_numbers;

	i = 1;
	numbers = ft_strdup("");
	if (!numbers)
		return ;
	while (i < ac)
	{
		tmp = ft_strjoin(numbers, " ");
		new_numbers = ft_strjoin(tmp, input[i]);
		free(tmp);
		if (!new_numbers)
		{
			free(numbers);
			return ;
		}
		free(numbers);
		numbers = new_numbers;
		i++;
	}
	single_input(stack_a, numbers);
	free(numbers);
}
