/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrey <nrey@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 20:03:35 by nrey              #+#    #+#             */
/*   Updated: 2024/10/25 14:25:46 by nrey             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*e;
	size_t	n;

	n = count * size;
	e = malloc(n);
	if (!e)
		return (0);
	if (n != 0)
	{
		while(n--)
			*p++ = 0;
	}
	return (e);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buf;
	char		*remaining;
	char		*line;
	int			read_ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = NULL;
	while (1)
	{
		read_ret = read(fd, buf, BUFFER_SIZE);
		buf[read_ret] = '\0';
		if (read_ret <= 0)
			break ;
		if (ft_strchr(buf, 10))
		{
			remaining = ft_strchr(buf, 10);
			if (!stash)
			{
				stash = buf;
				line = ft_strjoin("", ft_substr(stash, 0, ft_strlen(stash) - ft_strlen(remaining)));
				stash = remaining;
			}
			else
			{
				stash = ft_strjoin(remaining, buf);
				line = ft_substr(stash, 0, ft_strlen(stash) - ft_strlen(remaining));
				stash = remaining;
			}
			// empty stash.
			// trim/substract line and return it.
		}
	}
	return (line);
}

/*

	----------------

		MEMO GNL

	---------------

	v Read function v

	Requires <fcntl.h> library.

	Takes 3 params :

	- File descriptor (int fd)
	- the buffer pointer, which stores the data being read (void *buf)
	- the size of the buffer, which is the amount of data that will be read (size_t nbytes)

	ssize_t read(int fd, void *buf, size_t nbytes);

	==============
	Tips and steps
	==============

	use strchr to find \n, strchr searches a wanted char within a string.
	use strjoin to merge the data after it was read.
	use substr to remove extra read data after \n.

*/
