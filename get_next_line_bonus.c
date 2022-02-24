/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 22:44:44 by spoolpra          #+#    #+#             */
/*   Updated: 2022/02/16 22:44:44 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

int	detect_nl(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*read_file(int fd, char *str)
{
	int		byte_read;
	char	*s2;
	char	buffer[BUFFER_SIZE];

	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read <= 0)
			break ;
		s2 = (char *)malloc(sizeof(char) * (byte_read + 1));
		if (!s2)
		{
			free(str);
			return (NULL);
		}
		ft_strlcpy(s2, buffer, byte_read + 1);
		str = ft_strjoin(str, s2);
		free(s2);
		if (detect_nl(str) >= 0)
			break ;
	}
	return (str);
}

char	*create_line(char *str)
{
	int		nl_index;
	char	*line;
	size_t	s_len;

	nl_index = detect_nl(str);
	s_len = ft_strlen(str);
	if (nl_index < 0)
	{
		line = (char *)malloc(sizeof(char) * (s_len + 1));
		if (!line)
		{
			free(str);
			return (NULL);
		}
		ft_strlcpy(line, str, s_len + 1);
		return (line);
	}
	line = (char *)malloc(sizeof(char) * (nl_index + 2));
	if (!line)
	{
		free(str);
		return (NULL);
	}
	ft_strlcpy(line, str, nl_index + 2);
	return (line);
}

char	*cut_line(char *str)
{
	int		nl_index;
	char	*cut_str;
	size_t	len;

	nl_index = detect_nl(str);
	if (nl_index < 0)
	{
		free(str);
		return (NULL);
	}
	len = ft_strlen(str);
	cut_str = (char *)malloc(sizeof(char) * (len - nl_index));
	if (!cut_str)
	{
		free(str);
		return (NULL);
	}
	ft_strlcpy(cut_str, &str[nl_index + 1], len - nl_index);
	free(str);
	return (cut_str);
}

char	*get_next_line(int fd)
{
	char			*line;
	t_info			*fd_info;
	static t_info	*info = NULL;

	if (!info)
		info = create_info(fd);
	fd_info = get_info(fd, info);
	fd_info->line = read_file(fd, fd_info->line);
	if (fd_info->line == NULL)
		return (NULL);
	if (fd_info->line[0] == '\0')
		return (NULL);
	line = create_line(fd_info->line);
	if (!line)
		return (NULL);
	fd_info->line = cut_line(fd_info->line);
	return (line);
}
