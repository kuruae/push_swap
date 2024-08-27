/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enzo <enzo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 01:54:43 by enzo              #+#    #+#             */
/*   Updated: 2024/08/27 03:22:11 by enzo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	are_characters_valid(char **array, bool should_free)
{
	int	i;
	int	j;

	i = 0;
	while (array[i])
	{
		j = 0;
		if (array[i][j] == '+' || array[i][j] == '-')
		{
			if (!array[i][j + 1])
			{
				if (should_free)
					ft_free_str_array(&array);
				exit_and_print_errors("error: + or - alone");
			}
			j++;
		}
		while (array[i][j])
		{
			if (ft_isdigit(array[i][j]) || ft_isspace(array[i][j]))
				j++;
			else
			{
				if (should_free)
					ft_free_str_array(&array);
				exit_and_print_errors("error: non-numerical character");
			}
		}
		i++;
	}
}

char	**str_args(char *str)
{
	char	**array;

	array = ft_split(str, ' ');
	are_characters_valid(array, true);
	return (array);
}

char	**multiple_args(char **array)
{
	are_characters_valid(array + 1, false);
	return (array + 1);
}