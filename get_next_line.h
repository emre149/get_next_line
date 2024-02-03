/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 04:00:05 by ededemog          #+#    #+#             */
/*   Updated: 2024/02/03 18:13:28 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);

void	read_to_stash(int fd, t_list **stash);

t_list	*ft_lstlast(t_list *list);

int		newline(t_list *stash);

void	stash_to_line(t_list *stash, char **line);

void	line_allocation(char **line, t_list *stash);

int		ft_strlen(const char *str);

void	add(t_list **stash, char *buf, int already_read);

void	free_stash(t_list *stash);

void	clean(t_list **stash);

#endif