/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afogonca <afogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:53:24 by afogonca          #+#    #+#             */
/*   Updated: 2024/11/10 13:53:26 by afogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

int	map_loader(t_data *data, char *av)
{
	int	fd;
	int	i;

	fd = open(av, O_RDONLY);
	if (fd < 0)
		return (1);
	while (get_next_line(fd) != NULL)
		data->map->height++;
	data->map->maps = malloc(sizeof(char *) * (data->map->height + 1));
	if (!data->map->maps)
		return (1);
	close (fd);

	fd = open(av, O_RDONLY);
	if (fd < 0)
		return (1);
	i = 0;
	while (i < data->map->height)
	{
		data->map->maps[i] = get_next_line(fd);
		i++;
	}
	i = 0;
	data->map->width = ft_strlen(data->map->maps[0]) - 1;
	return (0); 
}
