/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afogonca <afogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 09:38:38 by afogonca          #+#    #+#             */
/*   Updated: 2024/11/11 09:40:25 by afogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long_bonus.h"

void	ft_free_arr(char **maps, t_data *data)
{
	int	y;

	y = -1;
	while (++y < data->map->height)
		free(maps[y]);
	free(maps);
}

void	ft_free_tiles(t_data *data)
{
	int	i;

	i = 0;
	while (i < 14)
		mlx_destroy_image(data->mlx, data->tiles[i++]);
	free(data->tiles);
}

void	ft_free_map(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->height)
	{
		free(map->maps[i]);
		map->maps[i] = NULL;
	}
	if (map->maps)
		free(map->maps);
	free(map);
}

int	ft_free(t_data *data)
{
	if (!data)
		return (0);
	if (data->map)
		ft_free_map(data->map);
	if (data->tiles)
		ft_free_tiles(data);
	if (data->player)
		free(data->player);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	free(data->mlx);
	free(data);
	return (0);
}
