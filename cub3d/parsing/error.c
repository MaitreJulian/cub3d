/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvenkata <jvenkata@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 18:02:53 by jvenkata          #+#    #+#             */
/*   Updated: 2025/11/18 15:47:21 by jvenkata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../include/raycast.h"

void	free_map(t_map *map)
{
	int	i;

	if (map)
	{
		if (map->tab)
		{
			i = -1;
			while (map->tab[++i])
				free(map->tab[i]);
			free(map->tab);
		}
		if (map->texture)
		{
			free(map->texture->north);
			free(map->texture->south);
			free(map->texture->west);
			free(map->texture->east);
			free(map->texture);
		}
		free(map);
		map = NULL;
	}
}

int	ft_error(char c)
{
	if (c == 'n')
		printf("Wrong name of file. Usage : map.cub");
	if (c == 'a')
		printf("Wrong RGB.");
	if (c == 'm')
		printf("Error malloc.");
	if (c == 't')
		printf("Error map.");
	if (c == 'p')
		printf("Error amount of player.");
	if (c == 'x')
		printf("Error texture.");
	return (-1);
}
