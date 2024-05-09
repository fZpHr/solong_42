/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_reload_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelle <hbelle@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:00:05 by hbelle            #+#    #+#             */
/*   Updated: 2024/05/10 00:56:42 by hbelle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

char	*itoa_step(t_game *g)
{
	if (g->count_step_str)
		free(g->count_step_str);
	g->count_step_str = ft_itoa(g->count_step);
	return (g->count_step_str);
}

void	loop_reload(t_game *g)
{
	while (g->map_tab[g->j][g->i])
	{
		if (g->map_tab[g->j][g->i] == '1')
			mlx_put_image_to_window(g->mlx_ptr, g->win_ptr,
				g->wall, g->img_x, g->img_y);
		else if (g->map_tab[g->j][g->i] == '0')
			mlx_put_image_to_window(g->mlx_ptr, g->win_ptr,
				g->floor, g->img_x, g->img_y);
		else if (g->map_tab[g->j][g->i] == 'C')
			mlx_put_image_to_window(g->mlx_ptr, g->win_ptr,
				g->object, g->img_x, g->img_y);
		else if (g->map_tab[g->j][g->i] == 'E')
			mlx_put_image_to_window(g->mlx_ptr, g->win_ptr,
				g->door, g->img_x, g->img_y);
		else if (g->map_tab[g->j][g->i] == 'N' && g->check_en == 1)
			mlx_put_image_to_window(g->mlx_ptr, g->win_ptr,
				g->floor, g->img_x, g->img_y);
		else if (g->map_tab[g->j][g->i] == 'P')
			mlx_put_image_to_window(g->mlx_ptr, g->win_ptr,
				g->floor, g->img_x, g->img_y);
		mlx_string_put(g->mlx_ptr, g->win_ptr, 45, 45, 0x0FF000,
			itoa_step(g));
		g->img_x += 90;
		g->i++;
	}
}

void	map_render_reload(t_game *g)
{
	g->img_y = 0;
	g->img_x += 0;
	g->j = 0;
	while (g->j < g->count_y)
	{
		g->i = 0;
		loop_reload(g);
		g->img_y += 90;
		g->img_x = 0;
		g->j++;
	}
	ft_printf("Nombre de mouvement: %d\n", g->count_step);
}
