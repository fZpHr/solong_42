/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_enemy_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelle <hbelle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:51:14 by hbelle            #+#    #+#             */
/*   Updated: 2023/12/20 14:24:55 by hbelle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

void	render_enemy_sprite(t_game *g, int sprite_index)
{
	map_render_reload(g);
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr,
		g->enemy_sprites[sprite_index][g->k],
		g->img_enemy_x, g->img_enemy_y);
	g->k++;
}

void	render_sprite_enemy(t_game *g, int i)
{
	if (g->img_player_y == g->img_enemy_y && g->img_player_x == g->img_enemy_x)
		g->player_life--;
	if (g->player_life <= 0)
	{
		ft_printf("Game Over\n");
		free_end(g);
	}
	if (i == 1)
		render_enemy_sprite(g, 1);
	else if (i == 2)
		render_enemy_sprite(g, 0);
	else if (i == 3)
		render_enemy_sprite(g, 0);
	else if (i == 4)
		render_enemy_sprite(g, 1);
}

void	render_enemy(t_game *g, int i)
{
	if (g->k > 5)
		g->k = 0;
	if (i != 0)
		render_sprite_enemy(g, i);
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr,
		g->wait, g->img_player_x, g->img_player_y);
}
