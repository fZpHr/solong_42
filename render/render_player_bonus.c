/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelle <hbelle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:00:02 by hbelle            #+#    #+#             */
/*   Updated: 2023/12/20 14:25:02 by hbelle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

void	render_waitportal(t_game *g)
{
	map_render_reload(g);
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr,
		g->waitportal, g->img_player_x, g->img_player_y);
	g->k++;
}

void	render_player_sprite(t_game *g, int sprite_index)
{
	map_render_reload(g);
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr,
		g->player_sprites[sprite_index][g->k],
		g->img_player_x, g->img_player_y);
	g->k++;
}

void	render_sprite(t_game *g, int i)
{
	if (g->check_en == 1)
	{
		if (g->img_player_y == g->img_enemy_y
			&& g->img_player_x == g->img_enemy_x)
			g->player_life--;
		if (g->player_life <= 0)
		{
			ft_printf("Game Over\n");
			free_end(g);
		}
	}
	if (g->map_tab[g->img_player_y / 90][g->img_player_x / 90] == 'E')
		render_waitportal(g);
	else if (i == 1)
		render_player_sprite(g, 1);
	else if (i == 2)
		render_player_sprite(g, 0);
	else if (i == 3)
		render_player_sprite(g, 3);
	else if (i == 4)
		render_player_sprite(g, 2);
	if (g->check_en == 1)
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr,
			g->enemy_sprites[0][0], g->img_enemy_x, g->img_enemy_y);
}

void	render(t_game *g, int i, int key)
{
	if (key >= 65361 && key <= 65364 && g->check_en)
		render_enemy(g, i);
	else
	{
		if (g->k > 4)
			g->k = 0;
		if (i != 0)
			render_sprite(g, i);
	}
}
