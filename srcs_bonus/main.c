/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afogonca <afogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:41:51 by afogonca          #+#    #+#             */
/*   Updated: 2024/11/10 13:47:30 by afogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long_bonus.h"

void	move2(t_data *data, int d)
{
	/*char	*str;*/

	mlx_put_image_to_window(data->mlx, data->win, data->tiles[0],
		(data->player->x * SIZE), (data->player->y * SIZE));
	mlx_put_image_to_window(data->mlx, data->win, data->tiles[d],
		(data->player->to_x * SIZE), (data->player->to_y * SIZE));
	data->player->x = data->player->to_x;
	data->player->y = data->player->to_y;
	data->player->moves++;
	/*str = ft_itoa(data->player->moves);*/
	/*mlx_put_image_to_window(data->mlx, data->win, data->tiles[7],*/
	/*	(data->map->width / 2) * SIZE, (data->map->height - 1) * SIZE);*/
	/*mlx_string_put(data->mlx, data->win, (data->map->width / 2) * SIZE,*/
	/*	(data->map->height * SIZE) - 50, 0x000000, "moves");*/
	/*mlx_string_put(data->mlx, data->win, ((data->map->width / 2) * SIZE) + 100,*/
	/*	(data->map->height * SIZE) - 50, 0x000000, str);*/
}

int	check_dir(char *av)
{
	int	fd;

	fd = open(av, O_DIRECTORY);
	if (fd < 0)
		return (0);
	else
	{
		ft_printf("Map sent is a directory!\n");
		exit (0);
	}
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac == 2 && check_dir(av[1]) == 0 && file_check(av[1]) == 0)
	{
		data = data_init();
		if (!data)
			return (0);
		if (map_loader(data, av[1]) > 0)
			return (ft_free(data));
		if (map_checker(data) > 0)
			return (ft_free(data));
		data->win = mlx_new_window(data->mlx, (data->map->width * SIZE),
				(data->map->height * SIZE), "So long");
		render_map(data);
		count_collect(data);
		mlx_hook(data->win, KeyPress, KeyPressMask, &key_hook, data);
		mlx_hook(data->win, DestroyNotify, StructureNotifyMask, &ft_kill, data);
		mlx_loop(data->mlx);
	}
	else if (ac != 2)
		ft_printf("No map input!\n");
	else
		ft_printf("Invalid file!\n");
}
