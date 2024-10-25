/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 23:06:42 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/10/25 01:48:37 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_map(t_game *so_long)
{
	check_shape(so_long);
	check_walls(so_long);
	count_map_objects(so_long);
	verify_map_objects(so_long);
    check_paths(so_long);
}
