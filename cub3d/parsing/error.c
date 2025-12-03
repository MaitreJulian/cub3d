/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvenkata <jvenkata@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 18:02:53 by jvenkata          #+#    #+#             */
/*   Updated: 2025/12/02 15:48:24 by jvenkata         ###   ########.fr       */
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
		printf("Wrong name of file. Usage : map_name.cub\n");
	if (c == 'a')
		printf("Wrong RGB.\n");
	if (c == 'm')
		printf("Error malloc.\n");
	if (c == 't')
		printf("Error map.\n");
	if (c == 'p')
		printf("Error amount of player.\n");
	if (c == 'x')
		printf("Error texture.\n");
	if (c == 'e')
		printf("Empty file.\n");
	return (-1);
}
