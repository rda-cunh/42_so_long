/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 00:02:52 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/10/22 19:55:04 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void    launch_mlx(t_game *game)
{
    game->display.mlx = mlx_init();
    if (!game->display.mlx)
        exit_error(game, "Error\nFailed to initialize MinilibX\n");
    game->display.win = mlx_new_window(game->display.mlx, game->map->width * SIZE_TL, game->map->height * SIZE_TL, "So Long");
    if (!game->display.win)
        exit_error(game, "Error\nFailed to create window.\n");
}

void    render_map(t_game *game)
{
    unsigned int    x;
    unsigned int    y;
    void            *grass_img;
    void            *water_img; 
    void            *egg_img;
    void            *exit_img;
    void            *player_img; 

    launch_mlx(game);

    //loading sprites into memory (evalute create a struct for them)
    grass_img = mlx_xpm_file_to_image(game->display.mlx, GRASS_TL, &SIZE_TL, &SIZE_TL);
    water_img = mlx_xpm_file_to_image(game->display.mlx, WATER_TL, &SIZE_TL, &SIZE_TL);
    egg_img = mlx_xpm_file_to_image(game->display.mlx, EGG_TL, &SIZE_TL, &SIZE_TL);
    exit_img = mlx_xpm_file_to_image(game->display.mlx, EXIT_TL, &SIZE_TL, &SIZE_TL);
    player_img = mlx_xpm_file_to_image(game->display.mlx, PLAYER_TL, &SIZE_TL, &SIZE_TL);

    y = 0; 
    while (y < game->map->height)
    {
        x = 0;
        while (x < game->map->width)
        {
            if (game->map->grid[y][x] == GRASS)
                mlx_put_image_to_window((game->display.mlx, game->display.win, GRASS_TL, x * SIZE_TL, y * SIZE_TL));
            else if (game->map->grid[y][x] == WATER)
                mlx_put_image_to_window((game->display.mlx, game->display.win, WATER_TL, x * SIZE_TL, y * SIZE_TL));
            else if (game->map->grid[y][x] == EGG)
                mlx_put_image_to_window((game->display.mlx, game->display.win, EGG_TL, x * SIZE_TL, y * SIZE_TL));
            else if (game->map->grid[y][x] == EXIT)
                mlx_put_image_to_window((game->display.mlx, game->display.win, EXIT_TL, x * SIZE_TL, y * SIZE_TL));
            else if (game->map->grid[y][x] == PLAYER)
                mlx_put_image_to_window((game->display.mlx, game->display.win, PLAYER_TL, x * SIZE_TL, y * SIZE_TL));
            x++;
        }
        y++;
    }

    //keep the window open to hanle events
    mlx_loop(game->display.mlx); 
}
