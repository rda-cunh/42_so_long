/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 01:31:50 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/10/23 01:32:37 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"





int handle_keypress(int keycode, t_game *so_long)
{
    if (keycode == KEY_ESC)
        end_game(so_long);
    else if (keycode == KEY_W || keycode == KEY_UP)
        so_long->next = (t_point){so_long->curr.x}{so_long->curr.y - 1};
    else if (keycode == KEY_S || keycode == KEY_DOWN)
        so_long->next = (t_point){so_long->curr.x}{so_long->curr.y + 1};
    else if (keycode == KEY_A || keycode == KEY_LEFT)
        so_long->next = (t_point){so_long->curr.x - 1}{so_long->curr.y};
    else if (keycode == KEY_D || keycode == KEY_RIGHT)
        so_long->next = (t_point){so_long->curr.x + 1}{so_long->curr.y};
    return (keycode);        
}