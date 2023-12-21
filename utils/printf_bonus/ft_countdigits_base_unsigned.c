/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countdigits_base_unsigned.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:49:01 by hbelle            #+#    #+#             */
/*   Updated: 2023/11/21 14:15:42 by z                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/ft_printf.h"

int	ft_countdigits_base_unsigned(unsigned long int nb, unsigned int base)
{
	int	count;

	count = 0;
	if (nb == 0)
		return (1);
	while (nb >= base)
	{
		nb /= base;
		count++;
	}
	return (count);
}
