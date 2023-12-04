#include "mlx/mlx.h"
#include <stdio.h>

int img_x = 250; // Coord horizontale de l'image du joueur
int img_y = 250; // Coord verticale de l'image du joueur
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

int window_width = 1480; // Largeur de la fenetre
int window_height = 800; // Hauteur de la fenetre




void render(int	i)
{
	
    // Affichage image du joueur img_x, img_y
   // mlx_put_image_to_window(mlx_ptr, win_ptr, background_ptr, 0, 0);
   	if (i != 0)
   		if(i == 1)
   		{
   			if (j == 0)
   			{
   				j++;
				mlx_put_image_to_window(mlx_ptr, win_ptr, player_ptr_w1, img_x, img_y);
			}
			else if (j == 1)
			{
				j++;
				mlx_put_image_to_window(mlx_ptr, win_ptr, player_ptr_w2, img_x, img_y);
			}
			else if (j == 2)
			{
				j++;
				mlx_put_image_to_window(mlx_ptr, win_ptr, player_ptr_w3, img_x, img_y);
			}
			else if (j == 3)
			{
				j++;
				mlx_put_image_to_window(mlx_ptr, win_ptr, player_ptr_w4, img_x, img_y);
			}
			else if (j == 4)
			{
				j = 0;
				mlx_put_image_to_window(mlx_ptr, win_ptr, player_ptr_w5, img_x, img_y);
			}
			
		}
		if(i == 2)
			if (j == 0)
   			{
   				j++;
				mlx_put_image_to_window(mlx_ptr, win_ptr, player_ptr_s1, img_x, img_y);
			}
			else if (j == 1)
			{
				j++;
				mlx_put_image_to_window(mlx_ptr, win_ptr, player_ptr_s2, img_x, img_y);
			}
			else if (j == 2)
			{
				j++;
				mlx_put_image_to_window(mlx_ptr, win_ptr, player_ptr_s3, img_x, img_y);
			}
			else if (j == 3)
			{
				j++;
				mlx_put_image_to_window(mlx_ptr, win_ptr, player_ptr_s4, img_x, img_y);
			}
			else if (j == 4)
			{
				j = 0;
				mlx_put_image_to_window(mlx_ptr, win_ptr, player_ptr_s5, img_x, img_y);
			}
		if(i == 3)
			if (j == 0)
   			{
   				j++;
				mlx_put_image_to_window(mlx_ptr, win_ptr, player_ptr_a1, img_x, img_y);
			}
			else if (j == 1)
			{
				j++;
				mlx_put_image_to_window(mlx_ptr, win_ptr, player_ptr_a2, img_x, img_y);
			}
			else if (j == 2)
			{
				j++;
				mlx_put_image_to_window(mlx_ptr, win_ptr, player_ptr_a3, img_x, img_y);
			}
			else if (j == 3)
			{
				j++;
				mlx_put_image_to_window(mlx_ptr, win_ptr, player_ptr_a4, img_x, img_y);
			}
			else if (j == 4)
			{
				j = 0;
				mlx_put_image_to_window(mlx_ptr, win_ptr, player_ptr_a5, img_x, img_y);
			}
		if(i == 4)
			if (j == 0)
   			{
   				j++;
				mlx_put_image_to_window(mlx_ptr, win_ptr, player_ptr_d1, img_x, img_y);
			}
			else if (j == 1)
			{
				j++;
				mlx_put_image_to_window(mlx_ptr, win_ptr, player_ptr_d2, img_x, img_y);
			}
			else if (j == 2)
			{
				j++;
				mlx_put_image_to_window(mlx_ptr, win_ptr, player_ptr_d3, img_x, img_y);
			}
			else if (j == 3)
			{
				j++;
				mlx_put_image_to_window(mlx_ptr, win_ptr, player_ptr_d4, img_x, img_y);
			}
			else if (j == 4)
			{
				j = 0;
				mlx_put_image_to_window(mlx_ptr, win_ptr, player_ptr_d5, img_x, img_y);
			}
	if (img_x > window_width - 64) img_x = window_width - 64; // Limite droite
	if (img_y > window_height - 64) img_y = window_height - 64; // Limite basse
	if (img_x < 0) img_x = 0; // Limite gauche
	if (img_y < 0) img_y = 0; // Limite haute

}

int handle_input(int key) {
    const int step = 25; // Deplacement par étape

    // Gestion des touches WASD pour déplacer image du joueur
    if (key == 119) { // Touche W pour monter (ASCII pour 'w')
            img_y -= step;
            render(1);
    } else if (key == 115) { // Touche S pour descendre (ASCII pour 's')
            img_y += step;
            render(2);
    } else if (key == 97) { // Touche A pour aller à gauche (ASCII pour 'a')
            img_x -= step;
            render(3);
    } else if (key == 100) { // Touche D pour aller à droite (ASCII pour 'd')
            img_x += step;
            render(4);
    }
 // Met à jour affichage apres le déplacement de l'image du joueur
 	render(0);
    return 0;
}



