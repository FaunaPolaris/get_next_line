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

char	*cpy(char *buffer, int index, int bytes_read)
{
	char	*result;

	result = (char *)malloc(sizeof(char) * bytes_read + 1);
	if (!result)
		return (NULL);
	while (index < bytes_read)
	{
		result[index] = buffer[index];
		index++;
	}
	return (result);
}
