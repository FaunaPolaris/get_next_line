/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:28:32 by fpolaris          #+#    #+#             */
/*   Updated: 2023/06/13 18:26:32 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char		*get_next_line(int fd);
char		*read_to_line(int fd, char *str);
char		*fp_findl(char *memory);
char		*fp_findnextl(char *memory);
char		*fp_joinfree(char *memory, char *buffer);
char		*fp_strjoin(char const *s1, char const *s2);
char		*fp_strchr(const char *str, int c);
void		*fp_calloc(size_t count, size_t size);
char		*fp_cutstr(char const *s, unsigned int start, size_t len);
size_t		fp_strlen(const char *str);

#endif
