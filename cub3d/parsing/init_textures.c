/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 12:28:06 by jvenkata          #+#    #+#             */
/*   Updated: 2025/11/18 13:26:51 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../include/raycast.h"

char	*without_space(char *line)
{
	int		i;
	char	*new_line;

	i = 0;
	while (ft_isspace(*line) && *line)
		line++;
	if (ft_strncmp(line, "./", 2) == 0)
	{
		line++;
		line++;
	}
	while (!ft_isspace(line[i]) && line[i])
	{
		if (line[i] == '\n')
		{
			i--;
			break ;
		}
		i++;
	}
	new_line = ft_substr(line, 0, i);
	return (new_line);
}

int	*fill_tab(char *line)
{
	int		*tab;
	char	**splited;
	int		i;

	tab = malloc(3 * sizeof(int));
	if (!tab)
		ft_error('m');
	while (ft_isspace(*line) && *line)
		line++;
	splited = ft_split(line, ',');
	tab[0] = ft_atoi(splited[0]);
	tab[1] = ft_atoi(splited[1]);
	tab[2] = ft_atoi(splited[2]);
	i = 0;
	while (i < 3)
	{
		if (tab[i] > 255 || tab[i] < 0)
			ft_error('a');
		i++;
	}
	return (tab);
}

void	find_texture(t_map *map, char *line)
{
	while (*line)
	{
		if (!ft_strncmp(line, "NO ", 3))
			map->texture->north = without_space(line + 3);
		else if (!ft_strncmp(line, "SO ", 3))
			map->texture->south = without_space(line + 3);
		else if (!ft_strncmp(line, "WE ", 3))
			map->texture->west = without_space(line + 3);
		else if (!ft_strncmp(line, "EA ", 3))
			map->texture->east = without_space(line + 3);
		else if (!ft_strncmp(line, "C ", 2))
			map->texture->ceiling = fill_tab(line + 2);
		else if (!ft_strncmp(line, "F ", 2))
			map->texture->floor = fill_tab(line + 2);
		line ++;
	}
}

char	*init_texture(t_map *map)
{
	char	*line;

	line = get_next_line(map->fd);
	while (line && *line != '1')
	{
		find_texture(map, line);
		free(line);
		line = get_next_line(map->fd);
	}
	return (line);
}
