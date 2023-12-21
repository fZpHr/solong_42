/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countdigits_unsigned.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:49:01 by hbelle            #+#    #+#             */
/*   Updated: 2023/11/21 14:18:13 by z                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/ft_printf.h"

int	ft_countdigits_unsigned(unsigned long int num)
{
	unsigned long int	count;
	unsigned long int	nb;

	nb = num;
	count = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}
