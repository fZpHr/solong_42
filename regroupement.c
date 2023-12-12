
#include "mlx/mlx.h"
#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*background;
	void	*wall;
	void	*floor;
	void	*object;
	void	*door;
	void	*player_sprites[5][5];
	char	**map_tab;
	int		img_x;
	int		img_y;
	int		img_player_x;
	int		img_player_y;
	int		current_image;
	int		window_width;
	int		window_height;
	int		count_step;
	int		width;
	int		j;
	int		height;
	int		step;
	char	*line;
	char	*wait;
	int		count_x;
	int		count_y;
	int		count_c;
	int		c;
	int		fd;
}	t_game;

void	fill_tab(t_game *g, int i)
{
	int	j;

	j = 0;
	g->line = get_next_line(g->fd);
	while (g->line[j])
	{
		g->map_tab[i][j] = g->line[j];
		j++;
	}
}

void	map_into_tab(t_game *g)
{
	int	i;

	i = 0;
	g->fd = open("map.ber", O_RDONLY);
	g->map_tab = (char **)malloc(sizeof(char *) * g->count_y);
	while (i < g->count_y)
	{
		g->map_tab[i] = (char *)malloc(sizeof(char *) * g->count_x);
		if (!g->map_tab[i])
		{
			while (i > 0)
			{
				free(g->map_tab[i]);
				i--;
			}
			return ;
		}
		fill_tab(g, i);
		i++;
	}
	close(g->fd);
}


void	map_render_reload(t_game *g)
{
	int	i;
	int	j;

	g->img_y = 0;
	g->img_x += 0;
	j = 0;
	while (j < g->count_y)
	{
		i = 0;
	    while(g->map_tab[j][i])
	    {
	    	if (g->map_tab[j][i] == '1')
				mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->wall, g->img_x, g->img_y);
			else if (g->map_tab[j][i] == '0')
				mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->floor, g->img_x, g->img_y);
			else if (g->map_tab[j][i] == 'C')
				mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->object, g->img_x, g->img_y);
			else if (g->map_tab[j][i] == 'E')
				mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->door, g->img_x, g->img_y);
			else if (g->map_tab[j][i] == 'P')
				mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->floor, g->img_x, g->img_y);
			mlx_string_put(g->mlx_ptr, g->win_ptr, 100, 100, 0x0FF000, ft_itoa(g->count_step));			
			g->img_x += 90;
			i++;
		}
		g->img_y += 90;
		g->img_x = 0;
		j++;
	}
}

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
		g->line = get_next_line(g->fd);
		i = 0;
	}
	close (g->fd);
	g->count_x /= g->count_y;
}

void	map_render(t_game *g)
{
	int	i;

	g->fd = open("map.ber", O_RDONLY);
	g->line = get_next_line(g->fd);
	i = 0;
	while (g->line)
	{
	    while(g->line[i])
	    {
	    	if (g->line[i] == '1')
			{
				mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->wall, g->img_x, g->img_y);
				g->img_x += 90;
			}
			else if (g->line[i] == '0')
			{
				mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->floor, g->img_x, g->img_y);
				g->img_x += 90;
			}
			else if (g->line[i] == 'C')
			{
				mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->object, g->img_x, g->img_y);
				g->img_x += 90;
				g->count_c++;
			}
			else if (g->line[i] == 'E')
			{
				mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->door, g->img_x, g->img_y);
				g->img_x += 90;
			}
			else if (g->line[i] == 'P')
			{
				mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->wait, g->img_x, g->img_y);
				g->img_player_x = g->img_x;
				g->img_player_y = g->img_y;
				g->img_x += 90;
			}
			i++;
		}
		//mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->wall, g->img_x, g->img_y);
		g->img_y += 90;
		g->img_x = 0;
		g->line = get_next_line(g->fd);
		i = 0;
	}
	close (g->fd);
}

