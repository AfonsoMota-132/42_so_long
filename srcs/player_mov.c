/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mov.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afogonca <afogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:31:46 by afogonca          #+#    #+#             */
/*   Updated: 2024/11/11 13:31:48 by afogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

int	move(t_data *data)
{
	if (data->map->maps[data->player->to_y][data->player->to_x] == 'C')
	{
		data->map->maps[data->player->to_y][data->player->to_x] = '0';
		data->player->collect++;
	}
	else if (data->map->maps[data->player->to_y][data->player->to_x] == 'E'
		&& data->player->collect == data->collect)
	{
		printf("Game won!\n");
		key_hook(65307, data);
	}
	else if (data->map->maps[data->player->to_y][data->player->to_x] == 'E')
		return (1);
	mlx_put_image_to_window(data->mlx, data->win, data->tiles[0],
		(data->player->x * SIZE), (data->player->y * SIZE));
	mlx_put_image_to_window(data->mlx, data->win, data->tiles[1],
		(data->player->to_x * SIZE), (data->player->to_y * SIZE));
	data->player->x = data->player->to_x;
	data->player->y = data->player->to_y;
	data->player->moves++;
	printf("moves: %i\n", data->player->moves);
	return (0);
}

int	move_up(t_data *data)
{
	if (data->map->maps[data->player->y - 1][data->player->x] != '1')
	{
		data->player->to_x = data->player->x;
		data->player->to_y = data->player->y - 1;
		move(data);
	}
	return (0);
}

int	move_left(t_data *data)
{
	if (data->map->maps[data->player->y][data->player->x - 1] != '1')
	{
		data->player->to_x = data->player->x - 1;
		data->player->to_y = data->player->y;
		move(data);
	}
	return (0);
}

int	move_down(t_data *data)
{
	if (data->map->maps[data->player->y + 1][data->player->x] != '1')
	{
		data->player->to_x = data->player->x;
		data->player->to_y = data->player->y + 1;
		move(data);
	}
	return (0);
}

int	move_right(t_data *data)
{
	if (data->map->maps[data->player->y][data->player->x + 1] != '1')
	{
		data->player->to_x = data->player->x + 1;
		data->player->to_y = data->player->y;
		move(data);
	}
	return (0);
}
