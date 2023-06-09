/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:35:49 by fpolaris          #+#    #+#             */
/*   Updated: 2023/06/05 13:35:09 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*cpy(char *buffer, int index, int limit)
{
	char	*result;
	int	i;

	i = -1;
	result = (char *)malloc(sizeof(char) * index + 1);
	if (!result)
		return (NULL);
	result[index] = '\0';
	while (index < limit)
	{
		result[++i] = buffer[index++];
	}
	return (result);
}

int	next_line(char *buffer, int index)
{
	while (buffer[index] != '\n' && buffer[index])
	{
		index++;
		if (buffer[index] == '\0')
			return (index);
	}
	return (index);
}

int	count_lines(char *buffer)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			counter++;
		if (buffer[i + 1] == '\0')
			return (counter + 1);
		i++;
	}
	return (counter);
}

char	**split(char *buffer, int lines)
{
	char	**content;
	int	pos;
	int	goal;

	goal = 0;
	pos = 0;
	content = (char **)malloc(sizeof(char *) * (lines + 1));
	if (!content)
		return (NULL);
	while (goal <= lines)
	{
		content[goal] = cpy(buffer, pos, next_line(buffer, pos));
		if (!content[goal])
			return (NULL);
		pos = (next_line(buffer, pos));
		pos++;
		goal++;
	}
	content[lines + 1] = '\0';
	return (content);
}
