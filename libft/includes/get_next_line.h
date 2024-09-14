/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emagnani <emagnani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:49:08 by emagnani          #+#    #+#             */
/*   Updated: 2024/06/22 17:16:51 by emagnani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <fcntl.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>
# include <limits.h>

char	*get_next_line(int fd);
char	*fill_rest(char *output, char *rest);
char	*read_line(int fd, char *output);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char *s, unsigned int start, size_t len);

#endif