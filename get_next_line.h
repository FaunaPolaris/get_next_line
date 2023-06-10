/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:28:32 by fpolaris          #+#    #+#             */
/*   Updated: 2023/06/10 16:09:48 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

typedef struct s_line
{
	char			*text;
	char			*extra;
	int				number;
	struct s_line	*next;
}	t_line;

char	*get_next_line(int fd);
char	*cpy(char *buffer, int index, int limit);
int		next_line(char *buffer, int index);
int		count_lines(char *buffer);
char	**split(char *buffer, int lines);

#endif
