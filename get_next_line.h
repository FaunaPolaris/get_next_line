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
# define BUFFER_SIZE 20
#endif

#include <unistd.h>
#include <stdlib.h>

typedef	struct	s_line
{
	char	*text;
	char	*extra;
	int	number;
	struct s_line	*next;
	struct s_line	*head;
}	t_line;

char	*get_next_line(int fd);
char	*cpy(char *buffer, int index, int limit);
int	next_line(char *buffer, int index);
int	count_lines(char *buffer);
char	**split(char *buffer, int lines);

#endif
