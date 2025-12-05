/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:48:05 by jvenkata          #+#    #+#             */
/*   Updated: 2025/12/05 11:09:34 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../include/raycast.h"

// void	print_map(char **map_tab)
// {
// 	int i = 0;
// 	int j = 0;

// 	while (map_tab[i])
// 	{
// 		j = 0;
// 		while (map_tab[i][j])
// 		{
// 			printf("%c", map_tab[i][j]);
// 			j++;
// 		}
// 		i++;
// 		printf("\n");
// 	}
// }

// void	print_textures(t_textures *text)
// {
// 	printf("%s\n", text->north);
// 	printf("%s\n", text->south);
// 	printf("%s\n", text->west);
// 	printf("%s\n", text->east);
// 	printf("%i %i %i \n", text->ceiling[0], text->ceiling[1], text->ceiling[0]);
// 	printf("%i %i %i \n", text->floor[0], text->floor[1], text->floor[0]);
// }
void	init_zero_textures(t_map *map)
{
	map->texture->ceiling = -1;
	map->texture->floor = -1;
	map->texture->north = NULL;
	map->texture->south = NULL;
	map->texture->east = NULL;
	map->texture->west = NULL;
}

int	only_01(char *line)
{
	int	i;

	i = 0;
	if (!line || !*line)
		return (0);
	while (line[i])
	{
		if (line[i] == '1' || line[i] == '0' || line[i] == ' ')
			i++;
		else
			return (0);
	}
	return (1);
}

int	all_textures(t_map *map)
{
	if (map->texture->ceiling == -1)
		return (0);
	if (map->texture->floor == -1)
		return (0);
	if (!map->texture->east)
		return (0);
	if (!map->texture->west)
		return (0);
	if (!map->texture->north)
		return (0);
	if (!map->texture->south)
		return (0);
	return (1);
}

int	exist_already(t_map *map, char *line)
{
	while (ft_isspace(*line) && *line)
		line++;
	if (*line)
	{
		if (!ft_strncmp(line, "NO ", 3) && map->texture->north)
			return (1);
		else if (!ft_strncmp(line, "SO ", 3) && map->texture->south)
			return (1);
		else if (!ft_strncmp(line, "WE ", 3) && map->texture->west)
			return (1);
		else if (!ft_strncmp(line, "EA ", 3) && map->texture->east)
			return (1);
		else if (!ft_strncmp(line, "C ", 2) && map->texture->ceiling != -1)
			return (1);
		else if (!ft_strncmp(line, "F ", 2) && map->texture->ceiling != -1)
			return (1);
	}
	return (0);
}

int	xpm_file(t_map *map)
{
	char	*paths[4];
	int		i;
	int		len;
	int		fd;

	paths[0] = map->texture->north;
	paths[1] = map->texture->south;
	paths[2] = map->texture->east;
	paths[3] = map->texture->west;
	i = -1;
	while (++i < 4)
	{
		len = ft_strlen(paths[i]);
		if (len < 4 || ft_strncmp(paths[i] + (len - 4), ".xpm", 4))
			return (0);
		fd = open(paths[i], O_RDONLY);
		if (fd == -1)
			return (0);
		close(fd);
	}
	return (1);
}
