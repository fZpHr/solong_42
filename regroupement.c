
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
	void	*player_sprites[5][5];
	char	**map_tab;
	int		img_x;
	int		img_y;
	int		img_player_x;
	int		img_player_y;
	int		j;
	int		current_image;
	int		window_width;
	int		window_height;
	int		width;
	int		height;
	int		step;
	char	*line;
	int		count_x;
	int		count_y;
	int		fd;
}	t_game;

void	fill_tab(t_game *g)
{
	int	i;

	i = 0;
	while (i < g->count_y)
	{
		g->map_tab[i] = g->line;
		g->map_tab[i][g->count_x + 1] = '\0';
		i++;
		get_next_line(g->fd);
	}
}

void	map_into_tab(t_game *g)
{
	int	i;

	i = 0;
	g->map_tab = (char **)malloc(sizeof(char *) * g->count_y + 1);
	while (i < g->count_y)
	{
		g->map_tab[i] = (char *)malloc(sizeof(char *) * g->count_x + 1);
		if (!g->map_tab[i])
		{
			while (i > 0)
			{
				free(g->map_tab[i]);
				i--;
			}
			return ;
		}
		i++;
	}
	fill_tab(g);
}
void	map_render_reload(t_game *g)
{
	int	i;
	int	j;
	
	j = 0;
	i = 0;
	while (g->map_tab[j] < g->map_tab[g->count_y])
	{
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->background, g->img_x, g->img_y);
	    while(g->map_tab[j][i])
	    {
	    	if (g->map_tab[j][i] == '1')
			{
				g->wall = mlx_xpm_file_to_image(g->mlx_ptr, "./image/wall_00.xpm", &g->width, &g->height);
				mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->wall, g->img_x, g->img_y);
				g->img_x += 60;
			}
			else if (g->map_tab[j][i] == '0')
			{
				g->wall = mlx_xpm_file_to_image(g->mlx_ptr, "./image/plant_03.xpm", &g->width, &g->height);
				mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->wall, g->img_x, g->img_y);
				g->img_x += 60;
			}
			else if (g->map_tab[j][i] == 'C')
			{
				g->wall = mlx_xpm_file_to_image(g->mlx_ptr, "./image/effect_w.xpm", &g->width, &g->height);
				mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->wall, g->img_x, g->img_x);
				g->img_x += 60;
			}
			else if (g->map_tab[j][i] == 'E')
			{
				g->wall = mlx_xpm_file_to_image(g->mlx_ptr, "./image/door_02.xpm", &g->width, &g->height);
				mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->wall, g->img_x, g->img_x);
				g->img_x += 60;
			}
			else if (g->map_tab[j][i] == 'P')
			{
				g->wall = mlx_xpm_file_to_image(g->mlx_ptr, "./image/enemy_01.xpm", &g->width, &g->height);
				mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->wall, g->img_x, g->img_x);
			}
			i++;
		}
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->wall, g->img_x, g->img_x);
		//g->wall = mlx_xpm_file_to_image(g->mlx_ptr, "->/image/wall_02->xpm", &g->width + 50, &g->height);
		//mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->wall, g->img_x + 50 , g->img_x + 50);
		// Maintien de la fenetre ouverte
		g->img_y += 60;
		g->img_x = 0;
		g->line = get_next_line(g->fd);
		i = 0;
		j++;
	}

}

void	map_render(t_game *g)
{
	int	i;

	g->count_x = 0;
	g->count_y = 0;
	i = 0;
	while (g->line)
	{
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->background, g->img_x, g->img_y);
	    while(g->line[i])
	    {
	    	if (g->line[i] == '1')
			{

				g->wall = mlx_xpm_file_to_image(g->mlx_ptr, "./image/wall_00.xpm", &g->width, &g->height);
				mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->wall, g->img_x, g->img_y);
				g->img_x += 60;
				
			}
			else if (g->line[i] == '0')
			{
				g->wall = mlx_xpm_file_to_image(g->mlx_ptr, "./image/plant_03.xpm", &g->width, &g->height);
				mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->wall, g->img_x, g->img_y);
				g->img_x += 60;
			}
			else if (g->line[i] == 'C')
			{
				g->wall = mlx_xpm_file_to_image(g->mlx_ptr, "./image/effect_w.xpm", &g->width, &g->height);
				mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->wall, g->img_x, g->img_x);
				g->img_x += 60;
			}
			else if (g->line[i] == 'E')
			{
				g->wall = mlx_xpm_file_to_image(g->mlx_ptr, "./image/door_02.xpm", &g->width, &g->height);
				mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->wall, g->img_x, g->img_x);
				g->img_x += 60;
			}
			else if (g->line[i] == 'P')
			{
				g->wall = mlx_xpm_file_to_image(g->mlx_ptr, "./image/enemy_01.xpm", &g->width, &g->height);
				mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->wall, g->img_x, g->img_x);
			}
			g->count_x++;
			i++;
		}
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->wall, g->img_x, g->img_x);
		//g->wall = mlx_xpm_file_to_image(g->mlx_ptr, "->/image/wall_02->xpm", &g->width + 50, &g->height);
		//mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->wall, g->img_x + 50 , g->img_x + 50);
		// Maintien de la fenetre ouverte
		g->count_y++;
		g->img_y += 60;
		g->img_x = 0;
		g->line = get_next_line(g->fd);
		i = 0;
	}
	g->count_x /= g->count_y;
}

