/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:35:52 by fpolaris          #+#    #+#             */
/*   Updated: 2023/06/10 16:12:48 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			buffer[BUFFER_SIZE];
	int			bytes_read;
	static t_line		*memory;
	char	**content;
	static int		number_return;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	content = split(buffer, count_lines(buffer, 0));
	memory = add_list(content, count_lines(buffer), buffer, memory);
	free (content);
	while(memory.number != number_return)
		memory = memory->next;
	number_return++;
	if (memory->next.extra)
		memory.text = fusion(memory.text, memory->next.text);
	return (memory.text);
}

t_list	*add_list(char **content, int final_size, char *buffer, t_list *memory)
{
	int	current_size;
	int		final;

	current_size = 0;
	if (!memory)
	{
		memory = (t_list *)malloc(sizeof(t_list));
		memory->next = &memory;
	}
	if (!count_lines(buffer, 1))
		final_size--;
	while (current_size < final_size)
	{
		add(new_line(content[current_size], current_size, 1), start);
		current_size++;
	}
	if (!count_lines(buffer, 1))
		add(new_line(content[final_size + 1], final_size + 1, 2), start);
	return (memory);
}

t_list	*new_line(char *content, int position, int flags)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	if (flags == 1)
		new_node->text = cpy(content, 0, length(content));
	else
		new_node->extra = cpy(content, 0 length(content));
	new_node.number = position;
	return (new_node);
}

void	add(t_list *node, t_list *prev)
{
	prev->next = node;
}
