/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 22:45:29 by spoolpra          #+#    #+#             */
/*   Updated: 2022/02/16 22:45:29 by spoolpra         ###   ########.fr       */
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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str_joined;
	size_t	i;
	size_t	len;
	size_t	s1_len;

	len = ft_strlen(s1) + ft_strlen(s2);
	str_joined = (char *)malloc(sizeof(char) * (len + 1));
	if (!str_joined)
	{
		free(s1);
		return (NULL);
	}
	ft_strlcpy(str_joined, s1, ft_strlen(s1) + 1);
	s1_len = ft_strlen(s1);
	i = 0;
	while ((s1_len + i + 1) < (len + 1) && s2[i] != '\0')
	{
		str_joined[i + s1_len] = s2[i];
		i++;
	}
	str_joined[i + s1_len] = '\0';
	free(s1);
	return (str_joined);
}

t_info	*check_fd(int fd, t_info *info)
{
	int		i;
	t_info	*info_fd;

	i = 0;
	if (!info)
	{
		info_fd = (t_info *)malloc(sizeof(t_info) * 2);
		info_fd->fd = fd;
		info_fd->line = (char *)malloc(sizeof(char) * 1);
		info_fd->line[0] = '\0';
		info_fd[1].fd = NULL;
	}
	while (info->)
}
