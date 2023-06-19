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
	static int	bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (memory && bytes >= 1)
	{
		memory = fp_rcpychr(&memory, '\n');
		if (!memory)
			return (NULL);
	}
	else if (!memory)
	{
		memory = (char*)malloc(sizeof(char) * 1);
		memory[0] = '\0';
	}
	memory = fp_readcpy(fd, '\n', &memory, &bytes);
	if (!memory)
		return (NULL);
	return (fp_remember(&memory, &bytes));
}

char	*fp_remember(char **memory, int *bytes)
{
	char	*output;

	if (memory[0][0] == '\0')
		return (NULL);
	if (fp_strchr(*memory, '\n') >= 0)
	{
		output = fp_cpychr(memory, '\n');
		if (!output)
			return (NULL);
	}
	else
	{
		output = fp_cpychr(memory, '\0');
		if (!output)
			return (NULL);
	}
	if (*bytes == 0)
	{
		free(memory[0]);
		memory[0] = NULL;
	}
	return (output);
}
char	*fp_readcpy(int fd, char end, char **memory, int *bytes)
{
	char		buffer[];

	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (fd < 0)
		return (NULL);
	while (1)
	{
		*bytes = read(fd, buffer, BUFFER_SIZE);
		if (*bytes < 0)
		{
			free(buffer);
			return (NULL);
		}
		if (*bytes == 0)
			return (memory[0]);
		memory[0] = fp_strcat(memory, buffer, *bytes);
		if (!memory[0])
			return (NULL);
		if ((fp_chrerror(memory[0], end) >= 0) || *bytes != BUFFER_SIZE)
			break;
	}
	return (memory[0]);
}

char	*fp_cpychr(char **src, char end)
{
	char	*output;
	int		i;

	i = 0;
	if (src[0][i] == '\0')
	{
		free(src[0]);
		return (NULL);
	}
	output = (char *)malloc(sizeof(char) * fp_strchr(src[0], end) + 2);
	if (!output)
		return (NULL);
	while (src[0][i] != end)
	{
		output[i] = src[0][i];
		i++;
		if (src[0][i] == '\0')
			break ;
	}
	if (src[0][i] != '\0')
		output[i++] = '\n';
	output[i] = '\0';
	return (output);
}

char	*fp_rcpychr(char **src, char end)
{
	char	*output;
	int		i;
	int		j;

	i = fp_strchr(src[0], end) + 1;
	j = 0;
	output = (char *)malloc(sizeof(char) * (fp_strlen(src[0]) - i + 2));
	if (!output || !src[0])
		return (NULL);
	if (fp_strlen(src[0]) - i <= 0)
	{
		output[0] = '\0';
		free(src[0]);
		return (output);
	}
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
