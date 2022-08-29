/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:59:58 by bjimenez          #+#    #+#             */
/*   Updated: 2022/05/04 13:17:53 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_s_str(const char *p, char c, int pos)
{
	int	np;
	int	i;
	int	s_sstr;
	int	sel;

	np = 0;
	i = 0;
	s_sstr = 0;
	sel = 1;
	while (p[i] != '\0' && np <= pos)
	{
		if (p[i] != c && np == pos)
		{			
			s_sstr++;
			sel = 0;
		}
		else if (p[i] == c && p[i + 1] != c && sel == 0)
			np++;
		else if (sel == 1 && p[i] != c && p[i + 1] == c)
			sel = 0;
		i++;
	}
	return (s_sstr);
}

static int	ft_n_str(char *p, char c)
{
	int	ns;
	int	i;
	int	c_sstr;

	ns = 0;
	i = 0;
	c_sstr = 1;
	while (p[i] != '\0')
	{
		if (p[i] != c && c_sstr == 1)
		{			
			ns++;
			c_sstr = 0;
		}
		else if (p[i] == c)
			c_sstr = 1;
		i++;
	}
	return (ns);
}

static void	ft_get_strs(int nstrs, const char *src, char x, char **str)
{
	int				j;
	int				i;
	int				k;

	k = 0;
	j = 0;
	while (j < nstrs && src[k] != '\0')
	{
		str[j] = (char *)malloc(sizeof(char) * (ft_s_str(src, x, j) + 1));
		i = 0;
		while (src[k] == x)
			k++;
		while (src[k] != x && src[k] != '\0')
		{
			str[j][i++] = src[k];
			k++;
		}
		str[j][i] = '\0';
		j++;
		k++;
	}
	str[j] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;
	int		k;

	j = 0;
	i = 0;
	k = 0;
	if (!s)
		return (0);
	str = (char **)malloc(sizeof(char *) * (ft_n_str((char *)s, c) + 1));
	if (str == NULL)
		return (NULL);
	ft_get_strs(ft_n_str((char *)s, c), s, c, str);
	return (str);
}
