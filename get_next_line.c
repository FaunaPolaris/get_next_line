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
	output = fp_cpychr(&memory, '\n');
	if (!output)
		return (NULL);
	memory = fp_rcpychr(&memory, '\n');
	if (!memory)
		return(NULL);
	return (output);
}

char	*fp_readcpy(int fd, char end, char **memory)
{
	char		buffer[BUFFER_SIZE];
	int	bytes;

	if (fd < 0)
		return (NULL);
	bytes = 0;
	while (1)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == 0)
			return (memory[0]);
		memory[0] = fp_strcat(memory, buffer, bytes);
		if (!memory[0])
			return (NULL);
		if ((fp_chrerror(memory[0], end) >= 0) || bytes != BUFFER_SIZE)
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
		if (src[0][i + 1] == '\0')
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
	int		size;
	int		i;
	int		j;

	size = fp_strlen(src[0]);
	i = fp_strchr(src[0], end) + 1;
	j = 0;
	if (size - i <= 0)
		size = i;
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
