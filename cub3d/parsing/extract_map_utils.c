/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvenkata <jvenkata@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:33:19 by jvenkata          #+#    #+#             */
/*   Updated: 2025/12/05 11:19:31 by jvenkata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../include/raycast.h"

char	**copy_map(char **map)
{
	int		i;
	int		len;
	char	**map_copy;

	i = 0;
	len = 0;
	while (map && map[len])
		len++;
	map_copy = malloc(sizeof(char *) * (len + 1));
	while (map && map[i])
	{
		map_copy[i] = ft_strdup(map[i]);
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

int	rest(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line && *line == '\0')
	{
		free(line);
		line = get_next_line(fd);
	}
	if (line && *line != '\0')
	{
		ft_error('t');
		free(line);
		return (1);
	}
	else
		return (0);
}
