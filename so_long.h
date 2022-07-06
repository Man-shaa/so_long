/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 14:32:07 by msharifi          #+#    #+#             */
/*   Updated: 2022/07/06 21:10:52 by msharifi         ###   ########.fr       */
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

# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 300

# define MLX_ERROR 1

# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0xFF00
# define WHITE_PIXEL 0xFFFFFF

#  define LEFT_KEY				65361
#  define RIGHT_KEY				65363
#  define UP_KEY				65362
#  define DOWN_KEY				65364
#  define A_KEY					97
#  define W_KEY					119
#  define S_KEY					115
#  define D_KEY					100
#  define ESC					65307

typedef struct s_image
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_image;

typedef struct s_rect
{
	int	x;
	int	y;
	int width;
	int height;
	int color;
}	t_rect;

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

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_image	img;
	t_map	map;
}	t_data;

// keypress.c
int		handle_keypress(int keysym, t_data *data);

// map.c
void	free_map(char **map);
int		line_count(char *access_path);
void	fill_map(t_data *data);
void	initialise_map(char *path, t_data *data);
void	create_map(char *path, t_data *data);

// parsing_map.c
int		is_rect(t_data *data);
int		is_btw_walls(t_data *data);
void 	select_incrementation(char c, t_data *data);
int		is_valid(int row, int column, t_data *data);
int		parsing(t_data *data);

// render.c
void	img_pix_put(t_image *img, int x, int y, int color);
int 	render_rect(t_image *img, t_rect rect);
void	render_background(t_image *img, int color);
int		render(t_data *data);

// utils.c
void	free_map(char **map);
void	ft_bzero(void *tab, size_t n);
void	*ft_calloc(size_t nelem, size_t size);

#endif
