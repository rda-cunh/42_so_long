/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:05:52 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/10/23 11:17:11 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	start_game(char *file)
{
	t_game	so_long;

	ft_bzero(&so_long, sizeof(t_game)); 
	read_map(&so_long, file); //map reading and store it as 2D array
	print_map(&so_long); //prints map size and map grid
	check_map(&so_long); //check map walls and object count
	launch_mlx(&so_long);
	load_images(&so_long);
	render_map(&so_long); // initialize mlx and render map
	mlx_hook(so_long.display.win, 17, 1L << 17, end_game, &so_long);  // 17 is the event for window close
	mlx_hook(so_long.display.win, 02, 1L << 0, handle_keypress, &so_long); //02 is the event for keypress
	mlx_loop_hook(so_long.display.mlx, render_after_move, &so_long); 
	mlx_loop(so_long.display.mlx);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		exit_error(NULL, "Error\nInvalid number of arguments.\n");
	if (check_filename(argv[1])) // check filename extension;
		exit_error(NULL, "Error\nInvalid filename.\n");
	start_game(argv[1]); // starting the game with the map file
	return (0);
}