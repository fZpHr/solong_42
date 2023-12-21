/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelle <hbelle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:59:48 by hbelle            #+#    #+#             */
/*   Updated: 2023/12/20 12:55:31 by hbelle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_player_sprites_down_and_up(t_game *g)
{
	g->player_sprites[0][0] = mlx_xpm_file_to_image(g->mlx_ptr,
			"./image/chara/char_run_down_0.xpm", &g->width, &g->height);
	g->player_sprites[0][1] = mlx_xpm_file_to_image(g->mlx_ptr,
			"./image/chara/char_run_down_1.xpm", &g->width, &g->height);
	g->player_sprites[0][2] = mlx_xpm_file_to_image(g->mlx_ptr,
			"./image/chara/char_run_down_2.xpm", &g->width, &g->height);
	g->player_sprites[0][3] = mlx_xpm_file_to_image(g->mlx_ptr,
			"./image/chara/char_run_down_3.xpm", &g->width, &g->height);
	g->player_sprites[0][4] = mlx_xpm_file_to_image(g->mlx_ptr,
			"./image/chara/char_run_down_4.xpm", &g->width, &g->height);
	g->player_sprites[1][0] = mlx_xpm_file_to_image(g->mlx_ptr,
			"./image/chara/char_run_up_0.xpm", &g->width, &g->height);
	g->player_sprites[1][1] = mlx_xpm_file_to_image(g->mlx_ptr,
			"./image/chara/char_run_up_1.xpm", &g->width, &g->height);
	g->player_sprites[1][2] = mlx_xpm_file_to_image(g->mlx_ptr,
			"./image/chara/char_run_up_2.xpm", &g->width, &g->height);
	g->player_sprites[1][3] = mlx_xpm_file_to_image(g->mlx_ptr,
			"./image/chara/char_run_up_3.xpm", &g->width, &g->height);
	g->player_sprites[1][4] = mlx_xpm_file_to_image(g->mlx_ptr,
			"./image/chara/char_run_up_4.xpm", &g->width, &g->height);
}

void	load_player_sprites_left_and_right(t_game *g)
{
	g->player_sprites[2][0] = mlx_xpm_file_to_image(g->mlx_ptr,
			"./image/chara/char_run_right_0.xpm", &g->width, &g->height);
	g->player_sprites[2][1] = mlx_xpm_file_to_image(g->mlx_ptr,
			"./image/chara/char_run_right_1.xpm", &g->width, &g->height);
	g->player_sprites[2][2] = mlx_xpm_file_to_image(g->mlx_ptr,
			"./image/chara/char_run_right_2.xpm", &g->width, &g->height);
	g->player_sprites[2][3] = mlx_xpm_file_to_image(g->mlx_ptr,
			"./image/chara/char_run_right_3.xpm", &g->width, &g->height);
	g->player_sprites[2][4] = mlx_xpm_file_to_image(g->mlx_ptr,
			"./image/chara/char_run_right_4.xpm", &g->width, &g->height);
	g->player_sprites[3][0] = mlx_xpm_file_to_image(g->mlx_ptr,
			"./image/chara/char_run_left_0.xpm", &g->width, &g->height);
	g->player_sprites[3][1] = mlx_xpm_file_to_image(g->mlx_ptr,
			"./image/chara/char_run_left_1.xpm", &g->width, &g->height);
	g->player_sprites[3][2] = mlx_xpm_file_to_image(g->mlx_ptr,
			"./image/chara/char_run_left_2.xpm", &g->width, &g->height);
	g->player_sprites[3][3] = mlx_xpm_file_to_image(g->mlx_ptr,
			"./image/chara/char_run_left_3.xpm", &g->width, &g->height);
	g->player_sprites[3][4] = mlx_xpm_file_to_image(g->mlx_ptr,
			"./image/chara/char_run_left_4.xpm", &g->width, &g->height);
}
