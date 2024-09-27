/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:05:52 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/09/27 18:36:45 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../inc/so_long.h"
#include <mlx.h> //to delete and include in header (just for testing)

int main(void)
{
    void    *mlx;
    void    *mlx_win;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello World"); 
    mlx_loop(mlx); 
//    if (!mlx)
//        return (1);
    

//    mlx_destroy_display(mlx);
//    free(mlx);
    return (0); 
}