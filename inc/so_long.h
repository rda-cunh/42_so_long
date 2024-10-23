/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:01:46 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/10/23 01:28:23 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h> //used for file control and opening files (maps)
# include <stdlib.h> //memory allocation and program termination (exit)
# include <unistd.h> //functions like read and close
# include <stdbool.h> //deals with bolean data
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

//keys 
# define KEY_ESC 	53
# define KEY_W		13
# define KEY_A 		0
# define KEY_S 		1
# define KEY_D 		2
# define KEY_UP 	126
# define KEY_DOWN 	125
# define KEY_LEFT 	123
# define KEY_RIGHT	124

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


void	start_game(char *file);

void	read_map(t_game *so_long, char *file);
int		get_file_height(t_game *so_long, char *file);
t_map	*create_map(unsigned int width, unsigned int height);

void	check_map(t_game *so_long);
void	check_walls(t_game *so_long);
void	count_map_objects(t_game *so_long);
void	verify_map_objects(t_game *so_long);

void	launch_mlx(t_game *game);
void	load_images(t_game *game);
void	render_map(t_game *game);

void	clean_map(t_map *map);
void	clean_game(t_game *so_long);

void	print_map(t_game *so_long);
bool	check_filename(char *file);
int		exit_error(t_game *so_long, char *msg);

#endif
