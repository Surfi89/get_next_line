/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 10:49:44 by josfelip          #+#    #+#             */
/*   Updated: 2023/08/17 11:48:48 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	char	*line;
	int		fd;
	int		i;

	if (argc == 1)
		fd = 0;
	else
		fd = open(argv[1], O_RDONLY);
	i = 1;
	line = get_next_line(fd);
	while (line)
	{
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
		line = get_next_line(fd);
	}
	if (fd)
		close(fd);
	return (0);
}
