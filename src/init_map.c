/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvenkata <jvenkata@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 12:49:52 by jvenkata          #+#    #+#             */
/*   Updated: 2025/10/20 13:05:57 by jvenkata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	init_map(t_map *map, char *file)
{
	char		*line;

	map ->fd = check_name(file);
	map->size = 1;
	map->texture = malloc(sizeof(t_textures));
	map->tab = malloc(sizeof(char *));
	map->tab[0] = NULL;
	line = init_texture(map);
	extract_map(map, line);	
}
