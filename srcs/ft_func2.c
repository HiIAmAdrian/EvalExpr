/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 15:58:48 by adstan            #+#    #+#             */
/*   Updated: 2017/09/03 21:03:34 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_func2.h"

int		ft_atoi(char *str)
{
	int final_number;
	int sign;
	int number_start;

	sign = 1;
	final_number = 0;
	number_start = 0;
	while (*str != '\0')
	{
		if (*str >= '0' && *str <= '9')
		{
			number_start = 1;
			final_number = final_number * 10 + (*str - '0') * sign;
		}
		else if ((*str == '-' || *str == '+') && number_start == 0)
		{
			number_start = 1;
			if (*str == '-')
				sign = -1;
		}
		else if (number_start == 1 || (int)*str > 32)
			return (final_number);
		str++;
	}
	return (final_number);
}

void	wh(int *nb, int *v, int *j)
{
	while (*nb)
	{
		v[*j] = *nb % 10;
		(*j)++;
		*nb /= 10;
	}
}

char	*ft_itoa(int nb)
{
	char	*str;
	int		i;
	int		j;
	int		v[10];

	i = 0;
	j = 0;
	str = malloc(sizeof(char) * 10);
	if (!nb)
		return ("0");
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
		i++;
	}
	wh(&nb, v, &j);
	while (j > 0)
	{
		str[i] = v[j - 1] + '0';
		j--;
		i++;
	}
	return (str);
}
