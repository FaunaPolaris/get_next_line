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

char	*fp_strjoin(char const *s1, char const *s2)
{
	char	*output;
	size_t	len1;
	size_t	len2;
	size_t	count;

	count = -1;
	len1 = fp_strlen(s1);
	len2 = fp_strlen(s2);
	output = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!output)
		return (NULL);
	while (++count < len1)
		output[count] = s1[count];
	count = 0;
	while (count < len2)
	{
		output[len1 + count] = s2[count];
		count++;
	}
	output[len1 + count] = '\0';
	free((void *)s1);
	return (output);
}

char	*fp_strchr(const char *str, int c)
{
	int	count;

	count = 0;
	while (str[count] != '\0' && (str[count] != (unsigned char)c))
		count++;
	if ((unsigned char)c == str[count])
		return ((char *)&str[count]);
	else if (c == '\0')
		return ((char *)&str[count]);
	return (NULL);
}

size_t	fp_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*fp_cutstr(char const *s, unsigned int start, size_t len)
{
	size_t	end;
	size_t	count;
	char	*output;

	end = 0;
	count = 0;
	while (s[end] != '\0')
		end++;
	if (start >= end)
		start = end;
	if (len > end - start)
		len = end - start;
	output = (char *)malloc(sizeof(char) * (len + 1));
	if (!output)
		return (NULL);
	while (count < len)
	{
		output[count] = s[start + count];
		count++;
	}
	output[count] = '\0';
	free((void *)s);
	return (output);
}