void render(t_game *g, int i)
{
   	if (i != 0)
   	{
   		if(i == 1)
   		{
				//mlx_destroy_image(g->mlx_ptr, g->player_sprites[g->current_image][g->j]);
				g->j++;
				//mlx_clear_window(g->mlx_ptr, g->win_ptr);
				map_render_reload(g);
				mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->player_sprites[1][g->j], g->img_player_x, g->img_player_y);
				if (g->j == 5)
					g->j = 0;
				g->current_image = 1;
		}
		if(i == 2)
		{
				//mlx_destroy_image(g->mlx_ptr, g->player_sprites[g->current_image][g->j]);
				g->j++;
				mlx_clear_window(g->mlx_ptr, g->win_ptr);
				mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->player_sprites[0][g->j], g->img_player_x, g->img_player_y);
				if (g->j == 5)
					g->j = 0;
				g->current_image = 0;
		}
		if(i == 3)
		{
				//mlx_destroy_image(g->mlx_ptr, g->player_sprites[g->current_image][g->j]);
				g->j++;
				mlx_clear_window(g->mlx_ptr, g->win_ptr);
				mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->player_sprites[3][g->j], g->img_player_x, g->img_player_y);
				if (g->j == 5)
					g->j = 0;
				g->current_image = 3;
		}
		if(i == 4)
		{
			//mlx_destroy_image(g->mlx_ptr, g->player_sprites[g->current_image][g->j]);
			g->j++;
			mlx_clear_window(g->mlx_ptr, g->win_ptr);
			mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->player_sprites[2][g->j], g->img_player_x, g->img_player_y);
			if (g->j == 5)
				g->j = 0;
			g->current_image = 2;
		}
	}
	if (g->img_player_x > g->window_width - 85) 
		g->img_player_x = g->window_width - 85; // Limite droite
	if (g->img_player_y > g->window_height - 85) 
		g->img_player_y = g->window_height -85; 
	if (g->img_player_x < 85) 
		g->img_player_x = 85; 
	if (g->img_player_y < 85) 
		g->img_player_y = 85; 
}


int	handle_input(int key, t_game *g)
{
	if (key == 'w')
	{
		g->img_player_y -= g->step;
		render(g, 1);
	}
	else if (key == 's')
	{
		g->img_player_y += g->step;
		render(g, 2);
	}
	else if (key == 'a')
	{
		g->img_player_x -= g->step;
		render(g, 3);
	}
	else if (key == 'd')
	{
		g->img_player_x += g->step;
		render(g, 4);
	}
	render(g, 0);
	return (0);
}



int main() 
{
	t_game	g;

	g.window_width = 800;
	g.window_height = 600;
	g.j = 0;
	g.step = 25;
	g.img_player_y = 250;
	g.img_player_x = 250;
	g.img_x = 0;
	g.img_y = 0;
	g.mlx_ptr = mlx_init();
	g.win_ptr = mlx_new_window(g.mlx_ptr, g.window_width, g.window_height, "Moving Player");
	g.background = mlx_xpm_file_to_image(g.mlx_ptr, "./image/background.xpm", &g.width, &g.height);
	g.fd = open("map.ber", O_RDONLY);
	g.line = get_next_line(g.fd);
	map_render(&g);
	close (g.fd);
	g.fd = open("map.ber", O_RDONLY);
	g.line = get_next_line(g.fd);
	map_into_tab(&g);
    
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

    // Gestion des événements clavier et déplacement image du joueur
    mlx_key_hook(g.win_ptr, handle_input, &g);

    // Maintien de la fenêtre ouverte
    mlx_loop(g.mlx_ptr);

    return 0;
}

