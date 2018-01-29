/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 20:08:24 by adstan            #+#    #+#             */
/*   Updated: 2017/09/03 20:21:08 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_func.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	int_min(void)
{
	ft_putchar('-');
	ft_putchar('2');
	ft_putchar('1');
	ft_putchar('4');
	ft_putchar('7');
	ft_putchar('4');
	ft_putchar('8');
	ft_putchar('3');
	ft_putchar('6');
	ft_putchar('4');
	ft_putchar('8');
}

void	ft_putnbr(int nb)
{
	int v[10];
	int i;

	i = 0;
	if (nb == -2147483648)
		int_min();
	if (nb == 0)
		ft_putchar('0');
	else
	{
		if (nb < 0)
		{
			ft_putchar('-');
			nb = -nb;
		}
		while (nb)
		{
			v[i] = nb % 10;
			i++;
			nb /= 10;
		}
		while (i--)
			ft_putchar(v[i] + '0');
	}
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while ((dest[i] = src[i]) != '\0')
		i++;
}
