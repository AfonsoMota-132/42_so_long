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

#include "../incs/so_long.h"

int	render_map(t_data *data)
{
	int		x;
	int		y;
	int		size;
	char	*tiles[2] = {"./imgs/ground.xpm", "./imgs/knight.xpm"};
	int		tile;
	void	*wtf;

	size = 100;
	y = -1;
	while (++y < data->map->height)
	{
		x = -1;
		while (++x < data->map->width)
		{
			if (data->map->maps[y][x] == '1' || data->map->maps[y][x] == '0') 
				tile = 0;
			else if (data->map->maps[y][x] == 'c'  
					|| data->map->maps[y][x] == 'C')
				tile = 1;
			wtf = mlx_xpm_file_to_image(data->mlx, tiles[tile], &size, &size);
			mlx_put_image_to_window(data->mlx, data->win, wtf, x * 100, y * 100);
		}
	}
}
