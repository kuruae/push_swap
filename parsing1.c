/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emagnani <emagnani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 01:54:43 by enzo              #+#    #+#             */
/*   Updated: 2024/09/14 18:33:25 by emagnani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_sign(char **array, int i, bool should_free)
{
	if (array[i][0] == '+' || array[i][0] == '-')
	{
		if (!array[i][1])
		{
			if (should_free)
				ft_free_str_array(&array);
			exit_and_print_errors();
		}
	}
}

void	are_characters_valid(char **array, bool should_free)
{
	int	i;
	int	j;

	i = 0;
	while (array[i])
	{
		check_sign(array, i, should_free);
		j = 0;
		if (array[i][0] == '+' || array[i][0] == '-')
			j = 1;
		while (array[i][j])
		{
			if (!ft_isdigit(array[i][j]) && !ft_isspace(array[i][j]))
			{
				if (should_free)
					ft_free_str_array(&array);
				exit_and_print_errors();
			}
			j++;
		}
		i++;
	}
}

char	**str_args(char *str)
{
	char	**array;
	int		i;

	i = 0;
	while (str[i++] == ' ')
	{
		if (str[i] == '\0')
			exit_and_print_errors();
	}
	array = ft_split(str, ' ');
	are_characters_valid(array, true);
	return (array);
}

char	**multiple_args(char **array)
{
	are_characters_valid(array + 1, false);
	return (array + 1);
}
