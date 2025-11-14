/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvenkata <jvenkata@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 14:31:19 by jvenkata          #+#    #+#             */
/*   Updated: 2025/10/04 11:42:12 by jvenkata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
// #include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		len;
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return ((char *)s2);
	else if (!s2)
		return ((char *)s1);
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	str = (char *)ft_calloc(sizeof(char), len + 1);
	if (!str)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	return (str);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str != (char)c && *str != '\0')
		str++;
	if (*str != c)
		return (NULL);
	return ((char *)str);
}

// void	ft_bzero(char *ptr, unsigned int n)
// {
// 	unsigned int	i;
// 	unsigned int	init;

// 	i = 0;
// 	init = 0;
// 	while (i < n)
// 	{
// 		ptr[i] = init;
// 		i++;
// 	}
// }

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	void	*element;

	element = (void *)malloc(elementCount * elementSize);
	if (!element)
		return (NULL);
	ft_bzero((char *)element, elementCount * elementSize);
	return (element);
}
