/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 22:23:38 by josfelip          #+#    #+#             */
/*   Updated: 2023/08/17 12:02:29 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_to_left_str(int fd, char *left_str)
{
	char	*buff;
	ssize_t	rd_bytes;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	rd_bytes = read(fd, buff, BUFFER_SIZE);
	while (!ft_strchr(left_str, '\n') && rd_bytes)
	{
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		if (left_str)
			left_str = ft_strjoin(left_str, buff);
		else
			left_str = ft_strdup(buff);
		rd_bytes = read(fd, buff, BUFFER_SIZE);
	}
	free(buff);
	return (left_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*left_str;
	size_t		len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	left_str = ft_read_to_left_str(fd, left_str);
	if (!left_str)
		return (NULL);
	line = ft_get_line(left_str, &len);
	if (line[0] == '\0')
		return (NULL);
	left_str += len;
	return (line);
}
