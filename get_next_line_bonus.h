/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 13:23:24 by dde-oliv          #+#    #+#             */
/*   Updated: 2021/06/06 18:40:10 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>
# define BUFFER_SIZE	32

typedef struct s_memory
{
	int				fd;
	char			*content;
	struct s_memory	*next;
}		t_memory;

char	*ft_strdup(char *src);

char	*ft_strjoin(char const *s1, char const *s2);

void	*ft_calloc(size_t nmemb, size_t size);

size_t	ft_strlen(char const *str);

void	*ft_memccpy(void *dest, void *src, int c, size_t n);

int		get_next_line(int fd, char **line);

#endif