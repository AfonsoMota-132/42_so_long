/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afogonca <afogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:10:13 by afogonca          #+#    #+#             */
/*   Updated: 2024/11/11 16:11:29 by afogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long_bonus.h"

int	flood(t_data *data)
{
	char	**maps;
	int		y;

	maps = malloc(sizeof(char *) * data->map->height);
	if (!maps)
	{
		ft_free(data);
		return (0);
	}
	y = -1;
	while (++y < data->map->height)
		maps[y] = ft_strdup(data->map->maps[y]);
	flood_fill(maps, data, data->player->x, data->player->y);
	return (flood_check(maps, data));
}

void	flood_fill(char **maps, t_data *data, int x, int y)
{
	if (x < 0 || y < 0 || x >= data->map->width || y >= data->map->height)
		return ;
	if (maps[y][x] == 'f' || maps[y][x] == '1' || maps[y][x] == 'E')
		return ;
	if (maps[y][x] != '1' && maps[y][x] != 'E')
		maps[y][x] = 'f';
	flood_fill(maps, data, x + 1, y);
	flood_fill(maps, data, x - 1, y);
	flood_fill(maps, data, x, y + 1);
	flood_fill(maps, data, x, y - 1);
}

int	flood_check(char **maps, t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y < data->map->height)
	{
		x = -1;
		while (++x < data->map->width)
		{
			if (maps[y][x] != '1' && maps[y][x] != 'f'
				&& maps[y][x] != '0' && maps[y][x] != 'E')
			{
				ft_free_arr(maps, data);
				return (1);
			}
		}
	}
	ft_free_arr(maps, data);
	return (0);
}

int	file_check(char *av)
{
	int	len;
	int	i;

	len = ft_strlen(av);
	i = 0;
	while (av[len - 4 + i] && av[len - 4 + i] == ".ber"[i])
		i++;
	return (av[len - 4 + i] - ".ber"[i]);
}

int	has_other(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y < data->map->height)
	{
		x = -1;
		while (++x < data->map->width)
		{
			if (data->map->maps[y][x] != '0' && data->map->maps[y][x] != '1'
				&& data->map->maps[y][x] != 'C' && data->map->maps[y][x] != 'E'
				&& data->map->maps[y][x] != 'P')
				return (1);
		}
	}
	return (0);
}
