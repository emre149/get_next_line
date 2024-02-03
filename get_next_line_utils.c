/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 04:00:29 by ededemog          #+#    #+#             */
/*   Updated: 2024/01/26 06:57:35 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	newline(t_list *stash)
{
	int	i;

	i = 0;
	if (!stash)
		return (0);
	while (ft_lstlast(stash)->content[++i])
	{
		if (ft_lstlast(stash)->content[i] == '\n')
			return (1);
	}
	return (0);
}

t_list	*ft_lstlast(t_list *list)
{
	while (list && list->next)
		list = list->next;
	return (list);
}

void	line_allocation(char **line, t_list *stash)
{
	int	i;
	int	len;

	len = 0;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
			{
				len++;
				break;
			}
			len++;
			i++;
		}
		stash = stash->next;
	}
	*line = malloc(sizeof(char) * (len + 1));
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str)
	{
		i++;
	}
	return (i);
}

void	free_stash(t_list *stash)
{
	t_list	*current_node;
	t_list	*next_node;

	current_node = stash;
	while (current_node)
	{
		free(current_node->content);
		next_node = current_node->next;
		free(current_node);
		current_node = next_node;
	}
}