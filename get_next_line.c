/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:35:52 by fpolaris          #+#    #+#             */
/*   Updated: 2023/06/13 19:54:58 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*memory;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!memory)
	{
		memory = (char *)malloc(sizeof(char) * 1);
		if (!memory)
			return (NULL);
		memory[0] = '\0';
	}
	memory = read_to_line(fd, memory);
	line = fp_findl(memory);
	if (!line)
	{
		free(memory);
		memory = NULL;
		return (NULL);
	}
	memory = fp_findnextl(memory);
	return (line);
}

char	*read_to_line(int fd, char *memory)
{
	char	*buffer;
	int		bytes;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	buffer[0] = '\0';
	while (fp_strchr(buffer, '\n') == NULL)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == 0)
			break ;
		if (bytes == -1)
		{
			free(buffer);
			free(memory);
			return (NULL);
		}
		buffer[bytes] = '\0';
		memory = fp_strjoin(memory, buffer);
	}
	free(buffer);
	return (memory);
}

char	*fp_findl(char *memory)
{
	int		i;
	int		count;
	int		check;
	char	*line;

	i = -1;
	count = -1;
	check = 0;
	if (!memory || memory[0] == '\0')
		return (NULL);
	while (memory[++count] != '\0')
	{
		if (memory[count] == '\n')
			{
				check += 1;
				break ;
			}
	}
	line = (char *)malloc(sizeof(char) * (count + check + 1));
	if (!line)
		return (NULL);
	while (++i < (count + check))
		line[i] = memory[i];
	line[i] = '\0';
	return (line);
}
char	*fp_findnextl(char *memory)
{
	int	size;
	int	start;

	size = 0;
	start = 0;
	if (!memory)
		return (NULL);
	while (memory[size] != '\0')
	{
		if (memory[size] == '\n' && start == 0)
			start = size + 1;
		size++;
	}
	if (!start)
	{
		free(memory);
		return (NULL);
	}
	memory = fp_cutstr(memory, start, (size - start));
	return (memory);
}