void render(t_game *g, int i)
{
	if (g->j > 4)
		g->j = 0;
	if (i != 0)
	{
		if (i == 1)
		{
			map_render_reload(g);
			mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->player_sprites[1][g->j], g->img_player_x, g->img_player_y);
			g->j++;
		}
		else if(i == 2)
		{
				map_render_reload(g);
				mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->player_sprites[0][g->j], g->img_player_x, g->img_player_y);
				g->j++;
		}
		else if(i == 3)
		{
				map_render_reload(g);
				mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->player_sprites[3][g->j], g->img_player_x, g->img_player_y);
				g->j++;
		}
		else if(i == 4)
		{
			map_render_reload(g);
			mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->player_sprites[2][g->j], g->img_player_x, g->img_player_y);
			g->j++;
		}
	}
}
int	check_limit_map(t_game *g, int a)
{
	if (a == 1)
	{
		if (g->map_tab[(g->img_player_y - 90) / 90][g->img_player_x / 90] == '1')
			return (0);
		else if (g->map_tab[(g->img_player_y - 90) / 90][g->img_player_x / 90] == 'C')
		{
			g->map_tab[(g->img_player_y - 90) / 90][g->img_player_x / 90] = '0';
			g->c++;
		}
		else if (g->map_tab[(g->img_player_y - 90) / 90][g->img_player_x / 90] == 'E' && g->count_c == g->c)
		{
			mlx_destroy_window(g->mlx_ptr, g->win_ptr);
			exit (0);
		}
	}
	else if (a == 2)
	{
		if (g->map_tab[(g->img_player_y + 90) / 90][g->img_player_x / 90] == '1')
			return (0);
		else if (g->map_tab[(g->img_player_y + 90) / 90][g->img_player_x / 90] == 'C')
		{
			g->map_tab[(g->img_player_y + 90) / 90][g->img_player_x / 90] = '0';
			g->c++;
		}
		else if (g->map_tab[(g->img_player_y + 90) / 90][g->img_player_x / 90] == 'E' && g->count_c == g->c)
		{
			mlx_destroy_window(g->mlx_ptr, g->win_ptr);
			exit (0);
		}
	}
	else if (a == 3)
	{
		if (g->map_tab[g->img_player_y / 90][(g->img_player_x - 90) / 90] == '1')
			return (0);
		else if (g->map_tab[g->img_player_y / 90][(g->img_player_x - 90) / 90] == 'C')
		{
			g->map_tab[g->img_player_y / 90][(g->img_player_x - 90) / 90] = '0';
			g->c++;
		}
		else if (g->map_tab[g->img_player_y / 90][(g->img_player_x - 90) / 90] == 'E' && g->count_c == g->c)
		{
			mlx_destroy_window(g->mlx_ptr, g->win_ptr);
			exit (0);
		}
	}
	else if (a == 4)
	{
		if (g->map_tab[g->img_player_y / 90][(g->img_player_x + 90) / 90] == '1')
			return (0);
		else if (g->map_tab[g->img_player_y / 90][(g->img_player_x + 90) / 90] == 'C')
		{
			g->map_tab[g->img_player_y / 90][(g->img_player_x + 90) / 90] = '0';
			g->c++;
		}
		else if (g->map_tab[g->img_player_y / 90][(g->img_player_x + 90) / 90] == 'E' && g->count_c == g->c)
		{
			mlx_destroy_window(g->mlx_ptr, g->win_ptr);
			exit (0);
		}
	}
	return (1);
}

int	handle_input(int key, t_game *g)
{
	if (key == 'w')
	{
		if (check_limit_map(g, 1) == 1)
		{
			g->img_player_y -= g->step;
			g->count_step++;
		}
		render(g, 1);	
	}
	else if (key == 's')
	{
		if (check_limit_map(g, 2) == 1)
		{
			g->img_player_y += g->step;
			g->count_step++;
		}
		render(g, 2);
	}
	else if (key == 'a')
	{
		if (check_limit_map(g, 3) == 1)
		{
			g->img_player_x -= g->step;
			g->count_step++;
		}
		render(g, 3);
	}
	else if (key == 'd')
	{
		if (check_limit_map(g, 4) == 1)
		{
			g->img_player_x += g->step;
			g->count_step++;
		}
		render(g, 4);
	}
	render(g, 0);
	return (0);
}

int	close_window(t_game *g)
{
	mlx_destroy_window(g->mlx_ptr, g->win_ptr);
	exit (0);
}

