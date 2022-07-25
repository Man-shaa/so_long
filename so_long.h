/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 14:32:07 by msharifi          #+#    #+#             */
/*   Updated: 2022/07/25 19:02:08 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "mlx/mlx.h"
# include "mlx/mlx_int.h"
# include "GNL/get_next_line.h"

# define WINDOW_WIDTH	1600
# define WINDOW_HEIGHT	1000
# define IMG_SIZE		100
# define MLX_ERROR		1

# define GROUND			"Image/ground2.xpm"
# define PLAYER			"Image/player.xpm"
# define ITEM			"Image/item.xpm"
# define EXIT			"Image/exit.xpm"
# define WALL			"Image/wall.xpm"

# define RED_PIXEL		0xFF0000
# define GREEN_PIXEL	0xFF00
# define WHITE_PIXEL	0xFFFFFF

# define LEFT_KEY		65361
# define UP_KEY			65362
# define RIGHT_KEY		65363
# define DOWN_KEY		65364
# define A_KEY			97
# define W_KEY			119
# define S_KEY			115
# define D_KEY			100
# define ESC			65307

typedef struct s_image
{
	void	*mlx_img;
	int		width;
	int		height;
	void	*wall;
	void	*exit;
	void	*ground;
	void	*player;
	void	*item;
	int		line_length;

}	t_image;

typedef struct s_map
{
	int		fd;
	int		line_count;
	size_t	line_len;
	int		count_p;
	int		count_e;
	int		count_c;
	char	*path;
	char	**map;
	int		can_exit;
	int		collected;

}				t_map;

typedef struct s_player
{
	int		p_x;
	int		p_y;
	int		move_count;
}				t_player;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_image		img;
	t_map		map;
	t_player	player;
}	t_data;

// init_player.c
void	init_player_pos(t_data *data);

// keypress.c
int		handle_keypress(int keysym, t_data *data);
int		handle_btnrealease(t_data *data);

// map.c
void	free_map(char **map);
int		line_count(char *access_path);
void	fill_map(t_data *data);
int		initialise_map(char *path, t_data *data);
int		create_map(char *path, t_data *data);

// mlx_utils.c
int		init_window(t_data *data);
void	init_images(t_data *data);
void	loop_hook(t_data data);
void	destroy_images(t_data data);

// moves.c
int		check_next_tile(t_data *data, char direction, char tile);
void	check_item_next_tile(t_data *data, char direction);
int		end_game(t_data *data);
void	move_player(t_data *data, char direction);

// parsing_map.c
int		is_rect(t_data *data);
int		is_btw_walls(t_data *data, int i);
void	select_incrementation(char c, t_data *data);
int		is_valid(int row, int column, t_data *data);
int		parsing(t_data *data);

// render.c
void	init_images(t_data *data);
void	parse_chars(t_data *data, int width, int i, int j);
int		render(t_data *data);

// utils.c
void	ft_bzero(void *tab, size_t n);
void	*ft_calloc(size_t nelem, size_t size);
int		ft_strchr2(char *str, int c);

#endif
