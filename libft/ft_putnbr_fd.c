/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:57:24 by bjimenez          #+#    #+#             */
/*   Updated: 2022/04/29 09:50:44 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	q;

	if (n == -2147483648)
	{
		n = 214748364;
		write(fd, "-", 1);
		ft_putnbr_fd(n, fd);
		write(fd, "8", 1);
	}
	else if (n < 0 && n > -2147483648)
	{
		write(fd, "-", 1);
		ft_putnbr_fd(n * -1, fd);
	}
	else if (n >= 10)
	{	
		ft_putnbr_fd(n / 10, fd);
		q = (n % 10) + '0';
		write(fd, &q, 1);
	}
	else if (n < 10)
	{	
		q = n + '0';
		write(fd, &q, 1);
	}
}
