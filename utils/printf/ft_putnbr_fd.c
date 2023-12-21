/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:06:57 by hbelle            #+#    #+#             */
/*   Updated: 2023/11/09 15:29:48 by hbelle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/ft_printf.h"

void	ft_putnbr_fd(long int nb, int fd)
{
	if (nb < 0)
	{
		nb = nb * (-1);
		write(fd, "-", 1);
	}
	if (nb <= 9)
	{
		nb = nb + 48;
		write(fd, &nb, 1);
	}
	else
	{
		ft_putnbr_fd((nb / 10), fd);
		nb = nb % 10 + 48;
		write(fd, &nb, 1);
	}
}
