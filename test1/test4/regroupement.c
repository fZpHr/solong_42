#include "mlx/mlx.h"
#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>

int img_x = 0; // Coordonnée horizontale initiale image
int img_y = 0;
int img_player_x = 250; // Coord horizontale de l'image du joueur
int img_player_y = 250; // Coord verticale de l'image du joueur
void *background_ptr; // Pointeur vers l'image de fond
void *player_ptr_s1; // Pointeur vers l'image du joueur
void *player_ptr_s2;
void *player_ptr_s3;
void *player_ptr_s4;
void *player_ptr_s5;

void *player_ptr_w1;
void *player_ptr_w2;
void *player_ptr_w3;
void *player_ptr_w4;
void *player_ptr_w5;

void *player_ptr_d1;
void *player_ptr_d2;
void *player_ptr_d3;
void *player_ptr_d4;
void *player_ptr_d5;

void *player_ptr_a1;
void *player_ptr_a2;
void *player_ptr_a3;
void *player_ptr_a4;
void *player_ptr_a5;

void *win_ptr; // Pointeur vers la fenetre
void *mlx_ptr; //
static int	j = 0;

int window_width = 845; // Largeur de la fenetre
int window_height = 600; // Hauteur de la fenetre

int	width = 10;
int	height = 10;

/*
void	mapbuilder(void)
{
	void *background_ptr;
	void *background_ptr1;
    
	// Initialisation de la fenêtre
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, window_width, window_height, "MAP");


	char	*line;
	int	fd;
	int	i;
	
	background_ptr = mlx_xpm_file_to_image(mlx_ptr, "/nfs/homes/hbelle/42/Projet/Project_solong/image/background.xpm", &width, &height);
	i = 0;
	fd = open("map.ber", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		int	l = ft_strlen(line); 
		mlx_put_image_to_window(mlx_ptr, win_ptr, background_ptr, img_x, img_y);
	    	while(i < l)
	    	{
	    		if (line[i] == '1')
			{
				background_ptr1 = mlx_xpm_file_to_image(mlx_ptr, "/nfs/homes/hbelle/42/Projet/Project_solong/image/wall_02.xpm", &width, &height);
				mlx_put_image_to_window(mlx_ptr, win_ptr, background_ptr1, img_x, img_y);
				img_x += 60;
			}
			else if (line[i] == '0')
			{
				background_ptr1 = mlx_xpm_file_to_image(mlx_ptr, "/nfs/homes/hbelle/42/Projet/Project_solong/image/plant_03.xpm", &width, &height);
				mlx_put_image_to_window(mlx_ptr, win_ptr, background_ptr1, img_x, img_y);
				img_x += 60;
			}
			else if (line[i] == 'C')
			{
				background_ptr1 = mlx_xpm_file_to_image(mlx_ptr, "/nfs/homes/hbelle/42/Projet/Project_solong/image/effect_w.xpm", &width, &height);
				mlx_put_image_to_window(mlx_ptr, win_ptr, background_ptr1, img_x, img_y);
				img_x += 60;
			}
			else if (line[i] == 'E')
			{
				background_ptr1 = mlx_xpm_file_to_image(mlx_ptr, "/nfs/homes/hbelle/42/Projet/Project_solong/image/door_02.xpm", &width, &height);
				mlx_put_image_to_window(mlx_ptr, win_ptr, background_ptr1, img_x, img_y);
				img_x += 60;
			}
			else if (line[i] == 'P')
			{
				background_ptr1 = mlx_xpm_file_to_image(mlx_ptr, "/nfs/homes/hbelle/42/Projet/Project_solong/image/enemy_01.xpm", &width, &height);
				mlx_put_image_to_window(mlx_ptr, win_ptr, background_ptr1, img_x, img_y);
				img_x += 60;
			}
			i++;		
		}
		mlx_put_image_to_window(mlx_ptr, win_ptr, background_ptr1, img_x, img_y);
		//background_ptr1 = mlx_xpm_file_to_image(mlx_ptr, "/nfs/homes/hbelle/42/Projet/Project_solong/image/wall_02.xpm", &width + 50, &height);
		//mlx_put_image_to_window(mlx_ptr, win_ptr, background_ptr1, img_x + 50 , img_y + 50);
		// Maintien de la fenetre ouverte
		img_y += 60;
		img_x = 0;
		line = get_next_line(fd);
		i = 0;
	}
	//mlx_loop(mlx_ptr);
}*/

