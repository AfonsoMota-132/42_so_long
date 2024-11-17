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

#include "../incs/so_long_bonus.h"

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
}

void	init_tiles2(t_data *data)
{
	data->tiles[10] = mlx_xpm_file_to_image(data->mlx, "./imgs/player_up.xpm",
			&data->tile_size, &data->tile_size);
	data->tiles[11] = mlx_xpm_file_to_image(data->mlx, "./imgs/player_bot.xpm",
			&data->tile_size, &data->tile_size);
	data->tiles[12] = mlx_xpm_file_to_image(data->mlx,
			"./imgs/player_right.xpm", &data->tile_size, &data->tile_size);
	data->tiles[13] = mlx_xpm_file_to_image(data->mlx, "./imgs/player_left.xpm",
			&data->tile_size, &data->tile_size);
	data->tiles[14] = mlx_xpm_file_to_image(data->mlx, "./imgs/mushroom.xpm",
			&data->tile_size, &data->tile_size);
}

void	init_tiles(t_data *data)
{
	data->tiles[0] = mlx_xpm_file_to_image(data->mlx, "./imgs/ground.xpm",
			&data->tile_size, &data->tile_size);
	data->tiles[1] = mlx_xpm_file_to_image(data->mlx, "./imgs/egg.xpm",
			&data->tile_size, &data->tile_size);
	data->tiles[2] = mlx_xpm_file_to_image(data->mlx, "./imgs/coop.xpm",
			&data->tile_size, &data->tile_size);
	data->tiles[3] = mlx_xpm_file_to_image(data->mlx, "./imgs/corner-ul.xpm",
			&data->tile_size, &data->tile_size);
	data->tiles[4] = mlx_xpm_file_to_image(data->mlx, "./imgs/corner-ur.xpm",
			&data->tile_size, &data->tile_size);
	data->tiles[5] = mlx_xpm_file_to_image(data->mlx, "./imgs/corner-bl.xpm",
			&data->tile_size, &data->tile_size);
	data->tiles[6] = mlx_xpm_file_to_image(data->mlx, "./imgs/corner-br.xpm",
			&data->tile_size, &data->tile_size);
	data->tiles[7] = mlx_xpm_file_to_image(data->mlx, "./imgs/top_bot.xpm",
			&data->tile_size, &data->tile_size);
	data->tiles[8] = mlx_xpm_file_to_image(data->mlx, "./imgs/left_right.xpm",
			&data->tile_size, &data->tile_size);
	data->tiles[9] = mlx_xpm_file_to_image(data->mlx, "./imgs/rock.xpm",
			&data->tile_size, &data->tile_size);
	init_tiles2(data);
}

void	init_null(t_data *data)
{
	data->mlx = 0;
	data->win = 0;
	data->map->maps = NULL;
	data->map->height = 0;
	data->map->width = 0;
	data->tile_size = 0;
	data->player->x = 0;
	data->player->y = 0;
	data->player->moves = 0;
	data->player->collect = 0;
	data->exit = 0;
	data->collect = 0;
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
	data->tiles = malloc(15 * sizeof(void *));
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
