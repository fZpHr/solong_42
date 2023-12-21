/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelle <hbelle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:00:02 by hbelle            #+#    #+#             */
/*   Updated: 2023/12/20 12:59:17 by hbelle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
}

void	render(t_game *g, int i)
{
	if (g->k > 4)
		g->k = 0;
	if (i != 0)
		render_sprite(g, i);
}
