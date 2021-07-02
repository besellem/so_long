/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 19:56:20 by besellem          #+#    #+#             */
/*   Updated: 2021/03/14 00:52:28 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

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
# define BMP_FILEPATH "./saved.bmp"
# define CUB_ERR "\033[1;31mError\033[0m"
# define MAP_CHARSET " 012NEWS"
# define DRXIONS "NSEW"
# define TEXTURES_COUNT 5

/*
** Get the 4 cardinal values within a circle:
**
**             N (PI / 2)
**             |
**             |
** W (PI) ----   ---- E (0.0)
**             |
**             |
**             S (PI + (PI / 2) OR (3 * PI) / 2)
**
** But y-> is inverted, so NORTH & SOUTH positions must be inverted too
*/

# define DRXION_E 0.0
# define DRXION_N T_3PI_2
# define DRXION_W T_PI
# define DRXION_S T_PI_2

# define HIT_NORTH 0
# define HIT_SOUTH 1
# define HIT_EAST 2
# define HIT_WEST 3

/*
** FOV (field of view) in radians
*/
# define FOV T_PI_2

/*
** Some colors (for minimap)
*/
# define UCOLOR_GREY 0xE0E0E0U
# define UCOLOR_BLACK 0x0U

/*
** Key mapping for macOS & Linux envs
*/
# if defined(__APPLE__) && defined(__MACH__)
#  define ENV_MSG "\033[1;32m[macOS environment]\033[0m"
#  define SOUND_CMD "afplay"
#  define KEY_ESC 53
#  define KEY_LEFT 123
#  define KEY_RIGHT 124
#  define KEY_W 13
#  define KEY_A 0
#  define KEY_S 1
#  define KEY_D 2
#  define KEY_F 3
#  define EVT_RED_CROSS 17
# else
#  define ENV_MSG "\033[1;32m[Linux (default) environment]\033[0m"
#  define SOUND_CMD "aplay"
#  define KEY_ESC 65307
#  define KEY_LEFT 65361
#  define KEY_RIGHT 65363
#  define KEY_W 119
#  define KEY_A 97
#  define KEY_S 115
#  define KEY_D 100
#  define KEY_F 102
#  define EVT_RED_CROSS 33
# endif

/*
** Bonus Macros
** Defined at compile time if wanted / needed
*/
# define GUN_GIF_NB 5
# ifndef BONUS
#  define BONUS 0
# endif

/*
** -- TYPEDEFS & STRUCTURES --
**
** is_down:			is the angle pointing up or down (0 or 1)
** is_right:		is the angle pointing left or right (0 or 1)
** hit_vertical:	check if the ray is vertical or horizontal (1 or 0)
** hit_drxion:		from where the ray hit a wall. Macros NORTH, SOUTH, ...
** angle:			angle of the ray in radians
** tan_ngl:			tan(angle): instead of doing it ~4 times a bit later
** distortion:		cos(ray->angle - cub->drxion): instead of doing it ~2 times
** xintcpt:			next cube from cub->pos_x
** yintcpt:			next cube from cub->pos_y
** xstep:			increment with xstep to check if we hit something
** ystep:			increment with ystep to check if we hit something
** distance:		distance from the player to a wall for that angle
** cmp_distance:	distance used for comparisons (does not use sqrt())
** hit_wall_x:		coordinate x of the wall hit
** hit_wall_y:		coordinate y of the wall hit
** sp_ray:			contains a ray of all the sprites combined & sorted
*/
typedef struct	s_ray
{
	int			is_down : 2;
	int			is_right : 2;
	int			hit_vertical : 2;
	int			hit_drxion : 4;
	int			can_kill_sp : 2;
	double		angle;
	double		tan_ngl;
	double		distortion;
	double		xintcpt;
	double		yintcpt;
	double		xstep;
	double		ystep;
	double		distance;
	double		cmp_distance;
	double		hit_wall_x;
	double		hit_wall_y;
	uint32_t	*sp_ray;
}				t_ray;

/*
** hit:				if it was hit or not
** x:				index x in cub->map
** y:				index y in cub->map
** distance:		distance from the player
** centre_angle:	angle of the center of the sprite (calculated with atan())
*/
typedef	struct	s_sprite
{
	int		hit : 2;
	int		x;
	int		y;
	double	distance;
	double	centre_angle;
}				t_sprite;

/*
** order:	vertical stripe before or after an horizontal one (0 or 1)
*/
typedef	struct	s_spcasting_vars
{
	int		order;
	int		horz_sp;
	int		vert_sp;
	int		horz_printable;
	int		vert_printable;
	double	dist_horz;
	double	dist_vert;
}				t_spcasting_vars;

/*
** *_x:		tmp - used in raycasting calculations
** *_y:		tmp - used in raycasting calculations
** horz:	horizontal ray (already casted when this variable is used)
** vert:	vertical ray (already casted when this variable is used)
*/

typedef	struct	s_raycasting
{
	double	vert_x;
	double	vert_y;
	double	horz_x;
	double	horz_y;
	t_ray	*horz;
	t_ray	*vert;
}				t_raycasting;

typedef struct	s_keys
{
	int key_w : 2;
	int key_s : 2;
	int key_a : 2;
	int key_d : 2;
	int key_left : 2;
	int key_right : 2;
}				t_keys;

/*
** x:			width of the texture (in pixels)
** y:			height of the texture (in pixels)
** size_line:	number of bytes used to store one line of the image in memory
** bpp:			number of bits needed to represent a pixel color
*/
typedef struct	s_img
{
	int		x;
	int		y;
	int		size_line;
	int		bpp;
	int		endian;
	void	*ptr;
	char	*addr;
}				t_img;

typedef	struct	s_gun
{
	int		gun_is_printable : 2;
	int		gun_status;
	int		gun_frames;
	time_t	last_time;
}				t_gun;

