/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 22:23:54 by josfelip          #+#    #+#             */
/*   Updated: 2023/08/16 23:53:03 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(const char *left_str, const char *buff)
{
	char	*str;
	size_t	len;
	size_t	i;
	size_t	j;

	len = ft_strlen(left_str) + ft_strlen(buff);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (left_str[i])
	{
		str[i] = left_str[i];
		i++;
	}
	j = 0;
	while (buff[j])
		str[i++] = buff[j++];
	str[i] = '\0';
	return (str);
}

char	*ft_strdup(const char *s1)
{
	char	*dup;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_get_line(const char *str, size_t *len)
{
	char	*line;
	size_t	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	*len = i;
	if (str[i] == '\0')
		return (ft_strdup(str));
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	i = -1;
	while (++i < *len)
		line[i] = str[i];
	line[i] = '\n';
	*len = i + 1;
	line[*len] = '\0';
	return (line);
}
