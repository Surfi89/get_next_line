/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajordan- <ajordan-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 13:17:07 by ajordan-          #+#    #+#             */
/*   Updated: 2021/10/20 10:04:39 by ajordan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
*	GET_NEXT_LINE
*	-------------
*	DESCRIPTION
*	This function takes an opened file descriptor and returns its next line.
*	This function has undefined behavior when reading from a binary file.
*	PARAMETERS
*	#1. A file descriptor 
*	RETURN VALUES
*	If successful, get_next_line returns a string with the full line ending in
*	a line break (`\n`) when there is one. 
*	If an error occurs, or there's nothing more to read, it returns NULL.
*	----------------------------------------------------------------------------
*	AUXILIARY FUNCTIONS
*	-------------------
*	READ_TO_LEFT_STR
*	-----------------
*	DESCRIPTION
*	Takes the opened file descriptor and saves on a "buff" variable what readed
*	from it. Then joins it to the cumulative static variable for the persistence
*	of the information.
*	PARAMETERS
*	#1. A file descriptor.
*	#2. The pointer to the cumulative static variable from previous runs of
*	get_next_line.
*	RETURN VALUES
*	The new static variable value with buffer joined for the persistence of the info,
*	or NULL if error.
*/

#include "get_next_line_bonus.h"
#include <unistd.h>
//#include <stdio.h>
//#include <fcntl.h>

char	*ft_read_to_left_str(int fd, char *left_str)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(left_str, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		left_str = ft_strjoin(left_str, buff);
	}
	free(buff);
	return (left_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*left_str[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	left_str[fd] = ft_read_to_left_str(fd, left_str[fd]);
	if (!left_str[fd])
		return (NULL);
	line = ft_get_line(left_str[fd]);
	left_str[fd] = ft_new_left_str(left_str[fd]);
	return (line);
}

/*int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;

	fd1 = open("tests/test.txt", O_RDONLY);
	fd2 = open("tests/test2.txt", O_RDONLY);
	fd3 = open("tests/test3.txt", O_RDONLY);
	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd2);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd3);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}*/