typedef	struct	s_sounds
{
	clock_t sound_time;
	clock_t sprite_last_hit_time;
}				t_sounds;

/*
** save_opt:		check if the option '--save' is defined
** life:			between 0 and 100
** win_w:			resolution width (if > screen, is truncated)
** win_h:			resolution height (if > screen, is truncated)
** parsed_w:		resolution width from the .cub file
** parsed_h:		resolution height from the .cub file
** sky_color:		sky color
** grnd_color:		ground color
** sprites_ocs:		sprites occurrences in the map
** kill_sprite:		is the gun shooting or not ?
** dw:				(key press): none (0), left (-1), right (1)
** dh:				(key press): none (0), down (-1), up (1)
** turn:			(key press): none (0), left angle (-1), right angle (1)
** cub_size:		size of a cube in pixels (for the minimap only)
** txtr_no:			path to the north texture file
** txtr_so:			path to the south texture file
** txtr_ea:			path to the east texture file
** txtr_we:			path to the west texture file
** txtr_s:			path to the sprite texture file
** map:				map[row][column]
** map_size_x:		horizontal size of the map
** map_size_y:		vertical size of the map
** mlx:				pointer created by mlx_init()
** win:				pointer of the window
** drxion:			direction of the player in radians
** pos_x:			player position horizontally
** pos_y:			player position vertically
** increment:		player's speed
** keys:			keys struct
** img:				image to print out
** txtrs:			all the textures and their specs
** txtr_gun:		gun textures ("frames")
** txtr_life:		life texture
** rays:			re-calculated each frame
** sprites:			sprites infos
** gun:				gun status (to get the corresponding texture)
*/
typedef	struct	s_cub
{
	int			save_opt : 2;
	int8_t		life;
	int			win_w;
	int			win_h;
	int			parsed_w;
	int			parsed_h;
	int32_t		sky_color;
	int32_t		grnd_color;
	int			sprites_ocs;
	int			kill_sprite;
	int			dw;
	int			dh;
	int			turn;
	int			cub_size;
	char		*txtr_no;
	char		*txtr_so;
	char		*txtr_ea;
	char		*txtr_we;
	char		*txtr_s;
	char		**map;
	size_t		map_size_x;
	size_t		map_size_y;
	void		*mlx;
	void		*win;
	double		drxion;
	double		pos_x;
	double		pos_y;
	double		increment;
	t_sounds	sounds;
	t_keys		keys;
	t_img		img;
	t_img		txtrs[TEXTURES_COUNT];
	t_img		txtr_gun[GUN_GIF_NB];
	t_img		txtr_target;
	t_img		txtr_life;
	t_ray		*rays;
	t_sprite	*sprites;
	t_gun		gun;
}				t_cub;

/*
** -- PROTOTYPES --
** Common
*/
void			print_specs(t_cub *cub);
void			print_map(t_cub *cub);
int				ft_save(t_cub *cub);

/*
** Others
*/
double			ft_deg2rad(int deg);
double			ft_rad2deg(double rad);
double			ft_norm_angle(double angle);
int				file_got_ext(char *file, char *extension);
int				in_charset(char *charset, int c);
int				charset_in_line(char *line, char *charset);
int				in_map_limits(t_cub *cub, double x, double y);
int				is_sprite(int c);
int				ft_strs_size(char **strs);
void			*ft_ternary(int condition, void *if_true, void *if_false);
void			ft_free_cub(t_cub *cub);
int				ft_free_strs(char **strs);
double			ft_pythagore(double x1, double y1, double x2, double y2);
double			ft_pyt_like(double x1, double y1, double x2, double y2);
double			get_dec(double n);
int				safe_min(double nb1, double nb2);
int				check_rgb(char *s);
int32_t			ft_rgb(uint8_t r, uint8_t g, uint8_t b);
int				is_rgb(int color);

/*
** Parser & Checkers
*/
void			init_cub(t_cub *cub);
void			cub_parser(int ac, char **av, t_cub *cub);
int				alloc_sprite_rays(t_cub *cub);
void			cub_fill_specs(int fd, t_cub *cub);
int				are_specs_complete(t_cub *cub);
void			map_parser(int fd, t_cub *cub);
int				map_checker(t_cub *cub);
int				map_validator(t_cub *cub);
void			fill_texture(t_cub *cub, t_img *tx, char *path);

/*
** Events
*/
int				handle_key_press(int key, t_cub *cub);
int				handle_key_release(int key, t_cub *cub);
void			ft_error(char *err, t_cub *cub, char *file, int line);
void			ft_quit(t_cub *cub);
int				ft_red_cross(t_cub *cub);

/*
** Raycasting
*/
int				get_sprite_idx(t_cub *cub, int x, int y);
void			init_sprites_hit(t_cub *cub);
void			init_sprites_rays(t_cub *cub);
void			init_ray(t_cub *cub, t_ray *ray, double angle, int is_vertical);
void			wall_intersect(t_cub *cub, t_ray *ray, double x, double y);
void			sprite_intersect(t_cub *cub, t_ray *ray, double x, double y);
void			sprites_raycasting(t_cub *cub, t_raycasting *cast,
									t_ray *valid_ray);
void			cast_all_rays(t_cub *cub);

/*
** Engine & Display
*/
void			ft_pixel_put(t_cub *cub, int x, int y, uint32_t color);
void			update_cubs(t_cub *cub);
void			update_frame(t_cub *cub);
int				engine_loop(t_cub *cub);

/*
** Bonus
*/
void			init_bonus(t_cub *cub);
void			play_global_music(t_cub *cub);
void			display_minimap(t_cub *cub);
void			display_life(t_cub *cub);
void			display_gun(t_cub *cub);

#endif
