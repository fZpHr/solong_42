/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_unsigned.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:59:05 by hbelle            #+#    #+#             */
/*   Updated: 2023/12/18 16:59:10 by hbelle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/ft_printf.h"

void	ft_putnbr_fd_unsigned(unsigned long int nb, int fd)
{
	if (nb <= 9)
	{
		nb = nb + 48;
		write(fd, &nb, 1);
	}
	else
	{
		ft_putnbr_fd_unsigned((nb / 10), fd);
		nb = nb % 10 + 48;
		write(fd, &nb, 1);
	}
}
