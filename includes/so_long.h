/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelle <hbelle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:08:41 by hbelle            #+#    #+#             */
/*   Updated: 2023/12/20 12:01:16 by hbelle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include "../mlx/mlx.h"
# include "ft_printf.h"
# include <fcntl.h>

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*background;
	void	*wall;
	void	*floor;
	void	*object;
	void	*door;
	void	*player_sprites[4][5];
	void	*enemy_sprites[2][6];
	char	**map_tab;
	int		enemy_direction;
	int		patrol_range;
	int		img_x;
	int		img_y;
	int		img_player_x;
	int		img_enemy_x;
	int		img_player_y;
	int		img_enemy_y;
	int		current_image;
	int		window_width;
	int		window_height;
	int		count_step;
	int		width;
	int		j;
	int		k;
	int		i;
	int		height;
	int		step;
	char	*line;
	char	*wait;
	char	*waitportal;
	int		count_x;
	int		count_y;
	int		count_c;
	int		count_e;
	int		check_en;
	int		check_c;
	int		check_p;
	int		player_life;
	int		check_e;
	int		count_p;
	char	*count_step_str;
	int		c;
	int		fd;
	int		eop;
	int		count;
}	t_game;

int		map_render(t_game *g);
char	*ft_itoa(int n);
int		check_limit_map(t_game *g, int a, int y, int x);
int		free_end(t_game *g);
void	render(t_game *g, int i);
void	map_render_reload(t_game *g);
void	count_xy(t_game *g);
void	load_player_sprites_down_and_up(t_game *g);
void	load_player_sprites_left_and_right(t_game *g);
int		handle_input(int key, t_game *g);
void	map_into_array(t_game *g);
void	fill_array(t_game *g);
int		check_map(t_game *g);
int		check_wall(t_game *g);
char	*itoa_step(t_game *g);
int		check_map_files(t_game *g);

#endif
