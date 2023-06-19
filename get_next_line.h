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

char	*get_next_line(int fd);
char	*fp_readcpy(int fd, char end, char **memory, int *bytes);
char	*fp_cpychr(char **src, char end);
char	*fp_rcpychr(char **src, char end);
char	*fp_strcat(char **first, char *last, int n);
int		fp_strchr(char *input, char end);
int		fp_chrerror(char *input, char end);
int		fp_strlen(char *input);
char		*fp_remember(char **memory, int *bytes);
#endif
