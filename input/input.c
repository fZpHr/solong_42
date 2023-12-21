/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelle <hbelle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:51:42 by hbelle            #+#    #+#             */
/*   Updated: 2023/12/20 13:02:40 by hbelle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	handle_input_exit(t_game *g)
{
	ft_printf("Nombre de mouvement: %d\n", g->count_step);
	free_end(g);
}

void	handle_input_movement(t_game *g, int direction)
{
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
	render(g, direction);
}

int	handle_input(int key, t_game *g)
{
	if (key == 65307)
	{
		handle_input_exit(g);
	}
	else if (key == 'w')
	{
		handle_input_movement(g, 1);
	}
	else if (key == 's')
	{
		handle_input_movement(g, 2);
	}
	else if (key == 'a')
	{
		handle_input_movement(g, 3);
	}
	else if (key == 'd')
	{
		handle_input_movement(g, 4);
	}
	render(g, 0);
	return (0);
}
