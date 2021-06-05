/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 07:28:11 by dde-oliv          #+#    #+#             */
/*   Updated: 2021/06/05 15:59:39 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	get_one_line(int bread, char **line, char **buffer, char **saved)
{
	char	*found_break;
	char	*line_temp;
	char	*linecpy;
	int		is_finished;

	line_temp = ft_calloc(bread + 1, sizeof(char));
	linecpy = *line;
	found_break = ft_memccpy(line_temp, *buffer, '\n', bread);
	is_finished = 0;
	if (found_break)
	{
		if (*saved)
			free(*saved);
		*saved = ft_strdup(found_break);
		is_finished = 1;
	}
	*line = ft_strjoin(linecpy, line_temp);
	free(*buffer);
	free(line_temp);
	free(linecpy);
	return (is_finished);
}

static int	get_saved(char **line, char **saved)
{
	int		is_finished;
	char	*saved_temp;

	if (!line)
		return (-1);
	*line = ft_calloc(1, sizeof(char));
	if (!*line)
		return (-1);
	while (*saved && **saved != '\0')
	{
		is_finished = get_one_line(ft_strlen(*saved), line, saved, &saved_temp);
		*saved = saved_temp;
		if (is_finished == 1)
			return (1);
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*saved;
	char		*buffer;
	int			bread;
	int			is_finished;

	is_finished = get_saved(line, &saved);
	if (is_finished == -1 || is_finished == 1)
		return (is_finished);
	while (is_finished == 0)
	{
		buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		bread = read(fd, buffer, BUFFER_SIZE);
		if (bread == 0)
		{
			free(buffer);
			if (saved)
			{
				free(saved);
				saved = NULL;
			}
			return (0);
		}
		is_finished = get_one_line(bread, line, &buffer, &saved);
	}
	return (1);
}
