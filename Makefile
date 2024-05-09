# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbelle <hbelle@student.42angouleme.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/18 17:11:29 by hbelle            #+#    #+#              #
#    Updated: 2024/05/10 00:57:15 by hbelle           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

NAME_BONUS = so_long_bonus

MAIN_SRCS = main.c \
	utils/ft_itoa.c \
	utils/printf/ft_putchar_fd.c \
	utils/printf/ft_putstr_fd.c \
	utils/printf/ft_putnbr_fd.c \
	utils/printf/ft_putnbr_fd_unsigned.c \
	utils/printf/ft_putnbr_fd_base_unsigned.c \
	utils/printf/ft_printf.c \
	utils/printf/ft_strlen.c \
	utils/printf/ft_countdigits.c \
	utils/printf/ft_countdigits_unsigned.c \
	utils/printf/ft_countdigits_base_unsigned.c \
	utils/printf/ft_printf_check.c \
	utils/gnl/get_next_line.c \
	utils/gnl/get_next_line_utils.c \
	check_map/map_check.c \
	check_map/check_map_files.c \
	check_map/map_limit.c \
	input/input.c \
	render/end.c \
	render/init_sprites.c \
	render/map_into_array.c \
	render/render_map.c \
	render/render_player.c \
	render/render_reload.c \

BONUS_SRCS = main_bonus.c \
	utils/ft_itoa_bonus.c \
	utils/printf_bonus/ft_putchar_fd.c \
	utils/printf_bonus/ft_putstr_fd.c \
	utils/printf_bonus/ft_putnbr_fd.c \
	utils/printf_bonus/ft_putnbr_fd_unsigned.c \
	utils/printf_bonus/ft_putnbr_fd_base_unsigned.c \
	utils/printf_bonus/ft_printf.c \
	utils/printf_bonus/ft_strlen.c \
	utils/printf_bonus/ft_countdigits.c \
	utils/printf_bonus/ft_countdigits_unsigned.c \
	utils/printf_bonus/ft_countdigits_base_unsigned.c \
	utils/printf_bonus/ft_printf_check.c \
	utils/gnl_bonus/get_next_line.c \
	utils/gnl_bonus/get_next_line_utils.c \
	check_map/map_check_bonus.c \
	check_map/check_map_files_bonus.c \
	check_map/map_limit_bonus.c \
	input/input_bonus.c \
	render/end_bonus.c \
	render/init_sprites_bonus.c \
	render/map_into_array_bonus.c \
	render/render_map_bonus.c \
	render/render_player_bonus.c \
	render/render_enemy_bonus.c \
	render/render_reload_bonus.c \

OBJTS = $(MAIN_SRCS:.c=.o)

OBJTS_BONUS = $(BONUS_SRCS:.c=.o)

HEADER = -I includes
HEADER_BONUS = -I includes_bonus
CFLAGS = -Wall -Werror -Wextra -I ./mlx/ -g

$(NAME): $(OBJTS)
	cc -o $(NAME) $(OBJTS) $(CFLAGS) $(HEADER) -L ./mlx -lmlx -lXext -lX11 -lm -lbsd

RM	=	rm -f

all:	${NAME}

bonus:	${OBJTS_BONUS}
	cc -o $(NAME_BONUS) $(OBJTS_BONUS) $(CFLAGS) $(HEADER_BONUS) -L ./mlx -lmlx -lXext -lX11 -lm -lbsd

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	${RM} ${OBJTS} ${OBJTS_BONUS}
	
fclean:	clean
	${RM} ${NAME} ${NAME_BONUS}

re:	fclean all

.PHONY: all bonus clean fclean re
