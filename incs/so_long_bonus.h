/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afogonca <afogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 12:03:56 by afogonca          #+#    #+#             */
/*   Updated: 2024/11/10 12:07:48 by afogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

//		Includes	//

# include <stdlib.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>
# include "../libs/mlx/mlx.h"
# include "../libs/libft/libft.h"
# include <stdio.h>

# define SIZE 128

typedef struct s_player
{
	int	x;
	int	y;
	int	collect;
	int	moves;
	int	to_x;
	int	to_y;
}	t_player;

typedef struct s_map
{
	int		height;
	int		width;
	char	**maps;
}	t_map;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		**tiles;
	t_map		*map;
	t_player	*player;
	int			exit;
	int			tile_size;
	int			collect;
}	t_data;

//		Functions		//

//		Initialize		//
void	init_pull(t_data *data);
t_data	*data_init(void);

//			Map			//

int		map_loader(t_data *data, char *av);
int		count_collect(t_data *data);

//			Render		//
int		render_map(t_data *data);

//		Map Checker		//
int		file_check(char *av);
int		is_rectanlge(t_data *data);
int		map_checker(t_data *data);
int		flood(t_data *data);
void	flood_fill(char **maps, t_data *data, int x, int y);
int		flood_check(char **maps, t_data *data);
int		has_other(t_data *data);

//		Key_hooks		//
int		key_hook(int keycode, t_data *data);
int		ft_kill(t_data *data);

//		Free Game		//

int		ft_free(t_data *data);
void	ft_free_arr(char **maps, t_data *data);

//		Player Mov		//

void	move2(t_data *data, int d);
int		move_left_right(t_data *data, int side);
int		move_down_up(t_data *data, int side);

#endif
