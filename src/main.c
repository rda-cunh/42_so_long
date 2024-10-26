/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:05:52 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/10/26 00:26:07 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

//initialise all game main components
void	start_game(char *file)
{
	t_game	so_long;

	ft_bzero(&so_long, sizeof(t_game));
	read_map(&so_long, file);
	print_map(&so_long);
	check_map(&so_long);
	launch_mlx(&so_long);
	load_images(&so_long);
	render_map(&so_long);
	mlx_hook(so_long.display.win, 17, 1L << 17, end_game, &so_long);
	mlx_hook(so_long.display.win, 02, 1L << 0, handle_keypress, &so_long);
	mlx_loop(so_long.display.mlx);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		exit_error(NULL, "Error\nInvalid number of arguments.\n");
	if (check_filename(argv[1]))
		exit_error(NULL, "Error\nInvalid filename.\n");
	start_game(argv[1]);
	return (0);
}
