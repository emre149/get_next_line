/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 04:00:18 by ededemog          #+#    #+#             */
/*   Updated: 2024/01/26 07:39:35 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*main;
	char			*line;
	int				already_read;

	main = NULL;
	line = NULL;
	already_read = 1;
	if (!stash)
		return (NULL);
	if (fd < 0 || read(fd, line, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	// read from fd and add to linked list (part by part)
	read_to_stash(fd, &main, already_read);
	// extract from stash to line
	// clean the stash
}

void	read_to_stash(int fd, t_list **stash, int *already_read_ptr)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	if (!*stash || !already_read_ptr)
		return ;
	tmp = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!tmp)
		return ;
	while (!newline(*stash) && already_read_ptr != 0)
	{
		*already_read_ptr = read(fd, tmp, BUFFER_SIZE);
		// free le buffer une fois que nous ne lisons plus de char et que la stash est vide
		if ((!*stash && *already_read_ptr == 0) || *already_read_ptr == -1)
		{
			free(tmp);
			return ;
		}
		tmp[*already_read_ptr] = '\0';
		add(stash, tmp, *already_read_ptr);
	}
}

void	add(t_list **stash, char *buf, int already_read)
{
	int		i;
	t_list	*last_node;
	t_list	*new_node;

	i = 0;
	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->content = malloc(sizeof(char) * already_read + 1);
	if (!new_node->content)
		return ;
	while (buf[i] && i < already_read)
	{
		new_node->content[i] = buf[i];
		i++;
	}
	new_node->content[i] = '\0';
	if (!*stash)
	{	
		*stash = new_node;
		return ;
	}
	last_node = ft_lstlast(*stash);
	last_node->next = new_node;
}
