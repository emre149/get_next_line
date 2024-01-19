/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:03:26 by ededemog          #+#    #+#             */
/*   Updated: 2024/01/08 16:20:39 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_list
{
	char			*str_buf;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);

void	add(t_list **list, char *buf);

void	list_creation(t_list **list, int fd);

char	*get_line_of(t_list *list);

t_list	*ft_lstlast(t_list *lst);

void	ft_lststrcpy(t_list *lst, char *str);

void	mr_propre(t_list **list);

int	buf_str_len(t_list *lst);

void	add(t_list **list, char *buf);

# endif