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

	memory = fp_readcpy(fd, '\n', memory);
	if (!memory)
		return (NULL);
	output = fp_cpychr(memory, '\n');
	if (!output)
		return (NULL);
	memory = fp_rcpychr(memory, '\n');
	if (!memory)
		return (NULL);
	return (output);
}

char	*fp_readcpy(int fd, char end, char *memory)
{
	char		*output;
	char		buffer[BUFFER_SIZE];
	int	bytes_read;

	if (fd < 0)
		return (NULL);
	bytes_read = 0;
	while (1)
	{
		if (!memory || fp_strchr(memory, end) == -1)
			bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == 0)
			return (memory);
		if (!memory && !output)
			output = fp_strcpy(buffer);
		else if (!memory)
			output = fp_strcat(&output, buffer);
		else
		{
			output = fp_strcat(&memory, buffer);
			memory = output;
		}
		if (fp_strchr(buffer, end) >= 0 || !output)
			break ;
	}	
	return (output);
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

char	*fp_rcpychr(char *src, char end)
{
	char	*output;
	int		i;
	int		j;

	i = fp_strchr(src, end) + 1;
	j = 0;
	output = (char *)malloc(sizeof(char) * (fp_strlen(src) - i));
	if (!output)
		return (NULL);
	while (src[i])
	{
		output[j] = src[i];
		i++;
		j++;
	}
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
