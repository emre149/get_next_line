/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:03:31 by ededemog          #+#    #+#             */
/*   Updated: 2024/01/24 18:42:57 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	mr_propre(t_list **list)
{
	t_list	*last_node;
	t_list	*clean_node;
	int		i;
	int		j;
	char	*buffer;

	i = 0;
	j = 0;
	buffer = malloc(BUFFER_SIZE + 1);
	clean_node = malloc(sizeof(t_list));
	if (!buffer || !clean_node)
		return ;
	last_node = ft_lstlast(*list);
	while (last_node->str_buf[i] && last_node->str_buf[i] != '\n')
		++i;
	while (last_node->str_buf[i] && last_node->str_buf[++i])
		buffer[j++] = last_node->str_buf[i];
	buffer[j] = '\0';
	clean_node->str_buf = buffer;
	clean_node->next = NULL;
	dealloc(list, clean_node, buffer);
}

void	add(t_list **list, char *buf)
{
	t_list	*new_element;
	t_list	*last_element;

	last_element = ft_lstlast(*list);
	new_element = malloc(sizeof(t_list));
	if (!new_element)
		return ;
	if (!last_element)
		*list = new_element;
	else
		last_element->next = new_element;
	new_element->str_buf = buf;
	new_element->next = NULL;
}

void	list_creation(t_list **list, int fd)
{
	int		char_read;
	char	*buf;

	// newline va check si un \n est present
	while (!newline(*list))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (!buf)
			return ;
		char_read = read(fd, buf, BUFFER_SIZE);
		// EndOfFile si !char_read
		if (!char_read)
		{
			free(buf);
			return ;
		}
		buf[char_read] = '\0';
		add(list, buf);
	}
}

char	*get_line_of(t_list *list) // me permet d'obtenir le total de la ligne chainee
{
	int		total_str_len;
	char	*next_str;

	if (!list)
		return (NULL);
	total_str_len = buf_str_len(list);
	next_str = malloc(total_str_len + 1);
	if (!next_str)
		return (NULL);
	ft_lststrcpy(list, next_str);
	return (next_str);
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*next_line;

	list = NULL;
	// cas d'erreur de lecture du fd
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
	list_creation(&list, fd);
	if (!list)
		return (NULL);
	next_line = get_line_of(list);

	mr_propre(&list);
	return (next_line);
}
/*
#include <stdio.h>

int		main()
{
	int	nb;
	int	fd;

	nb = 0;

	fd = open("text.txt", O_RDONLY);

	while (nb <= 1)
	{
		printf("%s", get_next_line(fd));
		nb++;
	}
}
*/