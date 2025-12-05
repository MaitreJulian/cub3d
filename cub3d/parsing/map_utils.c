/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:33:19 by jvenkata          #+#    #+#             */
/*   Updated: 2025/12/05 16:06:56 by gcauchy          ###   ########.fr       */
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

int	diagooooo(char **map, int i, int j)
{
	if (map[i + 1][j + 1] == ' ' || map[i + 1][j - 1] == ' '
		|| map[i - 1][j + 1] == ' ' || map[i - 1][j - 1] == ' ')
		return (0);
	if (map[i + 1][j + 1] == '\0' || map[i + 1][j - 1] == '\0'
		|| map[i - 1][j + 1] == '\0' || map[i - 1][j - 1] == '\0')
		return (0);
	return (1);
}

int	check_diago(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0')
			{
				if (i - 1 == -1 || j - 1 == -1)
					return (0);
				if (map[i] + 1 == NULL || map[i][j + 1] == '\0')
					return (0);
				if (!diagooooo(map, i, j))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