void render(int	i)
{
	
    // Affichage image du joueur img_x, img_y
   // mlx_put_image_to_window(mlx_ptr, win_ptr, background_ptr, 0, 0);
   	if (i != 0)
   	{
   		if(i == 1)
   		{
   			if (j == 0)
   			{
   				j++;
				mlx_put_image_to_window(mlx_ptr, win_ptr, player_ptr_w1, img_player_x, img_player_y);
			}
			else if (j == 1)
			{
				j++;
				mlx_put_image_to_window(mlx_ptr, win_ptr, player_ptr_w2, img_player_x, img_player_y);
			}
			else if (j == 2)
			{
				j++;
				mlx_put_image_to_window(mlx_ptr, win_ptr, player_ptr_w3, img_player_x, img_player_y);
			}
			else if (j == 3)
			{
				j++;
				mlx_put_image_to_window(mlx_ptr, win_ptr, player_ptr_w4, img_player_x, img_player_y);
			}
			else if (j == 4)
			{
				j = 0;
				mlx_put_image_to_window(mlx_ptr, win_ptr, player_ptr_w5, img_player_x, img_player_y);
			}
			
		}
		if(i == 2)
		{
			if (j == 0)
   			{
   				j++;
				mlx_put_image_to_window(mlx_ptr, win_ptr, player_ptr_s1, img_player_x, img_player_y);
			}
			else if (j == 1)
			{
				j++;
				mlx_put_image_to_window(mlx_ptr, win_ptr, player_ptr_s2, img_player_x, img_player_y);
			}
			else if (j == 2)
			{
				j++;
				mlx_put_image_to_window(mlx_ptr, win_ptr, player_ptr_s3, img_player_x, img_player_y);
			}
			else if (j == 3)
			{
				j++;
				mlx_put_image_to_window(mlx_ptr, win_ptr, player_ptr_s4, img_player_x, img_player_y);
			}
			else if (j == 4)
			{
				j = 0;
				mlx_put_image_to_window(mlx_ptr, win_ptr, player_ptr_s5, img_player_x, img_player_y);
			}
		}
		if(i == 3)
		{
			if (j == 0)
   			{
   				j++;
				mlx_put_image_to_window(mlx_ptr, win_ptr, player_ptr_a1, img_player_x, img_player_y);
			}
			else if (j == 1)
			{
				j++;
				mlx_put_image_to_window(mlx_ptr, win_ptr, player_ptr_a2, img_player_x, img_player_y);
			}
			else if (j == 2)
			{
				j++;
				mlx_put_image_to_window(mlx_ptr, win_ptr, player_ptr_a3, img_player_x, img_player_y);
			}
			else if (j == 3)
			{
				j++;
				mlx_put_image_to_window(mlx_ptr, win_ptr, player_ptr_a4, img_player_x, img_player_y);
			}
			else if (j == 4)
			{
				j = 0;
				mlx_put_image_to_window(mlx_ptr, win_ptr, player_ptr_a5, img_player_x, img_player_y);
			}
		}
		if(i == 4)
		{
			if (j == 0)
   			{
   				j++;
				mlx_put_image_to_window(mlx_ptr, win_ptr, player_ptr_d1, img_player_x, img_y);
			}
			else if (j == 1)
			{
				j++;
				mlx_put_image_to_window(mlx_ptr, win_ptr, player_ptr_d2, img_player_x, img_player_y);
			}
			else if (j == 2)
			{
				j++;
				mlx_put_image_to_window(mlx_ptr, win_ptr, player_ptr_d3, img_player_x, img_player_y);
			}
			else if (j == 3)
			{
				j++;
				mlx_put_image_to_window(mlx_ptr, win_ptr, player_ptr_d4, img_player_x, img_player_y);
			}
			else if (j == 4)
			{
				j = 0;
				mlx_put_image_to_window(mlx_ptr, win_ptr, player_ptr_d5, img_player_x, img_player_y);
			}
		}
	}
	if (img_player_x > window_width - 85) 
		img_player_x = window_width - 85; // Limite droite
	if (img_player_y > window_height - 85) 
		img_player_y = window_height -85; // Limite basse
	if (img_player_x < 85) 
		img_player_x = 85; // Limite gauche
	if (img_player_y < 85) 
		img_player_y = 85; // Limite haute
}


