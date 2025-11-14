/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 12:49:52 by jvenkata          #+#    #+#             */
/*   Updated: 2025/11/14 14:43:03 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../include/raycast.h"

void	init_map(t_map *map, char *file)
{
	char		*line;

	map->fd = check_name(file);
	map->size = 1;
	map->texture = malloc(sizeof(t_textures));
	map->tab = malloc(sizeof(char *));
	map->tab[0] = NULL;
	line = init_texture(map);
	extract_map(map, line);
}
