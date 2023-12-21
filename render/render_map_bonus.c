/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelle <hbelle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:46:47 by hbelle            #+#    #+#             */
/*   Updated: 2023/12/20 16:58:33 by hbelle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

void	render_wall_or_floor_or_door(t_game *g)
{
	if (g->line[g->i] == '1')
	{
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->wall,
			g->img_x, g->img_y);
		g->img_x += 90;
	}
	if (g->line[g->i] == '0')
	{
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->floor,
			g->img_x, g->img_y);
		g->img_x += 90;
	}
	if (g->line[g->i] == 'E')
	{
		g->count_e++;
		if (g->count_e > 1)
		{
			ft_printf("Error\nToo many doors\n");
			free_end(g);
		}
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr,
			g->door, g->img_x, g->img_y);
		g->img_x += 90;
	}
}

void	render_object_or_enemy(t_game *g)
{
	if (g->line[g->i] == 'C')
	{
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr,
			g->object, g->img_x, g->img_y);
		g->img_x += 90;
		g->count_c++;
	}
	else if (g->line[g->i] == 'N')
	{
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr,
			g->enemy_sprites[0][0], g->img_x, g->img_y);
		g->img_enemy_x = g->img_x;
		g->img_enemy_y = g->img_y;
		g->img_x += 90;
		g->check_en++;
	}
}

void	render_player(t_game *g)
{
	g->count_p++;
	if (g->count_p > 1)
	{
		ft_printf("Error\nToo many players\n");
		free_end(g);
	}
	if (g->count_p == 1)
	{
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr,
			g->wait, g->img_x, g->img_y);
		g->img_player_x = g->img_x;
		g->img_player_y = g->img_y;
		g->img_x += 90;
	}
	else
	{
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr,
			g->floor, g->img_x, g->img_y);
		g->img_x += 90;
	}
}

int	render_loop(t_game *g)
{
	while (g->line[g->i])
	{
		if (g->line[g->i] == '1' || g->line[g->i] == '0'
			|| g->line[g->i] == 'E')
			render_wall_or_floor_or_door(g);
		else if (g->line[g->i] == 'C' || g->line[g->i] == 'N')
			render_object_or_enemy(g);
		else if (g->line[g->i] == 'P')
			render_player(g);
		else if (g->line[g->i] == '\n')
			;
		else
		{
			free(g->line);
			close(g->fd);
			return (0);
		}
		g->i++;
	}
	return (1);
}

int	map_render(t_game *g)
{
	g->fd = open("map.ber", O_RDONLY);
	g->line = get_next_line(g->fd);
	g->i = 0;
	while (g->line)
	{
		if (render_loop(g) == (0))
			return (0);
		g->img_y += 90;
		g->img_x = 0;
		free(g->line);
		g->line = get_next_line(g->fd);
		g->i = 0;
	}
	free(g->line);
	close(g->fd);
	return (1);
}
