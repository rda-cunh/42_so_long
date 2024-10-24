/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:01:46 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/10/24 01:51:45 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h> //used for file control and opening files (maps)
# include <stdlib.h> //memory allocation and program termination (exit)
# include <unistd.h> //functions like read and close
# include "../minilibx-linux/mlx.h" //MiniliX graphic library
# include "../libft/libft.h" //libft

//macro to define objects
# define GRASS	'0'
# define WATER	'1'
# define EGG	'C'
# define EXIT	'E'
# define PLAYER	'P'

//sprites info and location
# define SIZE_TL	64
# define TILES		"01CEP"
# define GRASS_TL	"assets/sprites/0.xpm"
# define WATER_TL	"assets/sprites/1.xpm"
# define EGG_TL		"assets/sprites/c.xpm"
# define EXIT_TL	"assets/sprites/e.xpm"
# define PLAYER_TL	"assets/sprites/p.xpm"

//pressed keys 
#define KEY_ESC		65307
#define KEY_W		119
#define KEY_A		97
#define KEY_S		115
#define KEY_D		100
#define KEY_UP		65362
#define KEY_DOWN	65364
#define KEY_LEFT	65361
#define KEY_RIGHT	65363

//store sprite info
typedef struct s_sprite
{
	void	*img;
	int		height;
	int		width;
}			t_sprite;

//struct to store minilibx information 
typedef struct s_graphics
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
}				t_graphics;

//store player position
typedef struct s_point
{
	unsigned int	x;
	unsigned int	y;
}				t_point;

//struct to store map info
typedef struct s_map
{
	char			**grid;
	unsigned int	height;
	unsigned int	width;
	unsigned int	players;
	t_point			player;
	unsigned int	eggs;
	unsigned int	exit;
	unsigned int	moves;
}				t_map;

//struct to store game info
typedef struct s_game
{
	t_map		*map;
	t_graphics	display;
	t_point		curr;
	t_point		next;
	t_sprite	grass;
	t_sprite	water;
	t_sprite	egg;
	t_sprite	exit;
	t_sprite	player;
}				t_game;

//main.c
void	start_game(char *file);

//create_map.c
t_map	*create_map(unsigned int width, unsigned int height);
int		get_file_height(t_game *so_long, char *file);
void	read_map(t_game *so_long, char *file);

//check_map.c
void	check_walls(t_game *so_long);
void	count_map_objects(t_game *so_long);
void	verify_map_objects(t_game *so_long);
void	check_map(t_game *so_long);

//render_map.c
void	launch_mlx(t_game *game);
void	load_images(t_game *game);
void	render_map(t_game *game);

//movement.c
int		check_move(t_game *so_long);
void	move_player(t_game *so_long);
int		handle_keypress(int keycode, t_game *so_long);

//exit.c
void	clean_map(t_map *map);
void	clean_sprites(t_game *so_long)
void	clean_game(t_game *so_long);
int		exit_error(t_game *so_long, char *msg);
int		end_game(t_game *so_long);

//utils.c
int		check_filename(char *file);
int		is_same_point(t_point a, t_point b);
char	get_object(t_game *so_long, t_point point);
void	print_map(t_game *so_long);

#endif