int main() 
{
	t_game	g;

	g.c = 0;
	g.count_c = 0;
	g.j = 0;
	g.step = 90;
	g.img_player_y = 180;
	g.img_player_x = 180;
	g.img_x = 0;
	g.img_y = 0;
	g.count_step = 0;
	count_xy(&g);
	g.count_x--;
	g.window_width = 90 * g.count_x;
	g.window_height = 90 * g.count_y;
	g.mlx_ptr = mlx_init();
	g.door = mlx_xpm_file_to_image(g.mlx_ptr, "./image/door_02.xpm", &g.width, &g.height);
	g.object = mlx_xpm_file_to_image(g.mlx_ptr, "./image/effect_w.xpm", &g.width, &g.height);
	g.win_ptr = mlx_new_window(g.mlx_ptr, g.window_width, g.window_height, "Moving Player");
	g.floor = mlx_xpm_file_to_image(g.mlx_ptr, "./image/floor.xpm", &g.width, &g.height);
	g.wall = mlx_xpm_file_to_image(g.mlx_ptr, "./image/wall_04.xpm", &g.width, &g.height);
	g.wait = mlx_xpm_file_to_image(g.mlx_ptr, "./image/chara/char_idle_0.xpm", &g.width, &g.height);
	map_render(&g);
	map_into_tab(&g);
    mlx_string_put(g.mlx_ptr, g.win_ptr, 100, 100, 0x0FF000, ft_itoa(g.count_step));
	g.player_sprites[0][0] = mlx_xpm_file_to_image(g.mlx_ptr, "./image/chara/char_run_down_0.xpm", &g.width, &g.height);
	g.player_sprites[0][1] = mlx_xpm_file_to_image(g.mlx_ptr, "./image/chara/char_run_down_1.xpm", &g.width, &g.height);
	g.player_sprites[0][2] = mlx_xpm_file_to_image(g.mlx_ptr, "./image/chara/char_run_down_2.xpm", &g.width, &g.height);
	g.player_sprites[0][3] = mlx_xpm_file_to_image(g.mlx_ptr, "./image/chara/char_run_down_3.xpm", &g.width, &g.height);
	g.player_sprites[0][4] = mlx_xpm_file_to_image(g.mlx_ptr, "./image/chara/char_run_down_4.xpm", &g.width, &g.height);

	g.player_sprites[1][0] = mlx_xpm_file_to_image(g.mlx_ptr, "./image/chara/char_run_up_0.xpm", &g.width, &g.height);
	g.player_sprites[1][1] = mlx_xpm_file_to_image(g.mlx_ptr, "./image/chara/char_run_up_1.xpm", &g.width, &g.height);
	g.player_sprites[1][2] = mlx_xpm_file_to_image(g.mlx_ptr, "./image/chara/char_run_up_2.xpm", &g.width, &g.height);
	g.player_sprites[1][3] = mlx_xpm_file_to_image(g.mlx_ptr, "./image/chara/char_run_up_3.xpm", &g.width, &g.height);
	g.player_sprites[1][4] = mlx_xpm_file_to_image(g.mlx_ptr, "./image/chara/char_run_up_4.xpm", &g.width, &g.height);
	
	g.player_sprites[2][0] = mlx_xpm_file_to_image(g.mlx_ptr, "./image/chara/char_run_right_0.xpm", &g.width, &g.height);
	g.player_sprites[2][1] = mlx_xpm_file_to_image(g.mlx_ptr, "./image/chara/char_run_right_1.xpm", &g.width, &g.height);
	g.player_sprites[2][2] = mlx_xpm_file_to_image(g.mlx_ptr, "./image/chara/char_run_right_2.xpm", &g.width, &g.height);
	g.player_sprites[2][3] = mlx_xpm_file_to_image(g.mlx_ptr, "./image/chara/char_run_right_3.xpm", &g.width, &g.height);
	g.player_sprites[2][4] = mlx_xpm_file_to_image(g.mlx_ptr, "./image/chara/char_run_right_4.xpm", &g.width, &g.height);

	g.player_sprites[3][0] = mlx_xpm_file_to_image(g.mlx_ptr, "./image/chara/char_run_left_0.xpm", &g.width, &g.height);
	g.player_sprites[3][1] = mlx_xpm_file_to_image(g.mlx_ptr, "./image/chara/char_run_left_1.xpm", &g.width, &g.height);
	g.player_sprites[3][2] = mlx_xpm_file_to_image(g.mlx_ptr, "./image/chara/char_run_left_2.xpm", &g.width, &g.height);
	g.player_sprites[3][3] = mlx_xpm_file_to_image(g.mlx_ptr, "./image/chara/char_run_left_3.xpm", &g.width, &g.height);
	g.player_sprites[3][4] = mlx_xpm_file_to_image(g.mlx_ptr, "./image/chara/char_run_left_4.xpm", &g.width, &g.height);
	
    mlx_put_image_to_window(g.mlx_ptr, g.win_ptr, g.player_sprites[0][0], g.img_player_x, g.img_player_y);

	mlx_hook(g.win_ptr, 17, 1L << 17, close_window, &g);
	mlx_key_hook(g.win_ptr, handle_input, &g);
	
    mlx_loop(g.mlx_ptr);

    return 0;
}

