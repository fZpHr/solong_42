/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelle <hbelle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:55:07 by hbelle            #+#    #+#             */
/*   Updated: 2023/12/20 14:28:23 by hbelle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"
#include <stdlib.h>

static long long int	ft_size(long long int str)
{
	long long int	i;

	i = 0;
	while (str != 0)
	{
		str /= 10;
		i++;
	}
	return (i);
}

static char	*ft_writer(long long int nbr, char *str, long long int i)
{
	while (nbr != 0)
	{
		str[i] = '0' + (nbr % 10);
		nbr /= 10;
		i--;
	}
	return (str);
}

static char	*nega(long long int n, char *str,
		long long int i, long long int len)
{
	i--;
	n = n * -1;
	str[0] = '-';
	str = ft_writer(n, str, i);
	str[len] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	long long int		i;
	long long int		len;
	char				*str;

	len = ft_size(n);
	if (n == 0)
		len = 1;
	if (n < 0)
		len++;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = len;
	if (n < 0)
		return (nega(n, str, i, len));
	i = len - 1;
	if (n == 0)
		str[0] = '0';
	else
		str = ft_writer(n, str, i);
	str[len] = '\0';
	return (str);
}
