/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelle <hbelle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:53:48 by hbelle            #+#    #+#             */
/*   Updated: 2023/12/20 16:19:51 by hbelle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	free_end(t_game *g)
{
	g->i = 0;
	if (g->map_tab)
		while (g->i < g->count_y)
			free(g->map_tab[g->i++]);
	free(g->map_tab);
	free(g->count_step_str);
	mlx_destroy_image(g->mlx_ptr, g->door);
	mlx_destroy_image(g->mlx_ptr, g->object);
	mlx_destroy_image(g->mlx_ptr, g->floor);
	mlx_destroy_image(g->mlx_ptr, g->wall);
	mlx_destroy_image(g->mlx_ptr, g->wait);
	mlx_destroy_image(g->mlx_ptr, g->waitportal);
	g->i = 0;
	while (g->i < 4)
	{
		g->j = 0;
		while (g->j < 5)
			mlx_destroy_image(g->mlx_ptr, g->player_sprites[g->i][g->j++]);
		g->i++;
	}
	mlx_destroy_window(g->mlx_ptr, g->win_ptr);
	mlx_destroy_display(g->mlx_ptr);
	free(g->mlx_ptr);
	exit (0);
}
