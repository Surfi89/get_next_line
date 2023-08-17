/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 11:09:39 by josfelip          #+#    #+#             */
/*   Updated: 2023/08/16 23:52:28 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*get_next_line(int fd);
char	*ft_get_line(const char *str, size_t *len);
char	*ft_read_to_left_str(int fd, char *left_str);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(const char *left_str, const char *buff);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);

#endif
