/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelle <hbelle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:00:27 by hbelle            #+#    #+#             */
/*   Updated: 2023/12/20 17:03:28 by hbelle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

void	handle_input_exit(t_game *g)
{
	ft_printf("Nombre de mouvement: %d\n", g->count_step);
	free_end(g);
}

void	handle_input_movement(t_game *g, int direction, int key)
{
	g->eop = 1;
	if (check_limit_map(g, direction, g->img_player_y, g->img_player_x) == 1)
	{
		if (direction == 1)
			g->img_player_y -= g->step;
		else if (direction == 2)
			g->img_player_y += g->step;
		else if (direction == 3)
			g->img_player_x -= g->step;
		else if (direction == 4)
			g->img_player_x += g->step;
		g->count_step++;
	}
	render(g, direction, key);
}

void	handle_input_movement_enemy(t_game *g, int direction, int key)
{
	g->eop = 0;
	if (check_limit_map(g, direction, g->img_enemy_y, g->img_enemy_x) == 1)
	{
		if (direction == 1)
			g->img_enemy_y -= g->step;
		else if (direction == 2)
			g->img_enemy_y += g->step;
		else if (direction == 3)
			g->img_enemy_x -= g->step;
		else if (direction == 4)
			g->img_enemy_x += g->step;
	}
	render(g, direction, key);
}

int	handle_input(int key, t_game *g)
{
	if (key == 65307)
		handle_input_exit(g);
	else if (key == 'w')
		handle_input_movement(g, 1, key);
	else if (key == 's')
		handle_input_movement(g, 2, key);
	else if (key == 'a')
		handle_input_movement(g, 3, key);
	else if (key == 'd')
		handle_input_movement(g, 4, key);
	else if (key == 65362 && g->check_en == 1)
		handle_input_movement_enemy(g, 1, key);
	else if (key == 65364 && g->check_en == 1)
		handle_input_movement_enemy(g, 2, key);
	else if (key == 65361 && g->check_en == 1)
		handle_input_movement_enemy(g, 3, key);
	else if (key == 65363 && g->check_en == 1)
		handle_input_movement_enemy(g, 4, key);
	render(g, 0, key);
	return (0);
}
