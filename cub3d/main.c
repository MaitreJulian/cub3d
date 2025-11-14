/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 10:34:50 by gcauchy           #+#    #+#             */
/*   Updated: 2025/11/14 15:29:14 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/raycast.h"
#include "include/cub3d.h"

int	close_window(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	// free(data);
	exit (0);
	return (0);
}

int	get_key(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keycode == ESCAPE)
		return (close_window(param));
	mlx_string_put(data->mlx, data->win, 500, 800, 0x000000, "GO FORWARD");
	mlx_string_put(data->mlx, data->win, 500, 800, 0x000000, "GO BACKWARD");
	mlx_string_put(data->mlx, data->win, 500, 800, 0x000000, "GO LEFT");
	mlx_string_put(data->mlx, data->win, 500, 800, 0x000000, "GO RIGHT");
	if (keycode == FORWARD)
		mlx_string_put(data->mlx, data->win, 500, 800, 0xFFFFFF, "GO FORWARD");
	else if (keycode == BACKWARD)
		mlx_string_put(data->mlx, data->win, 500, 800, 0xFFFFFF, "GO BACKWARD");
	else if (keycode == LEFT)
		mlx_string_put(data->mlx, data->win, 500, 800, 0xFFFFFF, "GO LEFT");
	else if (keycode == RIGHT)
		mlx_string_put(data->mlx, data->win, 500, 800, 0xFFFFFF, "GO RIGHT");
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	t_map	*map;

	if (argc != 2 && !argv[1])
		return (display_error("Format: ./cub3D 'map'", 1, 2));
	// PARSING of the map
	data = malloc(sizeof(data));
	if (!data)
		return (display_error("Malloc of struct data failed", 1, 2));
	data->mlx = mlx_init();
	data->mlx = mlx_init();
	data->win = mlx_new_window((*data).mlx, WIN_LENGTH, WIN_HEIGHT, "cub3D");
	data->img = mlx_new_image((*data).mlx, WIN_LENGTH, WIN_HEIGHT);
	data->addr = mlx_get_data_addr((*data).img, &(*data).bits_per_pixel,
		&(*data).line_length, &(*data).endian);
	map = parse_map(argv);
	draw(data, map);
	mlx_key_hook((*data).win, get_key, data);
	mlx_hook((*data).win, 17, 0, close_window, data);
	mlx_loop((*data).mlx);
	return (0);
}
