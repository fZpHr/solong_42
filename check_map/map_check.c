/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:00:54 by hbelle            #+#    #+#             */
/*   Updated: 2023/12/18 17:00:56 by hbelle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	resolver_map(t_game *g, int x, int y)
{
	if (y < 0 || y >= g->count_y || x < 0 || x >= g->count_x
		|| g->map_tab[y][x] == '1' || g->map_tab[y][x] == 'V')
		return ;
	if (g->map_tab[y][x] == 'C')
		g->check_c++;
	if (g->map_tab[y][x] == 'E')
		g->check_e++;
	g->map_tab[y][x] = 'V';
	resolver_map(g, x + 1, y);
	resolver_map(g, x - 1, y);
	resolver_map(g, x, y + 1);
	resolver_map(g, x, y - 1);
}

int	check_map(t_game *g)
{
	if (g->count_y == g->count_x)
		return (0);
	resolver_map(g, (g->img_player_x / 90), (g->img_player_y / 90));
	if (g->check_c == g->count_c && g->check_e > 0 && g->check_c > 0)
		return (1);
	return (0);
}

int	check_wall(t_game *g)
{
	g->i = 0;
	g->j = 0;
	while (g->i < g->count_x)
	{
		if (g->map_tab[0][g->i] != '1')
			return (0);
		if (g->map_tab[g->count_y - 1][g->i] != '1')
			return (0);
		g->i++;
	}
	g->i = 0;
	while (g->i < g->count_y)
	{
		while (g->map_tab[g->i][g->j])
			g->j++;
		if (g->j != g->count_x + 1)
			return (0);
		if (g->map_tab[g->i][0] != '1')
			return (0);
		if (g->map_tab[g->i][g->count_x - 1] != '1')
			return (0);
		g->i++;
		g->j = 0;
	}
	return (1);
}
