/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 11:56:33 by gcauchy           #+#    #+#             */
/*   Updated: 2025/09/03 12:06:55 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnchr(char *s, char *find)
{
	int	i;
	int	j;
	int	len;

	i = -1;
	len = ft_strlen(find);
	while (s[++i])
	{
		j = 0;
		while (find[j] && s[i + j] == find[j])
			j++;
		if (j == len)
			return (&s[i]);
	}
	if (find[0] == '\0')
		return (&s[i]);
	return (NULL);
}