int main() {
    int width, height;

    // Initialisation de la fenêtre
    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, window_width, window_height, "Moving Player");

    // Chargement image de fond
  //  background_ptr = mlx_xpm_file_to_image(mlx_ptr, "/home/z/42/Project_solong/image/Background.xpm", &width, &height);
//    if (background_ptr == NULL) {
  //      fprintf(stderr, "Erreur : Impossible de charger l'image de fond.\n");
    //    return 1;
   // }

    // Chargement image du joueur
	player_ptr_s1 = mlx_xpm_file_to_image(mlx_ptr, "/home/z/42/Project_solong/image/chara/char_run_down_0.xpm", &width, &height);
	player_ptr_s2 = mlx_xpm_file_to_image(mlx_ptr, "/home/z/42/Project_solong/image/chara/char_run_down_1.xpm", &width, &height);
	player_ptr_s3 = mlx_xpm_file_to_image(mlx_ptr, "/home/z/42/Project_solong/image/chara/char_run_down_2.xpm", &width, &height);
	player_ptr_s4 = mlx_xpm_file_to_image(mlx_ptr, "/home/z/42/Project_solong/image/chara/char_run_down_3.xpm", &width, &height);
	player_ptr_s5 = mlx_xpm_file_to_image(mlx_ptr, "/home/z/42/Project_solong/image/chara/char_run_down_4.xpm", &width, &height);

	player_ptr_w1 = mlx_xpm_file_to_image(mlx_ptr, "/home/z/42/Project_solong/image/chara/char_run_up_0.xpm", &width, &height);
	player_ptr_w2 = mlx_xpm_file_to_image(mlx_ptr, "/home/z/42/Project_solong/image/chara/char_run_up_1.xpm", &width, &height);
	player_ptr_w3 = mlx_xpm_file_to_image(mlx_ptr, "/home/z/42/Project_solong/image/chara/char_run_up_2.xpm", &width, &height);
	player_ptr_w4 = mlx_xpm_file_to_image(mlx_ptr, "/home/z/42/Project_solong/image/chara/char_run_up_3.xpm", &width, &height);
	player_ptr_w5 = mlx_xpm_file_to_image(mlx_ptr, "/home/z/42/Project_solong/image/chara/char_run_up_4.xpm", &width, &height);
	
	
	
	player_ptr_d1 = mlx_xpm_file_to_image(mlx_ptr, "/home/z/42/Project_solong/image/chara/char_run_right_0.xpm", &width, &height);
	player_ptr_d2 = mlx_xpm_file_to_image(mlx_ptr, "/home/z/42/Project_solong/image/chara/char_run_right_1.xpm", &width, &height);
	player_ptr_d3 = mlx_xpm_file_to_image(mlx_ptr, "/home/z/42/Project_solong/image/chara/char_run_right_2.xpm", &width, &height);
	player_ptr_d4 = mlx_xpm_file_to_image(mlx_ptr, "/home/z/42/Project_solong/image/chara/char_run_right_3.xpm", &width, &height);
	player_ptr_d5 = mlx_xpm_file_to_image(mlx_ptr, "/home/z/42/Project_solong/image/chara/char_run_right_4.xpm", &width, &height);



	player_ptr_a1 = mlx_xpm_file_to_image(mlx_ptr, "/home/z/42/Project_solong/image/chara/char_run_left_0.xpm", &width, &height);
	player_ptr_a2 = mlx_xpm_file_to_image(mlx_ptr, "/home/z/42/Project_solong/image/chara/char_run_left_1.xpm", &width, &height);
	player_ptr_a3 = mlx_xpm_file_to_image(mlx_ptr, "/home/z/42/Project_solong/image/chara/char_run_left_2.xpm", &width, &height);
	player_ptr_a4 = mlx_xpm_file_to_image(mlx_ptr, "/home/z/42/Project_solong/image/chara/char_run_left_3.xpm", &width, &height);
	player_ptr_a5 = mlx_xpm_file_to_image(mlx_ptr, "/home/z/42/Project_solong/image/chara/char_run_left_4.xpm", &width, &height);	
	
    // Affichage initial image de fond dans la fenêtre
  //  mlx_put_image_to_window(mlx_ptr, win_ptr, background_ptr, 0, 0);

    // Affichage image du joueur a la position initiale img_x, img_y
    mlx_put_image_to_window(mlx_ptr, win_ptr, player_ptr_s1, img_x, img_y);

    // Gestion des événements clavier et déplacement image du joueur
    mlx_key_hook(win_ptr, handle_input, mlx_ptr);

    // Maintien de la fenêtre ouverte
    mlx_loop(mlx_ptr);

    return 0;
}

