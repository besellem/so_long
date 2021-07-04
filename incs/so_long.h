/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 19:56:20 by besellem          #+#    #+#             */
/*   Updated: 2021/07/04 00:45:29 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/*
** -- INCLUDES --
*/
# include <libft.h>
# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <stdint.h>
# include <fcntl.h>
# include <time.h>

/*
** -- DEFINES --
*/
# define ERR "\033[1;31mError\033[0m"
# define MAP_CHARSET "01CEP"

# define SYSCALL_ERR    (-1)

# define DIR_NORTH      0
# define DIR_SOUTH      1
# define DIR_EAST       2
# define DIR_WEST       3

/*
** Key mapping for macOS & Linux envs
*/
# if defined(__APPLE__) && defined(__MACH__)
#  define ENV_MSG       "\033[1;32m[macOS environment]\033[0m"
#  define SOUND_CMD     "afplay"
#  define KEY_ESC       53
#  define KEY_W         13
#  define KEY_A         0
#  define KEY_S         1
#  define KEY_D         2
#  define EVT_RED_CROSS 17
# else
#  define ENV_MSG       "\033[1;32m[Linux environment]\033[0m"
#  define SOUND_CMD     "aplay"
#  define KEY_ESC       65307
#  define KEY_W         119
#  define KEY_A         97
#  define KEY_S         115
#  define KEY_D         100
#  define EVT_RED_CROSS 33
# endif

/*
** Bonus Macros
** Defined at compile time if wanted / needed
*/
# ifndef BONUS
#  define BONUS 0
# endif

enum	e_textures
{
	TXTR_WALL,
	TXTR_EMPTY,
	TXTR_COLLECTIBLE,
	TXTR_EXIT,
	TXTR_PLAYER,
	__TXTR_MAX__
};

/*
** x:			width of the texture (in pixels)
** y:			height of the texture (in pixels)
** size_line:	number of bytes used to store one line of the image in memory
** bpp:			number of bits needed to represent a pixel color
*/
typedef struct s_img
{
	int		x;
	int		y;
	int		size_line;
	int		bpp;
	int		endian;
	void	*ptr;
	char	*addr;
}				t_img;

typedef struct s_sounds
{
	clock_t	sound_time;
	clock_t	sprite_last_hit_time;
}				t_sounds;

/*
** win_w:			resolution width (if > screen, is truncated)
** win_h:			resolution height (if > screen, is truncated)
** cub_size:		size of a cube in pixels (for the minimap only)
** map:				map[row][column]
** map_size_x:		horizontal size of the map
** map_size_y:		vertical size of the map
** mlx:				pointer created by mlx_init()
** win:				pointer of the window
** pos_x:			player position horizontally
** pos_y:			player position vertically
** img:				image to print out
** txtrs:			all the textures and their specs
*/
typedef struct s_so_long
{
	int			win_w;
	int			win_h;
	int			cub_size;
	char		**map;
	int			map_size_x;
	int			map_size_y;
	void		*mlx;
	void		*win;
	int			pos_x;
	int			pos_y;
	int			collectibles;
	size_t		move_nbr;
	t_img		img;
	t_img		txtrs[__TXTR_MAX__];
}				t_so_long;

/*
** -- PROTOTYPES --
** Common
*/
void			print_map(t_so_long *sl);
int				ft_save(t_so_long *sl);

/*
** Others
*/
int				is_extension(const char *file, const char *extension);
void			ft_free_all(t_so_long *sl);

/*
** Parser & Checkers
*/
int				ft_parse(t_so_long *sl, char *path);
int				parse_map(t_so_long *sl, const char *path);

/*
** Events
*/
int				handle_key_press(int key, t_so_long *sl);
int				handle_key_release(int key, t_so_long *sl);
void			ft_error(char *err, t_so_long *sl, char *file, int line);
void			ft_quit(t_so_long *sl);
int				ft_red_cross(t_so_long *sl);

/*
** Engine & Display
*/
void			ft_pixel_put(t_so_long *sl, int x, int y, uint32_t color);
void			update_frame(t_so_long *sl);
int				engine_loop(t_so_long *sl);

/*
** Bonus
*/
void			init_bonus(t_so_long *sl);
void			display_minimap(t_so_long *sl);

#endif
