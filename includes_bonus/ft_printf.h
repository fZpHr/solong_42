/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelle <hbelle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:16:37 by hbelle            #+#    #+#             */
/*   Updated: 2023/12/20 13:26:23 by hbelle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "get_next_line.h"
# include "so_long_bonus.h"

size_t	ft_strlen(const char *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(long int nb, int fd);
void	ft_putnbr_fd_unsigned(unsigned long int nb, int fd);
void	ft_putnbr_fd_base_unsigned(unsigned long int nb, int fd, char *base);
int		ft_countdigits(int num);
int		ft_countdigits_unsigned(unsigned long int num);
int		ft_countdigits_base_unsigned(unsigned long int nb, unsigned int base);
size_t	ft_printf_check(size_t i, const char *format,
			va_list args, size_t *count);
int		ft_printf(const char *format, ...);

#endif
