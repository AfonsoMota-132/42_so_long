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

#include "../incs/so_long.h"
int	flood(t_data *data)
{
	char	**maps;
	int		y;

	maps = malloc(sizeof(char *) * data->map->height + 1);
	if (!maps)
	{
		ft_free(data);
		return (0);
	}
	y = -1;
	while (++y < data->map->height)
		maps[y] = ft_strdup(data->map->maps[y]);
	printf("width:%i \nheight: %i\n", data->map->width, data->map->height);
	flood_fill(maps, data, data->player->x, data->player->y);
	return(flood_check(maps, data));
}

void	flood_fill(char **maps, t_data *data, int x, int y)
{
	if (x < 0 || y < 0 || x >= data->map->width || y >= data->map->height)
		return ;
	if (maps[y][x] == 'f' || maps[y][x] == '1')
		return ;
	if (maps[y][x] != '1')
		maps[y][x] = 'f';

	flood_fill(maps, data, x + 1, y);
	flood_fill(maps, data, x - 1, y);
	flood_fill(maps, data, x, y + 1);
	flood_fill(maps, data, x, y - 1);
}

int		flood_check(char **maps, t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y < data->map->height)
	{
		x = -1;
		while (++x < data->map->width)
		{
			if(maps[y][x] != '1' && maps[y][x] != 'f')
				return (1);
		}
	}
	return 0;
}

int		has_all(t_data *data)
{
	
	return (0);
}

