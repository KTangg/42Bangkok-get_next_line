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

t_info	*get_info(int fd, t_info *info)
{
	t_info	*tmp;

	if (!info)
	{
		info = (t_info *)malloc(sizeof(t_info) * 1);
		info->fd = fd;
		info->line = NULL;
		info->next = NULL;
		return (info);
	}
	while (info != NULL)
	{
		if (info->fd == fd)
			return (info);
		if (info->next == NULL)
			break ;
		info = info->next;
	}
	tmp = (t_info *)malloc(sizeof(t_info) * 1);
	tmp->fd = fd;
	tmp->line = NULL;
	tmp->next = NULL;
	info->next = tmp;
	return (tmp);
}

char	*get_next_line(int fd)
{
	t_info			*fd_info;
	static t_info	*info = NULL;

	fd_info = get_info(fd, info);
}
