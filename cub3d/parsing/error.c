/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 18:02:53 by jvenkata          #+#    #+#             */
/*   Updated: 2025/12/09 12:03:39 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../include/raycast.h"

void	free_tab(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
}

void	free_map(t_map **map)
{
	if (*map)
	{
		close((*map)->fd);
		if ((*map)->tab)
			free_tab((*map)->tab);
		if ((*map)->texture)
		{
			if ((*map)->texture->north)
				free((*map)->texture->north);
			if ((*map)->texture->south)
				free((*map)->texture->south);
			if ((*map)->texture->west)
				free((*map)->texture->west);
			if ((*map)->texture->east)
				free((*map)->texture->east);
			free((*map)->texture);
		}
		free(*map);
		*map = NULL;
	}
}

int	ft_error(char c)
{
	if (c == 'n')
		printf("Error\nWrong name of file. Usage : map_name.cub\n");
	if (c == 'a')
		printf("Error\nWrong RGB.\n");
	if (c == 'm')
		printf("Error\nError malloc.\n");
	if (c == 't')
		printf("Error\nError map.\n");
	if (c == 'p')
		printf("Error\nAmount of player.\n");
	if (c == 'x')
		printf("Error\nWrong texture.\n");
	if (c == 'e')
		printf("Error\nEmpty file.\n");
	if (c == 'z')
		printf("Error\nNot all textures.\n");
	return (-1);
}
