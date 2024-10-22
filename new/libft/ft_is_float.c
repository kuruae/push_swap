/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enzo <enzo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:37:17 by enzo              #+#    #+#             */
/*   Updated: 2024/10/22 19:56:28 by enzo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	check_float_part(char **str, bool *has_digit, bool after_dot)
{
	while (**str && ft_isdigit(**str))
	{
		*has_digit = true;
		(*str)++;
	}
	return (after_dot || *has_digit);
}

bool	ft_is_float(char *str)
{
	bool	has_digit;
	bool	has_dot;
	bool	valid;
	bool	second_valid;

	has_digit = false;
	has_dot = false;
	valid = false;
	if (!str || *str == '\0')
		return (false);
	if (*str == '-' || *str == '+')
		str++;
	valid = check_float_part(&str, &has_digit, false);
	if (*str == '.')
	{
		has_dot = true;
		str++;
		second_valid = check_float_part(&str, &has_digit, true);
		valid = valid && second_valid;
	}
	return (valid && has_digit && has_dot && *str == '\0');
}
