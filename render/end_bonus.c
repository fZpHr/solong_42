/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelle <hbelle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:59:40 by hbelle            #+#    #+#             */
/*   Updated: 2023/12/20 14:24:34 by hbelle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

void	player_sprites_loop(t_game *g)
{
	g->i = 0;
	while (g->i < 4)
	{
		g->j = 0;
		while (g->j < 5)
			mlx_destroy_image(g->mlx_ptr, g->player_sprites[g->i][g->j++]);
		g->i++;
	}
}

void	enemy_sprites_loop(t_game *g)
{
	g->i = 0;
	while (g->i < 2)
	{
		g->j = 0;
		while (g->j < 6)
			mlx_destroy_image(g->mlx_ptr, g->enemy_sprites[g->i][g->j++]);
		g->i++;
	}
}

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
	enemy_sprites_loop(g);
	player_sprites_loop(g);
	mlx_destroy_window(g->mlx_ptr, g->win_ptr);
	mlx_destroy_display(g->mlx_ptr);
	free(g->mlx_ptr);
	exit (0);
}
