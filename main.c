/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbarry <elbarry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 13:48:22 by elbarry           #+#    #+#             */
/*   Updated: 2025/12/17 12:31:11 by elbarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd1;
	int		fd2;
	int		fd3;
	char	*line;

	fd1 = open("test1.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	fd3 = open("test3.txt", O_RDONLY);

	if (fd1 < 0 || fd2 < 0 || fd3 < 0)
	{
		perror("open");
		return (1);
	}

	printf("=== Reading alternately from 3 files ===\n");

	line = get_next_line(fd1);
	printf("fd1: %s", line);
	free(line);

	line = get_next_line(fd2);
	printf("fd2: %s", line);
	free(line);

	line = get_next_line(fd3);
	printf("fd3: %s", line);
	free(line);

	line = get_next_line(fd1);
	printf("fd1: %s", line);
	free(line);

	line = get_next_line(fd2);
	printf("fd2: %s", line);
	free(line);

	line = get_next_line(fd3);
	printf("fd3: %s", line);
	free(line);

	printf("\n=== Reading remaining lines ===\n");

	while ((line = get_next_line(fd1)))
	{
		printf("fd1: %s", line);
		free(line);
	}
	while ((line = get_next_line(fd2)))
	{
		printf("fd2: %s", line);
		free(line);
	}
	while ((line = get_next_line(fd3)))
	{
		printf("fd3: %s", line);
		free(line);
	}

	close(fd1);
	close(fd2);
	close(fd3);

	return (0);
}

// #include <stdio.h>
// #include "get_next_line.h"

// int main(int argc, char **argv)
// {
//     int     fd;
//     char    *line;

//     if (argc != 2)
//     {
//         printf("Usage: %s <file>\n", argv[0]);
//         return (1);
//     }

//     fd = open(argv[1], O_RDONLY);
//     if (fd < 0)
//     {
//         perror("open");
//         return (1);
//     }

//     line = get_next_line(fd);
//     while (line)
//     {
//         printf("%s", line);
//         free(line);
//         line = get_next_line(fd);
//     }

//     close(fd);
//     return (0);
// }
