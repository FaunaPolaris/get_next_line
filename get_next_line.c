/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:35:52 by fpolaris          #+#    #+#             */
/*   Updated: 2023/05/29 10:01:08 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE];
	int	bytes_read;
	int	line;
	static t_list	memory;
	static int	current;

	current++;
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	line = count_lines(buffer);
	if (!memory)
		memory = new_list(buffer, line);
	else
		add_list(buffer, line, memory);
	return (memory);
}
