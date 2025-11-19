/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvenkata <jvenkata@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 17:46:08 by jvenkata          #+#    #+#             */
/*   Updated: 2025/11/19 13:14:45 by jvenkata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../include/raycast.h"

int	check_name(char *file)
{
	int		fd;
	char	*temp;

	fd = 0;
	temp = file;
	while (*temp && *temp != '.')
		temp++;
	if (*temp != '.')
		return (ft_error('n'));
	if (ft_strcmp(temp, ".cub"))
		return (ft_error('n'));
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("Open error");
		return (0);
	}
	return (fd);
}

void	init_map(t_map **map, char *file)
{
	char		*line;

	(*map)->fd = check_name(file);
	if (!(*map)->fd)
	{
		free_map(map);
		return ;
	}
	(*map)->size = 1;
	(*map)->texture = malloc(sizeof(t_textures));
	(*map)->tab = malloc(sizeof(char *));
	if (!(*map)->texture || !(*map)->texture)
	{
		free_map(map);
		return ;
	}
	(*map)->tab[0] = NULL;
	line = init_texture(*map);
	if (!line)
	{
		free_map(map);
		return ;
	}
	extract_map(map, line);
}

t_map	*parse_map(char **argv)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);//FAUT FREE MLX
	init_map(&map, argv[1]);
	// print_textures(map->texture);
	// print_map(map->tab);
	return (map);
}
