/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:36:42 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/10/24 01:26:47 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	clean_map(t_map *map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	if (!map->grid)
		return ;
	while (map->grid[i])
	{
		free (map->grid[i]);
		i++;
	}
	free (map->grid);
	free (map);
}

void	clean_game(t_game *so_long)
{
	if (!so_long)
		return ;
	if (so_long->map)
		clean_map(so_long->map); 
	//see what else must be set here, like cleaning sprites, mlx, mlx window, etc.
}

//exit functior: prints message and cleans map
int	exit_error(t_game *so_long, char *msg)
{
	clean_game(so_long);
	ft_printf("%s", msg);
	exit (EXIT_FAILURE);
}

int	end_game(t_game *so_long)
{
	clean_game(so_long);
	exit(EXIT_SUCCESS);
}
