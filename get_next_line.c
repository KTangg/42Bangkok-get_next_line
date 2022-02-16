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

#include "get_next_line.h"

static	int	find_nl(char *buffer)
{

}

char	*get_next_line(int fd)
{
	char	*line;
	char	*cursor;
	static char	*buffer[BUFFER_SIZE];

	line = (char *)malloc(sizeof(char) * 1);
	line = append_str(line, buffer);
	while (!find_nl(buffer))
	{
		line = append_str(line, buffer);
	}
}
