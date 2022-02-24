/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 12:40:58 by spoolpra          #+#    #+#             */
/*   Updated: 2022/02/24 12:41:07 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while ((i + 1) < dstsize && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize > 0)
		dst[i] = '\0';
	return (dstsize);
}

t_info	*create_info(int fd)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info) * 1);
	info->fd = fd;
	info->line = (char *)malloc(sizeof(char) * 1);
	info->line[0] = '\0';
	info->next = NULL;
	return (info);
}

t_info	*get_info(int fd, t_info *info)
{
	t_info	*tmp;
	t_info	*cursor;

	cursor = info;
	while (cursor != NULL)
	{
		if (cursor->fd == fd)
			return (cursor);
		if (cursor->next == NULL)
			break ;
		cursor = cursor->next;
	}
	tmp = create_info(fd);
	cursor->next = tmp;
	return (tmp);
}

t_info	*free_fd(t_info *start, int fd)
{
	t_info	*cursor;
	t_info	*prev;

	prev = start;
	cursor = start;
	while (cursor != NULL)
	{
		if (cursor->fd == fd)
		{
			if (cursor->line != NULL)
				free(cursor->line);
			if (cursor == start)
				start = start->next;
			else
				prev->next = cursor->next;
			free(cursor);
			break ;
		}
		prev = cursor;
		cursor = cursor->next;
	}
	return (start);
}
