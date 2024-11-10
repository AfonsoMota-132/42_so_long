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

	if (ac == 2)
	{
		data = data_init();
		if (!data)
			return (0);
		map_loader(data, av[1]);
		idk = map_checker(data);
		if (idk == 1)
			return (0);
		if (!data->map->height)
			return(0);
		data->win =	mlx_new_window(data->mlx, (data->map->width * 100), (data->map->height * 100), "So long");
		render_map(data);
		mlx_loop(data->mlx);
	}
}
