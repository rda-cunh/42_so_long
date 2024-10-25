/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 01:31:50 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/10/25 13:55:41 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

//checks for valid move (next position is not the same and is not WATER)
int	check_move(t_game *so_long)
{
	return (!is_same_point(so_long->curr, so_long->next) \
		&& get_object(so_long, so_long->next) != WATER);
}

//helper funtion for the move_player funtion above and keep it under 25 lines
static void	handle_exit(t_game *so_long)
{
	if (so_long->map->eggs == 0)
	{
		ft_printf("You reached the exit after collecting all eggs!\n");
		end_game(so_long);
	}
	else
		ft_printf("You need to collect all the eggs before exiting!\n");
}

//move the player
void	move_player(t_game *so_long)
{
	char	next_tile;

	if (check_move(so_long))
	{
		next_tile = get_object(so_long, so_long->next);
		if (next_tile == EGG)
		{
			so_long->map->eggs--;
			if (so_long->map->eggs == 0)
				ft_printf("All eggs colected!\n");
		}
		if (next_tile == EXIT)
			return (handle_exit(so_long));
		so_long->map->grid[so_long->curr.y][so_long->curr.x] = GRASS;
		so_long->map->grid[so_long->next.y][so_long->next.x] = PLAYER;
		so_long->curr = so_long->next;
		so_long->map->moves++;
		ft_printf("Moves: %d\n", so_long->map->moves);
		render_map(so_long);
	}
}

//handles keypress and updates next postition
int	handle_keypress(int keycode, t_game *so_long)
{
	if (keycode == KEY_ESC)
		end_game(so_long);
	else if (keycode == KEY_W || keycode == KEY_UP)
		so_long->next = (t_point){so_long->curr.x, so_long->curr.y - 1};
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		so_long->next = (t_point){so_long->curr.x, so_long->curr.y + 1};
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		so_long->next = (t_point){so_long->curr.x - 1, so_long->curr.y};
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		so_long->next = (t_point){so_long->curr.x + 1, so_long->curr.y};
	move_player(so_long);
	return (0);
}
