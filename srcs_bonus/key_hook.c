/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afogonca <afogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 09:27:30 by afogonca          #+#    #+#             */
/*   Updated: 2024/11/11 09:30:10 by afogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long_bonus.h"

int	ft_kill(t_data *data)
{
	ft_free(data);
	exit (0);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 65307 || keycode == 120 || keycode == -714992848)
	{
		ft_free(data);
		exit (0);
	}
	else if (keycode == 65362 || keycode == 119)
		move_down_up(data, 0);
	else if (keycode == 65361 || keycode == 97)
		move_left_right(data, 0);
	else if (keycode == 65364 || keycode == 115)
		move_down_up(data, 1);
	else if (keycode == 65363 || keycode == 100)
		move_left_right(data, 1);
	return (0);
}
