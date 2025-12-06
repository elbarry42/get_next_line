/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbarry <elbarry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 14:12:38 by elbarry           #+#    #+#             */
/*   Updated: 2025/12/05 22:38:58 by elbarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}
static char	*read_into_stash(int fd, char *stash)
{
	
}

static char	*extract_line(char *stash)
{
	
}

static char	*update_stash(char *stash)
{
	
}

char	*get_next_line(int fd)
{
	
}