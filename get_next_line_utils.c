/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 04:00:29 by ededemog          #+#    #+#             */
/*   Updated: 2024/01/26 06:51:38 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	newline(t_list *stash)
{
	int	i;
	
	i = 0;
	if (!stash)
		return (0);
	while (jspquoi->content[++i] != '\n')
	{

	}
}

t_list	*ft_lstlast(t_list *list)
{
	while (list && list->next)
		list = list->next;
	return (list);
}