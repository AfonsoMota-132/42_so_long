/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afogonca <afogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 12:14:58 by afogonca          #+#    #+#             */
/*   Updated: 2024/11/10 12:24:35 by afogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

void	count_collect(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y < data->map->height)
	{
		x = -1;
		while (++x < data->map->width)
		{
			if (data->map->maps[y][x] == 'C')
				data->collect++;
		}
	}
	printf("Collectables: %i\n", data->collect);
}
void	init_tiles(t_data *data)
{
	data->tiles[0] = mlx_xpm_file_to_image(data->mlx, "./imgs/ground.xpm",
			&data->tile_size, &data->tile_size);
	data->tiles[1] = mlx_xpm_file_to_image(data->mlx, "./imgs/knight.xpm",
			&data->tile_size, &data->tile_size);
	data->tiles[2] = mlx_xpm_file_to_image(data->mlx, "./imgs/coin.xpm",
			&data->tile_size, &data->tile_size);
	data->tiles[3] = mlx_xpm_file_to_image(data->mlx, "./imgs/castle.xpm",
			&data->tile_size, &data->tile_size);
}

void	init_null(t_data *data)
{
	data->mlx = 0;
	data->win = 0;
	data->map->height = 0;
	data->map->width = 0;
	data->tile_size = 0;
	data->player->x = 0;
	data->player->y = 0;
	data->player->moves = 0;
	data->player->collect = 0;
}

t_data	*data_init(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
	{
		ft_free(data);
		return (NULL);
	}
	data->tile_size = SIZE;
	data->map = malloc(sizeof(t_map));
	data->tiles = malloc(4 * sizeof(void *));
	data->player = malloc(sizeof(t_player));
	if (!data->map || !data->tiles || !data->player)
	{
		ft_free(data);
		return (NULL);
	}
	init_null(data);
	data->mlx = mlx_init();
	init_tiles(data);
	return (data);
}
