/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbarry <elbarry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 15:28:09 by elbarry           #+#    #+#             */
/*   Updated: 2025/12/17 12:05:11 by elbarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*read_into_stash(int fd, char *stash)
{
	char	*buf;
	ssize_t	bytes_read;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
	{
		free(stash);
		return (NULL);
	}
	bytes_read = 1;
	while ((stash == NULL || !ft_strchr(stash, '\n')) && bytes_read > 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buf);
			free(stash);
			return (NULL);
		}
		buf[bytes_read] = '\0';
		stash = ft_strjoin_free(stash, buf);
	}
	free(buf);
	return (stash);
}

static char	*extract_line(char *stash)
{
	size_t	i;
	size_t	j;
	char	*line;

	if (!stash || stash[0] == '\0')
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = stash[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

static char	*update_stash(char *stash)
{
	size_t	i;
	size_t	j;
	char	*new_stash;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	i++;
	new_stash = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	if (!new_stash)
	{
		free(stash);
		return (NULL);
	}
	j = 0;
	while (stash[i])
		new_stash[j++] = stash[i++];
	new_stash[j] = '\0';
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= OPEN_MAX)
		return (NULL);
	stash[fd] = read_into_stash(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = extract_line(stash[fd]);
	if (!line)
	{
		free(stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	stash[fd] = update_stash(stash[fd]);
	return (line);
}
