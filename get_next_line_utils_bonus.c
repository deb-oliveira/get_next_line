/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 08:04:43 by dde-oliv          #+#    #+#             */
/*   Updated: 2021/06/06 13:23:19 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char const *str)
{
	size_t	size;

	size = 0;
	while (str[size] != '\0')
		size++;
	return (size);
}

char	*ft_strdup(char *src)
{
	char	*src_copy;
	int		count;

	src_copy = malloc(ft_strlen(src) + 1);
	if (!src_copy)
		return (NULL);
	count = 0;
	while (src[count] != '\0')
	{
		src_copy[count] = src[count];
		count++;
	}
	src_copy[count] = '\0';
	return (src_copy);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len_str;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	len_str = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	str = malloc(sizeof(char) * (len_str + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (i + j < len_str)
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	count;

	ptr = malloc(nmemb * size);
	if (!ptr)
		return (ptr);
	count = 0;
	while (count < nmemb * size)
	{
		((unsigned char *)ptr)[count] = (unsigned char) 0;
		count++;
	}
	return (ptr);
}

void	*ft_memccpy(void *dest, void *src, int c, size_t n)
{
	size_t	count;

	count = 0;
	while (count < n && ((unsigned char *)src)[count] != (unsigned char)c)
	{
		((unsigned char *)dest)[count] = ((unsigned char *)src)[count];
		count++;
	}
	if (count == n)
		return (NULL);
	((unsigned char *)dest)[count] = '\0';
	return ((unsigned char *)(src + count + 1));
}