int handle_input(int key)
{
    const int step = 25; 


    if (key == 'w') 
    { 
            img_player_y -= step;
            render(1);
    }
    else if (key == 's')
    {
            img_player_y += step;
            render(2);
    } 
    else if (key == 'a') 
    { 
            img_player_x -= step;
            render(3);
    } 
    else if (key == 'd')
    {
            img_player_x += step;
            render(4);
    }
	render(0);
	return 0;
}



int main() 
{

	void *background_ptr;
	void *background_ptr1;
	char	*line;
	int	fd;
	int	i;

    // Initialisation de la fenêtre
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, window_width, window_height, "Moving Player");
	background_ptr = mlx_xpm_file_to_image(mlx_ptr, "/nfs/homes/hbelle/42/Projet/Project_solong/image/background.xpm", &width, &height);
i = 0;
	fd = open("map.ber", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		int	l = ft_strlen(line); 
		mlx_put_image_to_window(mlx_ptr, win_ptr, background_ptr, img_x, img_y);
	    	while(i < l)
	    	{
	    		if (line[i] == '1')
			{
				background_ptr1 = mlx_xpm_file_to_image(mlx_ptr, "/nfs/homes/hbelle/42/Projet/Project_solong/image/wall_00.xpm", &width, &height);
				mlx_put_image_to_window(mlx_ptr, win_ptr, background_ptr1, img_x, img_y);
				img_x += 60;
			}
			else if (line[i] == '0')
			{
				background_ptr1 = mlx_xpm_file_to_image(mlx_ptr, "/nfs/homes/hbelle/42/Projet/Project_solong/image/plant_03.xpm", &width, &height);
				mlx_put_image_to_window(mlx_ptr, win_ptr, background_ptr1, img_x, img_y);
				img_x += 60;
			}
			else if (line[i] == 'C')
			{
				background_ptr1 = mlx_xpm_file_to_image(mlx_ptr, "/nfs/homes/hbelle/42/Projet/Project_solong/image/effect_w.xpm", &width, &height);
				mlx_put_image_to_window(mlx_ptr, win_ptr, background_ptr1, img_x, img_y);
				img_x += 60;
			}
			else if (line[i] == 'E')
			{
				background_ptr1 = mlx_xpm_file_to_image(mlx_ptr, "/nfs/homes/hbelle/42/Projet/Project_solong/image/door_02.xpm", &width, &height);
				mlx_put_image_to_window(mlx_ptr, win_ptr, background_ptr1, img_x, img_y);
				img_x += 60;
			}
			else if (line[i] == 'P')
			{
				background_ptr1 = mlx_xpm_file_to_image(mlx_ptr, "/nfs/homes/hbelle/42/Projet/Project_solong/image/enemy_01.xpm", &width, &height);
				mlx_put_image_to_window(mlx_ptr, win_ptr, background_ptr1, img_x, img_y);
				img_x += 60;
			}
			i++;		
		}
		mlx_put_image_to_window(mlx_ptr, win_ptr, background_ptr1, img_x, img_y);
		//background_ptr1 = mlx_xpm_file_to_image(mlx_ptr, "/nfs/homes/hbelle/42/Projet/Project_solong/image/wall_02.xpm", &width + 50, &height);
		//mlx_put_image_to_window(mlx_ptr, win_ptr, background_ptr1, img_x + 50 , img_y + 50);
		// Maintien de la fenetre ouverte
		img_y += 60;
		img_x = 0;
		line = get_next_line(fd);
		i = 0;
	}

    
	player_ptr_s1 = mlx_xpm_file_to_image(mlx_ptr, "/nfs/homes/hbelle/42/Projet/Project_solong/image/chara/char_run_down_0.xpm", &width, &height);
	if (!player_ptr_s1)
		return(printf("ALED"));
	player_ptr_s2 = mlx_xpm_file_to_image(mlx_ptr, "/nfs/homes/hbelle/42/Projet/Project_solong/image/chara/char_run_down_1.xpm", &width, &height);
	player_ptr_s3 = mlx_xpm_file_to_image(mlx_ptr, "/nfs/homes/hbelle/42/Projet/Project_solong/image/chara/char_run_down_2.xpm", &width, &height);
	player_ptr_s4 = mlx_xpm_file_to_image(mlx_ptr, "/nfs/homes/hbelle/42/Projet/Project_solong/image/chara/char_run_down_3.xpm", &width, &height);
	player_ptr_s5 = mlx_xpm_file_to_image(mlx_ptr, "/nfs/homes/hbelle/42/Projet/Project_solong/image/chara/char_run_down_4.xpm", &width, &height);

	player_ptr_w1 = mlx_xpm_file_to_image(mlx_ptr, "/nfs/homes/hbelle/42/Projet/Project_solong/image/chara/char_run_up_0.xpm", &width, &height);
	player_ptr_w2 = mlx_xpm_file_to_image(mlx_ptr, "/nfs/homes/hbelle/42/Projet/Project_solong/image/chara/char_run_up_1.xpm", &width, &height);
	player_ptr_w3 = mlx_xpm_file_to_image(mlx_ptr, "/nfs/homes/hbelle/42/Projet/Project_solong/image/chara/char_run_up_2.xpm", &width, &height);
	player_ptr_w4 = mlx_xpm_file_to_image(mlx_ptr, "/nfs/homes/hbelle/42/Projet/Project_solong/image/chara/char_run_up_3.xpm", &width, &height);
	player_ptr_w5 = mlx_xpm_file_to_image(mlx_ptr, "/nfs/homes/hbelle/42/Projet/Project_solong/image/chara/char_run_up_4.xpm", &width, &height);
	
	
	
	player_ptr_d1 = mlx_xpm_file_to_image(mlx_ptr, "/nfs/homes/hbelle/42/Projet/Project_solong/image/chara/char_run_right_0.xpm", &width, &height);
	player_ptr_d2 = mlx_xpm_file_to_image(mlx_ptr, "/nfs/homes/hbelle/42/Projet/Project_solong/image/chara/char_run_right_1.xpm", &width, &height);
	player_ptr_d3 = mlx_xpm_file_to_image(mlx_ptr, "/nfs/homes/hbelle/42/Projet/Project_solong/image/chara/char_run_right_2.xpm", &width, &height);
	player_ptr_d4 = mlx_xpm_file_to_image(mlx_ptr, "/nfs/homes/hbelle/42/Projet/Project_solong/image/chara/char_run_right_3.xpm", &width, &height);
	player_ptr_d5 = mlx_xpm_file_to_image(mlx_ptr, "/nfs/homes/hbelle/42/Projet/Project_solong/image/chara/char_run_right_4.xpm", &width, &height);



	player_ptr_a1 = mlx_xpm_file_to_image(mlx_ptr, "/nfs/homes/hbelle/42/Projet/Project_solong/image/chara/char_run_left_0.xpm", &width, &height);
	player_ptr_a2 = mlx_xpm_file_to_image(mlx_ptr, "/nfs/homes/hbelle/42/Projet/Project_solong/image/chara/char_run_left_1.xpm", &width, &height);
	player_ptr_a3 = mlx_xpm_file_to_image(mlx_ptr, "/nfs/homes/hbelle/42/Projet/Project_solong/image/chara/char_run_left_2.xpm", &width, &height);
	player_ptr_a4 = mlx_xpm_file_to_image(mlx_ptr, "/nfs/homes/hbelle/42/Projet/Project_solong/image/chara/char_run_left_3.xpm", &width, &height);
	player_ptr_a5 = mlx_xpm_file_to_image(mlx_ptr, "/nfs/homes/hbelle/42/Projet/Project_solong/image/chara/char_run_left_4.xpm", &width, &height);	
	
    // Affichage initial image de fond dans la fenêtre
  //  mlx_put_image_to_window(mlx_ptr, win_ptr, background_ptr, 0, 0);

    // Affichage image du joueur a la position initiale img_x, img_y
    mlx_put_image_to_window(mlx_ptr, win_ptr, player_ptr_s1, img_player_x, img_player_y);

    // Gestion des événements clavier et déplacement image du joueur
    mlx_key_hook(win_ptr, handle_input, mlx_ptr);

    // Maintien de la fenêtre ouverte
    mlx_loop(mlx_ptr);

    return 0;
}

