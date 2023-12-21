/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_into_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelle <hbelle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:59:54 by hbelle            #+#    #+#             */
/*   Updated: 2023/12/20 16:25:37 by hbelle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	count_xy(t_game *g)
{
	int	i;

	g->fd = open("map.ber", O_RDONLY);
	g->line = get_next_line(g->fd);
	g->count_x = 0;
	g->count_y = 0;
	i = 0;
	while (g->line)
	{
		while (g->line[i])
		{
			g->count_x++;
			i++;
		}
		g->count_y++;
		free(g->line);
		g->line = get_next_line(g->fd);
		i = 0;
	}
	free(g->line);
	close (g->fd);
	g->count_x /= g->count_y;
}

void	fill_array(t_game *g)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	g->fd = open("map.ber", O_RDONLY);
	while (j < g->count_y)
	{
		g->line = get_next_line(g->fd);
		while (g->line[i])
		{
			g->map_tab[j][i] = g->line[i];
			i++;
		}
		g->map_tab[j][i] = '\0';
		i = 0;
		free(g->line);
		j++;
	}
	close(g->fd);
}

void	map_into_array(t_game *g)
{
	int	i;

	i = 0;
	g->map_tab = (char **)malloc(sizeof(char *) * g->count_y);
	while (i < g->count_y)
	{
		g->map_tab[i] = (char *)malloc(sizeof(char *) * g->count_x + 1);
		if (!g->map_tab[i])
		{
			while (i >= 0)
			{
				free(g->map_tab[i]);
				i--;
			}
			return ;
		}
		i++;
	}
	fill_array(g);
}
