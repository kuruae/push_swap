/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emagnani <emagnani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 20:51:28 by emagnani          #+#    #+#             */
/*   Updated: 2024/06/19 16:23:53 by emagnani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fill_rest(char *output, char *rest)
{
	int	i;

	i = 0;
	while (output && output[i] && output[i] != '\n')
		i++;
	if (output && output[i] == '\n')
		i++;
	rest = ft_substr(output, i, ft_strlen(output + i));
	if (output && output[i])
		output[i] = '\0';
	return (rest);
}

char	*read_line(int fd, char *output)
{
	ssize_t	bytes_read;
	char	buffer[BUFFER_SIZE + 1];

	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(output, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			if (bytes_read < 0)
			{
				free(output);
				output = NULL;
			}
			break ;
		}
		buffer[bytes_read] = '\0';
		output = ft_strjoin(output, buffer);
	}
	return (output);
}

char	*get_next_line(int fd)
{
	static char	*rest = NULL;
	char		*output;

	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (NULL);
	output = NULL;
	if (rest)
		output = rest;
	output = read_line(fd, output);
	rest = fill_rest(output, rest);
	if (!output)
		free(rest);
	return (output);
}
