/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:35:49 by fpolaris          #+#    #+#             */
/*   Updated: 2023/05/29 09:52:49 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 150
#endif

#include <unistd.h>
#include <stdlib.h>

typedef	struct	s_list
{
	char	*text;
	int	number;
	void	*next;
}	t_list

char	*get_next_line(int fd);
char	*cpy(char *buffer, int index, int bytes_read);
int	next_line(char *buffer, int index);

#endif
