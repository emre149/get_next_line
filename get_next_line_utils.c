/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:00:56 by ededemog          #+#    #+#             */
/*   Updated: 2024/01/08 13:33:57 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

int	buf_str_len(t_list *lst)
{
	int	i;
	int	len;

	len = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		i = 0;
		while (lst->str_buf[i])
		{
			if (lst->str_buf[i] == '\n')
			{
				++len;
				return (len);
			}
			++i;
			++len;
		}
		lst = lst->next;
	}
	return (len);
}

void	ft_lststrcpy(t_list *lst, char *str)
{
	int	i;
	int	j;

	i = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		j = 0;
		while (lst->str_buf[j])
		{
			if (lst->str_buf[j] == '\n')
			{
				str[i++] = '\n';
				str[i] = '\0';
				return ;
			}
			str[i++] = lst->str_buf[i++];
		}
		lst = lst->next;
	}
	str[i] = '\0';
}