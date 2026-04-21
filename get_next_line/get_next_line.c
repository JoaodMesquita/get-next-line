/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedro <joapedro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 09:31:43 by joapedro          #+#    #+#             */
/*   Updated: 2025/05/20 11:37:32 by joapedro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int			bytes_read;
	static char	read_buffer[BUFFER_SIZE + 1];
	char		*line;

	line = NULL;
	bytes_read = 1;
	line = ft_strjoin(line, read_buffer);
	while (!ft_strchr(read_buffer, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, read_buffer, BUFFER_SIZE);
		if (bytes_read == -1 || read_buffer[0] == 0)
		{
			free(line);
			shift(read_buffer);
			return (NULL);
		}
		if (!bytes_read)
			break ;
		read_buffer[bytes_read] = '\0';
		line = ft_strjoin(line, read_buffer);
	}
	shift(read_buffer);
	return (line);
}
 
#include <stdio.h>
#include <fcntl.h>
int	main(void)
{
	int		fd;
	char	*line;
	
	fd = open("test.txt", O_RDONLY);

	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
} 