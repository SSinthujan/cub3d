#include "cub3d.h"

int game_loop(t_data *data)
{
	if (data->movement.move_forward)
		move_forward(data);
	if (data->movement.move_backward)
		move_backward(data);
	if (data->movement.move_left)
		move_left(data);
	if (data->movement.move_right)
		move_right(data);
	if (data->movement.rotate_left)
		rotate_left(data);
	if (data->movement.rotate_right)
		rotate_right(data);
	perform_raycasting(data);
	return (0);
}

int	close_window(t_data *data)
{
	if (data->mlx_ptr)
	{
		if (data->win_ptr)
			mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		if (data->texture_width && data->texture_height)
			mlx_destroy_image(data->mlx_ptr, data->win_ptr);
		if (data->north_texture.img)
			mlx_destroy_image(data->mlx_ptr, data->north_texture.img);
		if (data->south_texture.img)
			mlx_destroy_image(data->mlx_ptr, data->south_texture.img);
		if (data->east_texture.img)
			mlx_destroy_image(data->mlx_ptr, data->east_texture.img);
		if (data->west_texture.img)
			mlx_destroy_image(data->mlx_ptr, data->west_texture.img);
		mlx_destroy_display(data->mlx_ptr);
		mlx_loop_end(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	free_map(data->config);
	free(data->config);
	exit(0);
	return (0);
}

void	handle_keyhook(t_data *data)
{
	mlx_hook(data->win_ptr, 33, NoEventMask, close_window, data);
	mlx_hook(data->win_ptr, 2, KeyPressMask, key_pressed, data);
	mlx_hook(data->win_ptr, 3, KeyReleaseMask, key_released, data);
}

int	key_pressed(int keycode, t_data *data)
{
	if (keycode == 65307)
		close_window(data);
	if (keycode == 119)
		data->movement.move_forward = 1;
	if (keycode == 115)
		data->movement.move_backward = 1;
	if (keycode == 97)
		data->movement.move_left = 1;
	if (keycode == 100)
		data->movement.move_right = 1;
	if (keycode == 65363)
		data->movement.rotate_left = 1;
	if (keycode == 65361)
		data->movement.rotate_right = 1;
	return (0);
}

int	key_released(int keycode, t_data *data)
{
	if (keycode == 119)
		data->movement.move_forward = 0;
	if (keycode == 115)
		data->movement.move_backward = 0;
	if (keycode == 97)
		data->movement.move_left = 0;
	if (keycode == 100)
		data->movement.move_right = 0;
	if (keycode == 65363)
		data->movement.rotate_left = 0;
	if (keycode == 65361)
		data->movement.rotate_right = 0;
	return (0);
}