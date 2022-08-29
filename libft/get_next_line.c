/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 09:23:31 by bjimenez          #+#    #+#             */
/*   Updated: 2022/07/15 09:32:33 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

char	*gnl_init_sent(char *str)
{
	int		i;
	int		j;
	char	*init_line;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	init_line = ft_calloc((ft_strlen(str) - i + 1), sizeof(char));
	i++;
	while (str[i])
		init_line[j++] = str[i++];
	free(str);
	return (init_line);
}

char	*gnl_sentence(char *str)
{
	char	*aux_sent;
	int		i;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	aux_sent = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		aux_sent[i] = str[i];
		i++;
	}
	if (str[i] && str[i] == '\n')
	{
		aux_sent[i] = '\n';
		aux_sent[i + 1] = '\0';
	}
	else
		aux_sent[i] = '\0';
	return (aux_sent);
}

char	*gnl_get_content(int fd, char *str)
{
	char	*aux;
	int		n_byte;

	if (!str)
		str = ft_calloc(1, 1);
	aux = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!aux)
		return (NULL);
	n_byte = 1;
	while (!ft_strchr(str, '\n') && n_byte != 0)
	{
		n_byte = read(fd, aux, BUFFER_SIZE);
		if (n_byte == -1)
		{
			free(aux);
			free(str);
			return (NULL);
		}
		aux[n_byte] = '\0';
		str = ft_strjoin(str, aux);
	}
	free(aux);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str = NULL;
	char		*sentence;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = gnl_get_content(fd, str);
	if (!str)
		return (NULL);
	sentence = gnl_sentence(str);
	str = gnl_init_sent(str);
	return (sentence);
}
