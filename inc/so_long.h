/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:01:46 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/10/22 01:18:03 by rda-cunh         ###   ########.fr       */
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
# define GRASS_TL	"assets/sprites/0.xpm"
# define WATER_TL	"assets/sprites/1.xpm"
# define EGG_TL		"assets/sprites/c.xpm"
# define EXIT_TL	"assets/sprites/e.xpm"
# define PLAYER_TL	"assets/sprites/p.xpm"

//struct to store minilibx information 
typedef struct s_graphics
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_graphics;

//struct to store map info
typedef struct s_map
{
	char			**grid;
	unsigned int	height;
	unsigned int	width;
}				t_map;

//struct to store game info
typedef struct s_game
{
	t_map		*map;
	t_graphics	display;
}				t_game;


void	start_game(char *file);

void	read_map(t_game *so_long, char *file);
int		get_file_height(t_game *so_long, char *file);
t_map	*create_map(unsigned int width, unsigned int height);

void	launch_mlx(t_game *game);
void	render_map(t_game *game);

void	clean_map(t_map *map);

void	print_map(t_game *so_long);
bool	check_filename(char *file);

//void	clean_map(char **map, int map_height);

#endif
