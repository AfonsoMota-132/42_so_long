/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afogonca <afogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:09:13 by afogonca          #+#    #+#             */
/*   Updated: 2024/11/10 14:09:14 by afogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long_bonus.h"

int	render_fences(t_data *data, int x, int y)
{
	if (x == 0 && y == 0)
		return (3);
	else if (x == data->map->width - 1 && y == 0)
		return (4);
	else if (x == 0 && y == data->map->height - 1)
		return (5);
	else if (x == data->map->width - 1 && y == data->map->height - 1)
		return (6);
	else if (y == 0 || y == data->map->height - 1)
		return (7);
	else if (x == 0 || x == data->map->width - 1)
		return (8);
	return (9);
}

int	render_option(t_data *data, int x, int y)
{
	if (data->map->maps[y][x] == '0')
		return (0);
	else if (data->map->maps[y][x] == 'P')
		return (11);
	else if (data->map->maps[y][x] == 'C')
		return (1);
	else if (data->map->maps[y][x] == 'E')
		return (2);
	else if (data->map->maps[y][x] == '1')
		return (render_fences(data, x, y));
	else if (data->map->maps[y][x] == 'M')
		return (14);
	return (0);
}

int	render_map(t_data *data)
{
	int		x;
	int		y;
	int		tile;

	y = -1;
	while (++y < data->map->height)
	{
		x = -1;
		while (++x < data->map->width)
		{
			tile = render_option(data, x, y);
			mlx_put_image_to_window(data->mlx, data->win,
				data->tiles[tile], x * SIZE, y * SIZE);
		}
	}
	return (0);
}
