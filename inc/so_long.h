/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:01:46 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/10/20 23:17:38 by rda-cunh         ###   ########.fr       */
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

//struct to store minilibx image information 
typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

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
	t_map	*map;
}				t_game;


void	start_game(char *file);

void	read_map(t_game *so_long, char *file);
int		get_file_height(t_game *so_long, char *file);
t_map	*create_map(unsigned int width, unsigned int height);

void	clean_map(t_map *map);

void	print_map(t_game *so_long);

//void	clean_map(char **map, int map_height);

#endif
