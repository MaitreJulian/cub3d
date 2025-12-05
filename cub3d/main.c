/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 10:34:50 by gcauchy           #+#    #+#             */
/*   Updated: 2025/12/05 13:44:43 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/raycast.h"
#include "include/cub3d.h"

int	key_press(int keycode, t_data *data)
{
	if (keycode == ESCAPE)
		return (close_window(data));
	if (keycode == FORWARD)
		data->key.up = 1;
	else if (keycode == BACKWARD)
		data->key.down = 1;
	else if (keycode == LEFT)
		data->key.left = 1;
	else if (keycode == RIGHT)
		data->key.right = 1;
	else if (keycode == LOOK_L)
		data->key.look_l = 1;
	else if (keycode == LOOK_R)
		data->key.look_r = 1;
	return (0);
}

int	key_release(int keycode, t_data *data)
{
	if (keycode == FORWARD)
		data->key.up = 0;
	else if (keycode == BACKWARD)
		data->key.down = 0;
	else if (keycode == LEFT)
		data->key.left = 0;
	else if (keycode == RIGHT)
		data->key.right = 0;
	else if (keycode == LOOK_L)
		data->key.look_l = 0;
	else if (keycode == LOOK_R)
		data->key.look_r = 0;
	return (0);
}

int	update(t_data *data)
{
	if (data->key.up)
		move_forward(data);
	if (data->key.down)
		move_backward(data);
	if (data->key.left)
		move_left(data);
	if (data->key.right)
		move_right(data);
	if (data->key.look_l)
		look_left(data);
	if (data->key.look_r)
		look_right(data);
	draw(data, data->map);
	return (0);
}

void	loop_n_hook(t_data *data)
{
	mlx_hook(data->win, 2, 1L << 0, key_press, data);
	mlx_hook(data->win, 3, 1L << 1, key_release, data);
	mlx_hook((*data).win, 17, 0, close_window, data);
	mlx_loop_hook(data->mlx, update, data);
	mlx_loop((*data).mlx);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2 && !argv[1])
		return (display_error("Format: ./cub3D 'map'", 1, 2));
	data = malloc(sizeof(t_data));
	if (!data)
		return (display_error("Malloc of struct data failed", 1, 2));
	data->map = parse_map(argv);
	if (!data->map)
		return (free(data), 1);
	data->mlx = mlx_init();
	data->win = mlx_new_window((*data).mlx, WIN_LENGTH, WIN_HEIGHT, "cub3D");
	data->img = mlx_new_image((*data).mlx, WIN_LENGTH, WIN_HEIGHT);
	data->addr = mlx_get_data_addr((*data).img, &(*data).bits_per_pixel,
			&(*data).line_length, &(*data).endian);
	data = init_img(data);
	if (!data)
		return (display_error("Error\nxpm file", 1, 2));
	data->cam = init_cam();
	if (!data->cam)
		return (1);
	draw(data, data->map);
	loop_n_hook(data);
	return (0);
}
