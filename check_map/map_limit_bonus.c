/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_limit_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelle <hbelle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:00:59 by hbelle            #+#    #+#             */
/*   Updated: 2023/12/20 14:23:57 by hbelle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

int	check_limit_map_1(t_game *g, int y, int x)
{
	if (g->map_tab[(y - 90) / 90][x / 90] == '1')
		return (0);
	else if (g->map_tab[(y - 90) / 90][x / 90] == 'C' && g->eop == 1)
	{
		g->map_tab[(y - 90) / 90][x / 90] = '0';
		g->c++;
	}
	else if (g->map_tab[(y - 90) / 90][x / 90] == 'E'
		&& g->count_c == g->c && g->eop == 1)
	{
		ft_printf("Nombre de mouvement: %d\n ", g->count_step);
		free_end(g);
	}
	return (1);
}

int	check_limit_map_2(t_game *g, int y, int x)
{
	if (g->map_tab[(y + 90) / 90][x / 90] == '1')
		return (0);
	else if (g->map_tab[(y + 90) / 90][x / 90] == 'C' && g->eop == 1)
	{
		g->map_tab[(y + 90) / 90][x / 90] = '0';
		g->c++;
	}
	else if (g->map_tab[(y + 90) / 90][x / 90] == 'E'
		&& g->count_c == g->c && g->eop == 1)
	{
		ft_printf("Nombre de mouvement: %d\n", g->count_step);
		free_end(g);
	}
	return (1);
}

int	check_limit_map_3(t_game *g, int y, int x)
{
	if (g->map_tab[y / 90][(x - 90) / 90] == '1')
		return (0);
	else if (g->map_tab[y / 90][(x - 90) / 90] == 'C' && g->eop == 1)
	{
		g->map_tab[y / 90][(x - 90) / 90] = '0';
		g->c++;
	}
	else if (g->map_tab[y / 90][(x - 90) / 90] == 'E'
		&& g->count_c == g->c && g->eop == 1)
	{
		ft_printf("Nombre de mouvement: %d\n", g->count_step);
		free_end(g);
	}
	return (1);
}

int	check_limit_map_4(t_game *g, int y, int x)
{
	if (g->map_tab[y / 90][(x + 90) / 90] == '1')
		return (0);
	else if (g->map_tab[y / 90][(x + 90) / 90] == 'C' && g->eop == 1)
	{
		g->map_tab[y / 90][(x + 90) / 90] = '0';
		g->c++;
	}
	else if (g->map_tab[y / 90][(x + 90) / 90] == 'E'
		&& g->count_c == g->c && g->eop == 1)
	{
		ft_printf("Nombre de mouvement: %d\n", g->count_step);
		free_end(g);
	}
	return (1);
}

int	check_limit_map(t_game *g, int a, int y, int x)
{
	int	bol;

	bol = 0;
	if (a == 1)
		bol = check_limit_map_1(g, y, x);
	else if (a == 2)
		bol = check_limit_map_2(g, y, x);
	else if (a == 3)
		bol = check_limit_map_3(g, y, x);
	else if (a == 4)
		bol = check_limit_map_4(g, y, x);
	if (bol == 0)
		return (0);
	else
		return (1);
}
