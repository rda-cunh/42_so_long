/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:01:46 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/10/14 11:07:35 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h> //used for file control and opening files (maps)
# include <stdlib.h> //memory allocation and program termination (exit)
# include <unistd.h> //functions like read and close
# include <mlx.h> //MiniliX graphic library

//struct to store minilibx image information 
typedef struct	s_data 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void    start_game(char *file);

char    **read_map(char *file);
int     get_file_height(char *file); 

#endif
