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

	maps = malloc(sizeof(char *) * data->map->height);
	if (!maps)
	{
		ft_free(data);
		return (0);
	}
	y = -1;
	while (++y < data->map->height)
		maps[y] = ft_strdup(data->map->maps[y]);
	return (0);
}

void	flood_fill(char **maps, int x, int y, t_data *data)
{
	if (x < 0 || y < 0 || x > data->map->width
		|| y > data->map->height)
		return ;
	if (maps[y][x] == 'f')
		return ;
	if (maps[y][x] != '1')
		maps[y][x] = 'f';
	flood_fill(maps, x + 1, y, data);
	flood_fill(maps, x - 1, y, data);
	flood_fill(maps, x, y + 1, data);
	flood_fill(maps, x, y - 1, data);
}
