/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvenkata <jvenkata@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 17:46:08 by jvenkata          #+#    #+#             */
/*   Updated: 2025/12/02 16:57:47 by jvenkata         ###   ########.fr       */
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
		return (-1);
	}
	return (fd);
}

void	init_map(t_map **map, char *file)
{
	char		*line;

	(*map)->fd = check_name(file);
	if ((*map)->fd == -1)
	{
		free(*map);
		*map = NULL;
		return ;
	}
	(*map)->size = 1;
	(*map)->texture = malloc(sizeof(t_textures));
	(*map)->tab = malloc(sizeof(char *));
	if (!(*map)->texture || !(*map)->tab)
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
		return (NULL);
	init_map(&map, argv[1]);
	return (map);
}
