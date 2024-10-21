/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 22:29:30 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/10/20 22:46:28 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

//print map size and map grid
void	print_map(t_game *so_long)
{
	unsigned int	j;

	j = 0;
	ft_printf("Map size: %d x %d\n", so_long->map->width, so_long->map->height);
	while (j < so_long->map->height)
	{
		ft_printf("%s", so_long->map->grid[j]);
		j++;
	}
	ft_printf("\n");
}

//verifies map filename
bool	check_file(char *file)
{
	size_t	len;

	len = ft_strlen(file);
	if (len <= 4 || !ft_strnstr((file + len - 4), ".ber", 4))
		return (false);
	else
		return (true); 
}