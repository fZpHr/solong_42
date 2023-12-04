
/*void	check_map()
{
	char	*line;
	int	fd;
	int	i;
	
	
	i = 0;
	fd = open("map.ber", O_RDONLY);
	line = get_next_line(int fd);
	
	while(line[i] != '\0')
	{
		if (line[i] == 1)
		{
			background_ptr = mlx_xpm_file_to_image(mlx_ptr, "/home/z/42/Project_solong/image/chara/wall_ul.xpm", 0, 0);
		}
		if (line[i] == 0)
		{
			background_ptr = mlx_xpm_file_to_image(mlx_ptr, "/home/z/42/Project_solong/image/chara/plant_03.xpm", &width, &height);
		}
		if (line[i] == 'C')
		{
			background_ptr = mlx_xpm_file_to_image(mlx_ptr, "/home/z/42/Project_solong/image/chara/effect_w.xpm", &width, &height);
		}
		if (line[i] == 'E')
		{
			background_ptr = mlx_xpm_file_to_image(mlx_ptr, "/home/z/42/Project_solong/image/chara/door_02.xpm", &width, &height);
		}
	}
}*/
#include "mlx/mlx.h"
#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>

int img_x = 250; // Coordonnée horizontale initiale image du joueur
int img_y = 250;
int window_width = 1480; // Largeur de la fenetre
int window_height = 800; // Hauteur de la fenetre
void *win_ptr; // Pointeur vers la fenetre
void *mlx_ptr; //	

int	main() 
{
	void *background_ptr;
	void *background_ptr1;
	int width, height;
    
	// Initialisation de la fenêtre
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, window_width, window_height, "Moving Player");


	char	*line;
	int	fd;
	int	i;
	
	background_ptr = mlx_xpm_file_to_image(mlx_ptr, "/home/z/42/Project_solong/image/wall_02.xpm", &width, &height);
	i = 0;
	fd = open("map.ber", O_RDONLY);
	line = get_next_line(fd);
	
    // Affichage initial image de fond dans la fenêtre
  //  mlx_put_image_to_window(mlx_ptr, win_ptr, background_ptr, 0, 0);

    // Affichage image du joueur position  img_x, img_y
    mlx_put_image_to_window(mlx_ptr, win_ptr, background_ptr, img_x, img_y);
    
    		if (line[i] == '1')
		{
			background_ptr1 = mlx_xpm_file_to_image(mlx_ptr, "/home/z/42/Project_solong/image/wall_02.xpm", &width, &height);
			if (!background_ptr)
				return (printf("aled1"));
		}
		else if (line[i] == '0')
		{
			background_ptr1 = mlx_xpm_file_to_image(mlx_ptr, "/home/z/42/Project_solong/image/plant_03.xpm", &width, &height);
			if (!background_ptr)
				return (printf("aled0"));
		}
		else if (line[i] == 'C')
		{
			background_ptr1 = mlx_xpm_file_to_image(mlx_ptr, "/home/z/42/Project_solong/image/effect_w.xpm", &width, &height);
			if (!background_ptr)
				return (printf("aledC"));
		}
		else if (line[i] == 'E')
		{
			background_ptr1 = mlx_xpm_file_to_image(mlx_ptr, "/home/z/42/Project_solong/image/door_02.xpm", &width, &height);
			if (!background_ptr)
				return (printf("aledE"));
		}

	mlx_put_image_to_window(mlx_ptr, win_ptr, background_ptr1, img_x, img_y);
		background_ptr1 = mlx_xpm_file_to_image(mlx_ptr, "/home/z/42/Project_solong/image/wall_02.xpm", &width + 50, &height);
	mlx_put_image_to_window(mlx_ptr, win_ptr, background_ptr1, img_x + 50 , img_y + 50);
    // Maintien de la fenetre ouverte
	mlx_loop(mlx_ptr);

	return 0;
}

