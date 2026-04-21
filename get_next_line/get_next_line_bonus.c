/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedro <joapedro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 09:26:51 by joapedro          #+#    #+#             */
/*   Updated: 2025/05/20 11:08:42 by joapedro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	int			bytes_read;
	static char	read_buffer[1024][BUFFER_SIZE + 1];
	char		*line;

	line = NULL;
	bytes_read = 1;
	line = ft_strjoin(line, read_buffer[fd]);
	while (!ft_strchr(read_buffer[fd], '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, read_buffer[fd], BUFFER_SIZE);
		if (bytes_read == -1 || read_buffer[fd][0] == 0)
		{
			free(line);
			shift(read_buffer[fd]);
			return (NULL);
		}
		if (!bytes_read)
			break ;
		read_buffer[fd][bytes_read] = '\0';
		line = ft_strjoin(line, read_buffer[fd]);
	}
	shift(read_buffer[fd]);
	return (line);
}
/*
#include <stdio.h>
#include <fcntl.h>
int	main(void)
{
	char	*line, *line1, *line2, *line3;
	int		fd;
	int		fd1;
	int		fd2;
	int		fd3;

	fd = open("test.txt", O_RDONLY);
	fd1 = open("test1.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	fd3 = open("test3.txt", O_RDONLY);

	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}

	while ((line1 = get_next_line(fd1)))
	{
		printf("%s", line1);
		free(line1);
	}

	while ((line2 = get_next_line(fd2)))
	{
		printf("%s", line2);
		free(line2);
	}

	while ((line3 = get_next_line(fd3)))
	{
		printf("%s", line3);
		free(line3);
	}
	close(fd);
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}*/