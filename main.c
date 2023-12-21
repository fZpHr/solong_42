/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelle <hbelle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:58:08 by hbelle            #+#    #+#             */
/*   Updated: 2023/12/20 16:30:24 by hbelle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	init_game_variables(t_game *g)
{
	g->count_step_str = 0;
	g->count_p = 0;
	g->count_e = 0;
	g->check_c = 0;
	g->check_e = 0;
	g->check_p = 0;
	g->c = 0;
	g->count_c = 0;
	g->i = 0;
	g->k = 0;
	g->j = 0;
	g->step = 90;
	g->img_x = 0;
	g->img_y = 0;
	g->count_step = 0;
	if (check_map_files(g) == 0)
		exit (0);
	count_xy(g);
	g->count_x--;
	g->window_width = 90 * g->count_x;
	g->window_height = 90 * g->count_y;
}

void	load_images(t_game *g)
{
	g->door = mlx_xpm_file_to_image(g->mlx_ptr, "./image/door.xpm",
			&g->width, &g->height);
	g->object = mlx_xpm_file_to_image(g->mlx_ptr, "./image/item.xpm",
			&g->width, &g->height);
	g->win_ptr = mlx_new_window(g->mlx_ptr, g->window_width, g->window_height,
			"so_long");
	g->floor = mlx_xpm_file_to_image(g->mlx_ptr, "./image/floor.xpm",
			&g->width, &g->height);
	g->wall = mlx_xpm_file_to_image(g->mlx_ptr, "./image/wall.xpm",
			&g->width, &g->height);
	g->wait = mlx_xpm_file_to_image(g->mlx_ptr, "./image/chara/char_idle_0.xpm",
			&g->width, &g->height);
	g->waitportal = mlx_xpm_file_to_image(g->mlx_ptr,
			"./image/chara/char_idle_1.xpm", &g->width, &g->height);
}

void	load_player_sprites(t_game *g)
{
	load_player_sprites_down_and_up(g);
	load_player_sprites_left_and_right(g);
}

void	setup_game(t_game *g)
{
	mlx_hook(g->win_ptr, 17, 1L << 17, free_end, g);
	mlx_key_hook(g->win_ptr, handle_input, g);
	mlx_loop(g->mlx_ptr);
}

int	main(void)
{
	t_game	g;

	init_game_variables(&g);
	g.mlx_ptr = mlx_init();
	load_images(&g);
	load_player_sprites(&g);
	if (map_render(&g) == 0)
	{
		return (ft_printf("Error\nCheck your map\n"));
		free_end(&g);
	}
	map_into_array(&g);
	if (check_map(&g) == 0)
	{
		return (ft_printf("Error\nCheck your map\n"));
		free_end(&g);
	}
	fill_array(&g);
	if (check_wall(&g) == 0)
	{
		return (ft_printf("Error\nCheck your wall\n"));
		free_end(&g);
	}
	setup_game(&g);
	return (0);
}
