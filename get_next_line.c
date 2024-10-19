/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrey <nrey@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 20:03:35 by nrey              #+#    #+#             */
/*   Updated: 2024/10/18 20:21:40 by nrey             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

char	*get_next_line(int fd)
{
	static char	*left;
	char		*buf;
	char		*line;
	int			bread;

	if (fd < 0 || !BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if !(buf)
		return (NULL);
	bread = read(fd, buf, BUFFER_SIZE);
	while (bread != '\n' || bread > 0)
	{
		if (bread == '\n')
		{

		}
	}
}
