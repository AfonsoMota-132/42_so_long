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

#ifndef SO_LONG_H
# define SO_LONG_H

//		Includes	//

# include <stdlib.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>
# include "../libs/mlx/mlx.h"
# include "../libs/libft/libft.h"
# include <stdio.h>

# define SIZE 64

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
void	count_collect(t_data *data);

//			Render		//
int		render_map(t_data *data);

//		Map Checker		//
int		is_rectanlge(t_data *data);
int		map_checker(t_data *data);
int		flood(t_data *data);
void	flood_fill(char **maps, t_data *data, int x, int y);
int		flood_check(char **maps, t_data *data);

//		Key_hooks		//

int		key_hook(int keycode, t_data *data);

//		Free Game		//

int		ft_free(t_data *data);

//		Player Mov		//

int		move_up(t_data *data);
int		move_left(t_data *data);
int		move_down(t_data *data);
int		move_right(t_data *data);

#endif
