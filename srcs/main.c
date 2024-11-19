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

#include "../incs/so_long.h"
#include <X11/X.h>
#include <fcntl.h>

int	check_dir(char *av)
{
	int	fd;

	fd = open(av, O_DIRECTORY);
	if (fd < 0)
		return (0);
	else
	{
		ft_printf("Error\nMap sent is a directory!\n");
		exit (0);
	}
}

void	render_win(t_data *data)
{
	data->win = mlx_new_window(data->mlx, (data->map->width * SIZE),
			(data->map->height * SIZE), "So long");
	render_map(data);
	mlx_hook(data->win, KeyPress, KeyPressMask, &key_hook, data);
	mlx_hook(data->win, DestroyNotify, StructureNotifyMask, &ft_kill, data);
	mlx_loop(data->mlx);
}

int	check_ber(char *av)
{
	int	len;

	if (ft_strlen(av) <= 4)
		return (1);
	else
	{
		len = ft_strlen(av);
		if (av[len - 5] == '/')
			return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac == 2 && check_dir(av[1]) == 0
		&& file_check(av[1]) == 0 && check_ber(av[1]) == 0)
	{
		data = data_init();
		if (!data)
			return (0);
		if (map_loader(data, av[1]) > 0)
			return (ft_free(data));
		if (map_checker(data) > 0)
			return (ft_free(data));
		if (count_collect(data) == 1)
		{
			ft_printf("Error\nNo collectables.\n");
			return (ft_free(data));
		}
		render_win(data);
	}
	else if (ac != 2)
		ft_printf("Error\nNo map input!\n");
	else
		ft_printf("Error\nInvalid file!\n");
}
