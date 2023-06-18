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
	char		*output;
	
	if (!memory)
	{
		memory = (char*)malloc(sizeof(char));
		memory[0] = '\0';
	}
	memory = fp_readcpy(fd, '\n', &memory);
	if (!memory)
		return (NULL);
	output = fp_cpychr(memory, '\n');
	if (!output)
		return (NULL);
	memory = fp_rcpychr(&memory, '\n');
	if (!memory)
		return (NULL);
	return (output);
}

char	*fp_readcpy(int fd, char end, char **memory)
{
	char		buffer[BUFFER_SIZE];
	int	bytes_read;

	if (fd < 0)
		return (NULL);
	bytes_read = 0;
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == 0)
			return (0);
		memory[0] = fp_strcat(memory, buffer);
		if (!memory[0])
			return (NULL);
		if (fp_strchr(memory[0], end) >= 0)
			break;
	}
	if (bytes_read != BUFFER_SIZE)
		return (fp_cpychr(memory[0], end));
	return (memory[0]);
}

char	*fp_cpychr(char *src, char end)
{
	char	*output;
	int		i;

	i = 0;
	output = (char *)malloc(sizeof(char) * fp_strchr(src, end) + 2);
	if (!output)
		return (NULL);
	while (src[i] != end)
	{
		output[i] = src[i];
		i++;
	}
	output[i] = '\n';
	output[i + 1] = '\0';
	return (output);
}

char	*fp_rcpychr(char **src, char end)
{
	char	*output;
	int		size;
	int		i;
	int		j;

	size = fp_strlen(src[0]);
	i = fp_strchr(src[0], end) + 1;
	j = 0;
	output = (char *)malloc(sizeof(char) * (size - i) + 1);
	if (!output)
		return (NULL);
	while (src[0][i])
	{
		output[j] = src[0][i];
		i++;
		j++;
	}
	output[j] = '\0';
	free(src[0]);
	return (output);
}

char	*fp_catchr(char *first, char *last, char end)
{
	char	*output;
	int		size;
	int		i;
	int		j;

	size = fp_strlen(first) + fp_strchr(last, end);
	output = (char *)malloc(sizeof(char) * size + 1);
	if (!output)
		return (NULL);
	i = 0;
	while (first[i])
		output[i] = first[i];
	j = 0;
	while (last[j++] && i++)
		output[i] = last[j++];
	free(first);
	return (output);
}
