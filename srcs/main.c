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

int	main(int ac, char **av)
{
	t_data	*data;
	int		idk;

	if (ac == 2 && file_check(av[1]) == 0)
	{
		data = data_init();
		if (!data)
			return (0);
		if (map_loader(data, av[1]) == 1)
			return (ft_free(data));
		if (map_checker(data) > 0)
			return (ft_free(data));
		data->win = mlx_new_window(data->mlx, (data->map->width * SIZE),
				(data->map->height * SIZE), "So long");
		render_map(data);
		count_collect(data);
		mlx_hook(data->win, KeyPress, KeyPressMask, &key_hook, data);
		mlx_loop(data->mlx);
	}
}
