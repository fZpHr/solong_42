/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_files_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelle <hbelle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:23:36 by hbelle            #+#    #+#             */
/*   Updated: 2023/12/20 17:02:08 by hbelle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

int	check_map_files(t_game *g)
{
	g->fd = open("map.ber", O_RDONLY);
	g->line = get_next_line(g->fd);
	if (g->line == NULL || g->line[0] == '\0')
	{
		ft_printf("Error\nCheck your map\n");
		free(g->line);
		close(g->fd);
		return (0);
	}
	else
	{
		free(g->line);
		close(g->fd);
		return (1);
	}
}
