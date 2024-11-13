/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afogonca <afogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 20:32:46 by afogonca          #+#    #+#             */
/*   Updated: 2024/11/10 20:37:54 by afogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

int	is_rectangle(t_data *data)
{
	int	lines;
	int	line;

	lines = 0;
	line = ft_strlen(data->map->maps[lines]);
	while (++lines < data->map->height)
	{
		if (ft_strlen(data->map->maps[lines]) != line)
			return (1);
	}
	return (0);
}

int	has_walls(t_data *data)
{
	int	x;
	int	y;

	x = -1;
	while (++x < data->map->width)
	{
		if (data->map->maps[0][x] != '1'
			|| data->map->maps[data->map->height - 1][x] != '1')
			return (1);
	}
	y = 0;
	while (++y < data->map->height)
	{
		if (data->map->maps[y][0] != '1'
			|| data->map->maps[y][data->map->width - 1] != '1')
			return (1);
	}
	return (0);
}

int	has_one_pla(t_data *data)
{
	int	x;
	int	y;
	int	ver;

	ver = 0;
	y = -1;
	while (y++ < data->map->height - 1)
	{
		x = -1;
		while (x++ < data->map->width)
		{
			if (data->map->maps[y][x] == 'P'
				&& !ver && ++ver)
			{
				data->player->x = x;
				data->player->y = y;
			}
			else if (data->map->maps[y][x] == 'P' && ver >= 1)
				return (1);
		}
	}
	if (ver == 1)
		return (0);
	return (2);
}

int	has_one_exit(t_data *data)
{
	int	y;
	int	x;

	y = -1;
	while (y++ < data->map->height - 1)
	{
		x = -1;
		while (x++ < data->map->width)
		{
			if (data->map->maps[y][x] == 'E' && data->exit == 0)
			{
				data->exit = 1;
			}
			else if (data->map->maps[y][x] == 'E'
					&& data->exit == 1)
				return (1);
		}
	}
	if (data->exit == 1)
		return (0);
	return (2);
}

int	map_checker(t_data *data)
{
	if (is_rectangle(data) == 1)
		return (ft_printf("Not a rectangle!\n"));
	if (has_walls(data) == 1)
		return (ft_printf("The walls are not complete!\n"));
	if (has_one_pla(data) == 1)
		return (ft_printf("More than one player!\n"));
	if (has_one_pla(data) == 2)
		return (ft_printf("No player spawn in the map!\n"));
	if (has_one_exit(data) == 1)
		return (ft_printf("More than one exit!\n"));
	if (has_one_exit(data) == 2)
		return (ft_printf("No exit in the map!\n"));
	if (flood(data) == 1)
		return (ft_printf("Map does not have path!\n"));
	return (0);
}
