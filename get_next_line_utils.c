/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:35:49 by fpolaris          #+#    #+#             */
/*   Updated: 2023/06/13 20:28:24 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	fp_strchr(char *input, char end)
{
	int	i;

	i = 0;
	if (input[i] == end)
		return (0);
	while (input[i] != end)
	{
		if (input[i] == '\0')
			return (-1);
		i++;
	}
	return (i);
}

int	fp_strlen(char *input)
{
	int	i;

	if (!input)
		return (0);
	i = 0;
	if (input[i])
	{
		if (input[i] == '\0')
			return (0);
		while (input[i])
			i++;
	}
	return (i);
}

char	*fp_strcat(char **first, char *last, int n)
{
	char	*output;
	int		i;
	int		j;
	int		size;

	size = fp_strlen(first[0]) + n;
	output = (char *)malloc(sizeof(char) * (size + 1));
	i = 0;
	while (i < fp_strlen(first[0]))
	{
		output[i] = first[0][i];
		i++;
	}
	j = 0;
	while (j < n)
	{
		output[i] = last[j];
		i++;
		j++;
	}
	output[i] = '\0';
	free(first[0]);
	return (output);
}
