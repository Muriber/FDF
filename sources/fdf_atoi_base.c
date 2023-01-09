/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_atoi_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 11:47:54 by bjimenez          #+#    #+#             */
/*   Updated: 2022/08/29 09:23:46 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

int	ft_check_base(char c, int base)
{
	char	*base_t1;
	char	*base_t2;
	int		i;

	base_t1 = "0123456789abcdef";
	base_t2 = "0123456789ABCDEF";
	i = 0;
	while (i < base)
	{
		if (c == base_t1[i] || c == base_t2[i])
			return (i);
		i++;
	}
	return (-1);
}	

int	ft_atoi_base(const char *str, int base)
{
	int		i;
	int		sig;
	int		num;

	i = 0;
	sig = 1;
	num = 0;
	if (base == 16 && str[0] == '0' && str[1] == 'x')
		str = str + 2;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sig = sig * (-1);
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (ft_check_base(str[i], base) != -1)
	{
		num = num * base;
		num = num + ft_check_base(str[i], base);
		i++;
	}
	return (num * sig);
}
