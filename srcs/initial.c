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
/*void	init_tiles(t_data *data)*/
/*{*/
/*	int	size = 100;*/
/*	data->tiles = mlx_xpm_file_to_image(data->mlx, "./imgs/coin.xpm", &size, &size);*/
/*	/*data->tiles[1] = mlx_xpm_file_to_image(data->mlx, "./imgs/coin.xpm", &size, &size);*/
/*}*/

void	init_null(t_data *data)
{
	data->mlx = 0;
	data->win = 0;
	data->map->height = 0;
	data->map->width = 0;
}

t_data	*data_init(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	printf("0\n");
	if (!data)
		return (NULL);
	data->map = malloc(sizeof(t_map));
	if (!data->map)
		return (NULL);
	/*data->tiles = malloc(sizeof(char *) * 2);*/
	/*if (!data->tiles)*/
	/*	return (NULL);*/
	printf("1\n");
	init_null(data);
	/*init_tiles(data);*/
	printf("2\n");
	data->tile_size = SIZE;
	data->mlx = mlx_init();
	return (data);
}
