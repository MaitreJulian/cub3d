/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvenkata <jvenkata@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 12:28:06 by jvenkata          #+#    #+#             */
/*   Updated: 2025/11/18 18:36:10 by jvenkata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../include/raycast.h"

// int	verif_texture(t_map *map)
// {
// 	if()
// }

char	*sub_texture(char *line)
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

int	put_rgb(char *line)
{
	int		r;
	int		g;
	int		b;
	char	**splited;

	while (ft_isspace(*line) && *line)
		line++;
	splited = ft_split(line, ',');
	r = ft_atoi(splited[0]);
	g = ft_atoi(splited[1]);
	b = ft_atoi(splited[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		ft_error('a');
	free_tab(splited);
	return (r * 65536 + g * 256 + b);
}

void	find_texture(t_map *map, char *line)
{
	while (*line)
	{
		if (!ft_strncmp(line, "NO ", 3))
			map->texture->north = sub_texture(line + 3);
		else if (!ft_strncmp(line, "SO ", 3))
			map->texture->south = sub_texture(line + 3);
		else if (!ft_strncmp(line, "WE ", 3))
			map->texture->west = sub_texture(line + 3);
		else if (!ft_strncmp(line, "EA ", 3))
			map->texture->east = sub_texture(line + 3);
		else if (!ft_strncmp(line, "C ", 2))
			map->texture->ceiling = put_rgb(line + 2);
		else if (!ft_strncmp(line, "F ", 2))
			map->texture->floor = put_rgb(line + 2);
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
	// if (!verif_texture(map))
	// 	ft_error('x');
	
	return (line);
}
