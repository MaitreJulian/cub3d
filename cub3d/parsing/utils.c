/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:48:05 by jvenkata          #+#    #+#             */
/*   Updated: 2025/11/18 11:56:02 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../include/raycast.h"

void	print_map(char **map_tab)
{
	int i = 0;
	int j = 0;

	while (map_tab[i])
	{
		j = 0;
		while (map_tab[i][j])
		{
			printf("%c", map_tab[i][j]);
			j++;
		}
		i++;
	}
}

void	print_textures(t_textures *text)
{
	printf("%s\n", text->north);
	printf("%s\n", text->south);
	printf("%s\n", text->west);
	printf("%s\n", text->east);
	printf("%i %i %i \n", text->ceiling[0], text->ceiling[1], text->ceiling[0]);
	printf("%i %i %i \n", text->floor[0], text->floor[1], text->floor[0]);
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

char	**copy_map(char **map)
{
	int		i;
	int		len;
	char	**map_copy;

	i = 0;
	len = 0;
	while (map && map[len])
		len++;
	map_copy = malloc(sizeof(char *) * len + 1);
	while (map && map[i])
	{
		map_copy[i] = ft_strdup(map[i]);
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}
