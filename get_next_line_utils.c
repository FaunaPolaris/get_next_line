/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:35:49 by fpolaris          #+#    #+#             */
/*   Updated: 2023/06/10 18:04:58 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	fp_strchr(char *input, char end)
{
	int	i;

	i = 0;
	while (input[i++] != end && input[i])
		;
	if (input[i] != '\n')
		return (0);
	return (i);
}

int	fp_strlen(char *input)
{
	int	i;

	i = 0;
	while (input[i++])
		;
	return (i);
}

char	*fp_strcpy(char *input)
{
	char	*output;
	int		i;

	output = (char *)malloc(sizeof(char) * (fp_strlen(input) + 1));
	if (!output)
		return (NULL);
	i = 0;
	while (input[i++])
		output[i] = input[i];
	output[i] = '\0';
	return (output);
}

char	*fp_strcat(char *first, char *last)
{
	char	*output;
	int		i;
	int		j;
	int		size;

	size = fp_strlen(first) + fp_strlen(last);
	output = (char *)malloc(sizeof(char) * (size + 1));
	i = 0;
	while (i < fp_strlen(first) && i++)
		output[i] = first[i];
	j = 0;
	while (j < fp_strlen(last) && i++)
		output[i] = last[j++];
	free (first);
	return (output);
}
